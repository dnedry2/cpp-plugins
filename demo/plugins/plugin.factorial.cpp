#include <iostream>
#include "plugin.h"

class Factorial : public Plugin {
public:
    double Process(double in) {
        return factorial(in, 1);
    }
    ~Factorial() { }

private:
    double factorial(int n, double v) {
        return n > 1 ? factorial(n - 1, v * n) : v;
    }
};

Plugin* NewInstance() {
    return new Factorial();
}
void Destroy(Plugin* in) {
    delete in;
}

extern "C" PluginInterface Interface() {
    PluginInterface pi = {"Factorial Processor", &NewInstance, &Destroy};
    return pi;
}