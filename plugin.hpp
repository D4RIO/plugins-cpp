#ifndef _PLUGIN_HPP_
#define _PLUGIN_HPP_

#include <iostream>
#include <memory>

class Plugin
{
public:
    std::string msg;
    virtual void print(void);
};

class PluginLoader
{
public:
    virtual std::shared_ptr< Plugin > get(const std::string& s);
};

#endif
