#include "plugin.hpp"
#include <iostream> // std::cerr

/** ***************************************************************************
 * en: This is a simple main, calling plugin to load a library, and using a
 * function just inmediately after.
 * es: Esta es una main sencilla, que llama a d::plugin para cargar una biblioteca
 * y usa una función de la misma inmediatamente. 
 ** ***************************************************************************/
int main(void)
{
    try
    {
        auto plug =  d::plugin ( "./libexample-1.so" );
        plug->print();   
    }
    catch (std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    catch (...)
    {
        std::cerr << "Unexpected error" << std::endl;
        return 2;
    }
    return 0;
}
