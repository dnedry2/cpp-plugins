#include <iostream>
#include "plugin.h"

class Fibonacci : public Plugin {
public:
    double Process(double in) {
        return fibonacci(in);
    }
    ~Fibonacci() { }

private:
    double fibonacci(double n) {
        return n > 1 ? fibonacci(n - 1) + fibonacci(n - 2) : n;
    }
};

Plugin* NewInstance() {
    return new Fibonacci();
}
void Destroy(Plugin* in) {
    delete in;
}

extern "C" PluginInterface Interface() {
    PluginInterface pi = {"Fibonacci Processor", &NewInstance, &Destroy};
    return pi;
}