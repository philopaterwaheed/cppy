#include "function_reg.h"

int add(int a, int b) {
    return a + b;
}

double multiply(double x, double y) {
    return x * y;
}

REGISTER_FUNCTION(add, add);
REGISTER_FUNCTION(multiply, multiply);

PYBIND11_MODULE(module_name, m) {
    m.doc() = "Dynamically generated module";

    // Register all functions automatically
    for (const auto& entry : get_function_registry()) {
        entry.bind_function(m);
    }
}

