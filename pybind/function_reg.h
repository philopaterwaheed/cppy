#pragma once
#include <pybind11/pybind11.h>
#include <vector>
#include <string>
#include <functional>

namespace py = pybind11;

struct FunctionEntry {
    std::string name;
    std::function<void(py::module_&)> bind_function;
};

// Global registry for detected functions
inline std::vector<FunctionEntry>& get_function_registry() {
    static std::vector<FunctionEntry> registry;
    return registry;
}

// Macro to register a function dynamically
#define REGISTER_FUNCTION(name, func) \
    namespace { \
        struct Register_##name { \
            Register_##name() { \
                get_function_registry().push_back({#name, [](py::module_& m) { \
                    m.def(#name, func); \
                }}); \
            } \
        }; \
        static Register_##name register_##name; \
    }

