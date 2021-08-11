# Even if you don't know a bit about Makefiles, this is too easy to understand

# Basics:
# A: B C                ---> A (TARGET) depends on B and C (PREREQUISITES)
# [TAB]some commands    ---> this should be executed to update A (from B and C)

# PHONY Targets are not meant to be files. They aren't checked or updated.
# PHONY Targets are rules to be executed every time they are called

.PHONY: all clean



# Now, all is the DEFAULT. If you call 'make', it calls for 'make all':

all:plugin-test libplugin-1.so



# If you call 'make clean', you mean this:

clean:
	rm -f *.o *.~ libplugin-1.so plugin-test



# This is a generic rule to every *.o file depending on some *.cpp file
# of the same name. $^ means all of the PREREQUISITES

.cpp.o:
	g++ -c -fPIC $^



# This are using the generic rule above, see? plugin.o from plugin.cpp

plugin.o:plugin.cpp
plugin-test.o:plugin-test.cpp
plugin-content.o:plugin-content.cpp



# Now the binaries. $@ is the TARGET.

plugin-test: plugin.o plugin-test.o
	g++ -o $@ $^ -ldl

libplugin-1.so: plugin-content.o
	g++ -o $@ -shared -fPIC $^

