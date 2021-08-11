#include <iostream>
#include <memory>

class Servicio
{
public:
    std::string msg;
    virtual void print(void);
};

class Plugin
{
public:
    std::shared_ptr<Servicio> gimi(const std::string& s);
};
