#include "plugin.hpp"

class ServicioEspecial : public Servicio
{
    void print(void);
};

/** ***************************************************************************
 * @param
 * @return
 * @see
 ** ***************************************************************************/
void ServicioEspecial::print(void)
{
    std::cout << msg << "\n";	
}
