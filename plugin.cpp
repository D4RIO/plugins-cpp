#include "plugin.hpp"

/** ***************************************************************************
 * @param
 * @return
 * @see
 ** ***************************************************************************/
void Plugin::print(void)
{
    std::cout << "MESSAGE: " << std::endl;
}

/** ***************************************************************************
 * @param
 * @return
 * @see
 ** ***************************************************************************/
std::shared_ptr< Plugin > PluginLoader::get(const std::string& s)
{
    auto r=std::make_shared< Plugin >();
    r->msg=s;
    return r;
}

