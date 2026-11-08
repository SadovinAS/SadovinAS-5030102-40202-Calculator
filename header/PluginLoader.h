#pragma once
#include <string>
#include <vector>
#include <memory>
#include <windows.h>
#include <stdexcept>
#include <filesystem>
#include "Function.h"
#include "Operation.h"


using LoadFunc = void(*)(std::vector<std::shared_ptr<Function>>&);
using LoadOper = void(*)(std::vector<std::shared_ptr<Operation>>&);

class PluginLoader {
    std::vector<HMODULE> Libs;
public:
    void LoadAll();
    ~PluginLoader();
};