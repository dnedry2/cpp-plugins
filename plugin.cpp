#include <vector>
#include <string>
#include <filesystem>
#include <iostream>

#define PLUGIN_CLIENT
#include "plugin.h"

using namespace std;

#ifdef __unix
    #include <dlfcn.h>
#endif

void DestroyInterface(PluginInterface* interface) {
#ifdef __unix
    dlclose(interface->_handle);
#endif
}

PluginInterface LoadPlugin(std::string path) {
    using namespace std;
    typedef PluginInterface (*Interface)();
    Interface plug = nullptr;

#ifdef __unix
    void* handle = dlopen(path.c_str(), RTLD_LAZY);

    if (!handle) {
        cerr << "Cannot open library: " << dlerror() << endl;
        throw("Failed to load! (IO)");
    }

    dlerror();
    plug = (Interface)dlsym(handle, "Interface");

    const char *dlsym_error = dlerror();
    if (dlsym_error) {
        dlclose(handle);
        cerr << "Cannot load symbols: " << dlsym_error << endl;
        throw("Failed to load!");
    }
#endif

    PluginInterface out = plug();
    out._handle = handle;

    return out;
}

std::vector<PluginInterface> LoadPlugins(std::string dir) {
    vector<PluginInterface> out = vector<PluginInterface>();

    for (const auto& file : std::filesystem::directory_iterator(dir)) {
        try {
            out.push_back(LoadPlugin(file.path()));
        } catch (...) { }
    }

    return out;
}