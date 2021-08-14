#include "plugin.hpp"
#include <iostream> // std::cout

// 'using namespace' is bad, usually, but this source
// is tiny and not to be used by any other sources.

using namespace d;


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
 * PluginFactory factory and overwrite the behaviour of it's
 * methods
 */
class SpecificFactory : public PluginFactory
{
    std::shared_ptr< Plugin > get(void)
        {
            auto r=std::make_shared< SpecificPlugin > ();
            return r;
        }
};

/** ***************************************************************************
 * @param
 * @return
 * @see
 ** ***************************************************************************/
void SpecificPlugin::print(void)
{
    std::cout << "SPECIAL MESSAGE" << std::endl;
}

/**
 * Forget everything about GLOBALS being demons.
 * Static globals aren't mangled by the compiler.
 * The only rule is that every plugin defines 'pluginFactory',
 * an object of a class inherited from PluginFactory. This is the
 * actual factory.
 */
SpecificFactory pluginFactory;

