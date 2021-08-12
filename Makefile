# Even if you don't know a bit about Makefiles, this is too easy to understand

# Basics:
# A: B C                ---> A (TARGET) depends on B and C (PREREQUISITES)
# [TAB]some commands    ---> this should be executed to update A (from B and C)

# PHONY Targets are not meant to be files. They aren't checked or updated.
# PHONY Targets are rules to be executed every time they are called

.PHONY: all clean



# Now, all is the DEFAULT. If you call 'make', it calls for 'make all':

all:example-main libexample-1.so libplugin-cpp.so



# If you call 'make clean', you mean this:

clean:
	rm -f *.o *.~ libexample-1.so example-main libplugin-cpp.so



# This is a generic rule to every *.o file depending on some *.cpp file
# of the same name. $^ means all of the PREREQUISITES

.cpp.o:
	g++ -c -fPIC $^



# This are using the generic rule above, see? plugin.o from plugin.cpp

plugin.o:plugin.cpp
example-main.o:example-main.cpp
plugin-example.o:plugin-example.cpp




# Now the binaries. $@ is the TARGET. $< means the first PREREQUISITE.

example-main: example-main.o libplugin-cpp.so
	g++ -o $@ $< -ldl -rdynamic -L. -lplugin-cpp




# This is the Plugin and PluginLoader class library. This will let you
# get your own plugins loaded at runtime. If you don't want to install it
# (like for testing purposes), you can define LD_LIBRARY_PATH to ./

libplugin-cpp.so: plugin.o
	g++ -shared -fPIC $^ -o $@




# And finally this. Here there is a trick about using g++ to access the linker.
# If you put -lplugin-cpp BEFORE the $<, the linker might not see the symbols
# and just ignore libplugin-cpp.so entirely. To check for a wrong linkage,
# you may use 'ldd -d libexample-1.so'. If there are unresolved symbols, then
# the linkage has just failed. As a good rule, -l fits nicely AT THE END.

libexample-1.so: plugin-example.o libplugin-cpp.so
	g++ -o $@ -fPIC $< -shared -rdynamic -lplugin-cpp

