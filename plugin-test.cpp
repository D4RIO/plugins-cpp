#include "plugin.hpp"
#include <dlfcn.h>

/** ***************************************************************************
 * @param
 * @return
 * @see
 ** ***************************************************************************/
int main(void)
{
    auto lib = dlopen ( "libplugin-1.so", 0 );
    Plugin *plugin = (Plugin*) dlsym ( lib, "pluginLoader" );

    std::shared_ptr< Servicio > serviceProvided = plugin->gimi( "A message" );

    serviceProvided->print();
    return 0;
}
