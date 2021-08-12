#include "plugin.hpp"
#include <dlfcn.h>

/** ***************************************************************************
 * @param
 * @return
 * @see
 ** ***************************************************************************/
int main(void)
{
    auto lib = dlopen ( "./libplugin-1.so", RTLD_LAZY );

    if (!lib) {
        std::cout << dlerror() << std::endl;
        return 1;
    }
    
    PluginLoader *loader = (PluginLoader*) dlsym ( lib, "pluginLoader" );

    if (!loader) {
        std::cout << dlerror() << std::endl;
        return 1;
    }

    std::shared_ptr< Plugin > plugin = loader->get( "A message" );

    plugin->print();

    dlclose (lib);
    return 0;
}
