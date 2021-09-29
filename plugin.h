#ifndef _PLUGIN_H_
#define _PLUGIN_H_

//*********************** Replace with plugin interface ***********************

class Plugin {
public:
    virtual double Process(double in) = 0;
    virtual ~Plugin() { };
};

//*****************************************************************************

extern "C" typedef struct {
    const char* Name;
    Plugin* (*Instance)();
    void    (*Destroy)(Plugin*);

    void*   _handle;
} PluginInterface;

extern "C" PluginInterface Interface();

#ifdef PLUGIN_CLIENT
#include <vector>
#include <string>

void DestroyInterface(PluginInterface* interface);
PluginInterface LoadPlugin(std::string path);
std::vector<PluginInterface> LoadPlugins(std::string dir);
#endif

#endif