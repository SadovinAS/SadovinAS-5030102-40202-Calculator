#include "PluginLoader.h"

void PluginLoader::LoadAll() {
    std::filesystem::path dir = "plugins";
    
    if (!std::filesystem::exists(dir))
        return;
    
    for (auto& e : std::filesystem::directory_iterator(dir)) {
        if (e.path().extension() != ".dll")
            continue;

        HMODULE h = LoadLibraryA(e.path().string().c_str());
        if (!h)
            throw std::exception(("Cannot open plugin '" + e.path().string() + "'.").c_str());

        auto fn = (LoadFunc)GetProcAddress(h, "LoadFunc");
        auto on = (LoadOper)GetProcAddress(h, "LoadOper");
        if (!fn && !on)
            throw std::exception(("Cannot find a Plugin Load Function in plugin '" + e.path().string() + "'.").c_str());

        if (fn)
            fn(Function::List);
        if (on)
            on(Operation::List);

        Libs.push_back(h);
    }
}
PluginLoader::~PluginLoader() {
    Function::List.clear();
    Operation::List.clear();
    for (auto h : Libs)
        FreeLibrary(h);
}