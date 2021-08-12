#include "plugin.hpp"

/**
 * When you want to build a new plugin, you inherit the
 * plugin from "Plugin"
 */
class SpecificPlugin : public Plugin
{
    void print(void);
};

/**
 * To set the factory to work, you need to inherit from the
 * PluginLoader factory and overwrite the behaviour of it's
 * methods
 */
class SpecificLoader : public PluginLoader
{
    std::shared_ptr< Plugin > get(const std::string& s)
        {
            auto r=std::make_shared< SpecificPlugin > ();
            r->msg=s;
            return r;
        }
};

/**
 * Forget everything about GLOBALS being demons.
 * Static globals aren't mangled by the compiler.
 * The only rule is that every plugin defines 'pluginLoader',
 * an object of a class inherited from PluginLoader. This is the
 * actual factory.
 */
SpecificLoader pluginLoader;

/** ***************************************************************************
 * @param
 * @return
 * @see
 ** ***************************************************************************/
void SpecificPlugin::print(void)
{
    std::cout << "SPECIAL MESSAGE: " << msg << "\n";
}
