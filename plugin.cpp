#include "plugin.hpp"

// forward declaration + static global object (loading purposes)
class Plugin;
Plugin pluginLoader;

/** ***************************************************************************
 * @param
 * @return
 * @see
 ** ***************************************************************************/
void Servicio::print(void)
{
    std::cout << msg << "\n";	
}

/** ***************************************************************************
 * @param
 * @return
 * @see
 ** ***************************************************************************/
std::shared_ptr<Servicio> Plugin::gimi(const std::string& s)
{
    auto r=std::make_shared<Servicio>();
    r->msg=s;
    return r;
}

