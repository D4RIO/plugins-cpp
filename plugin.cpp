#include "plugin.hpp"
#include <dlfcn.h>  // dlopen, dlsym, dlclose
#include <iostream> // std::cout

/** ***************************************************************************
 * en: This is a testing, simple function, overwritten in the plugin. If it works
 * then you will see whatever message written by the plugin. If you just see
 * MESSAGE, then it isn't working quite well.
 * es: Esta es una función simple de prueba, sobreescrita en el plugin. Si funciona,
 * entonces se verá el mensaje redefinido por el plugin. Si ves MESSAGE, entonces
 * no está funcionando muy bien.
 ** ***************************************************************************/
void d::Plugin::print(void)
{
    std::cout << "MESSAGE" << std::endl;
}

/** ***************************************************************************
 * en: This is the factory builder. There is an static factory object called
 * pluginFactory inside every plugin (working with this library), and the
 * factory get() build the Plugin objects.
 * es: Este es el constructor de la factoría. Hay un objeto factoría estático
 * llamado pluginFactory en cada plugin que funciona con esta biblioteca, y su
 * get() construye los objetos Plugin.
 * @return Smart shared pointer to a maybe new plugin object.
 * @see d::plugin()
 ** ***************************************************************************/
std::shared_ptr< d::Plugin > d::PluginFactory::get(void)
{
    auto r=std::make_shared< d::Plugin >();
    return r;
}

/** ***************************************************************************
 * en: This function gives compatibility with C++ strings.
 * es: Esta función brinda compatibilidad con strings de C++.
 * @param s Path of the library to open
 * @return Plugin object. A Plugin may implement a Singleton or not.
 ** ***************************************************************************/
std::shared_ptr< d::Plugin > d::plugin(const std::string& s)
{
    return plugin ( s.c_str() );
}

/** ***************************************************************************
 * en: This will open the library, load the factory, and get a Plugin object.
 * es: Abre la biblioteca, carga la factoría, y obtiene un objeto Plugin.
 * @param s Path of the library to open
 * @return Plugin object. A Plugin may implement a Singleton or not.
 ** ***************************************************************************/
std::shared_ptr< d::Plugin > d::plugin(const char *s)
{
    auto lib = dlopen ( s, RTLD_LAZY );

    if (!lib)
        throw std::runtime_error( dlerror() );

    auto factory = (d::PluginFactory*) dlsym ( lib, "pluginFactory" );

    if (!factory)
        throw std::runtime_error( dlerror() );

    auto plugin = factory->get();

    return plugin;
}

