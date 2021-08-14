#ifndef _PLUGIN_HPP_
#define _PLUGIN_HPP_

#include <memory> // std::shared_ptr is a must

namespace d
{

    class Plugin
    {
    public:
        virtual void print( void );
    };

    class PluginFactory
    {
    public:
        virtual std::shared_ptr< Plugin > get( void );
    };

    extern std::shared_ptr< Plugin > plugin ( const std::string& s );
    extern std::shared_ptr< Plugin > plugin ( const char *s );

}

#endif
