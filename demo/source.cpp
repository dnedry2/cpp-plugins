#include <vector>
#include <iostream>

#define PLUGIN_CLIENT
#include "plugin.h"

using std::cout;
using std::cin;
using std::endl;
using std::vector;

vector<PluginInterface> plugins;

int main() {
    plugins = LoadPlugins("plugins");
    cout << plugins.size() << " plugins loaded." << endl;

    int input = 0;
    cout << "Enter a number: ";
    cin >> input;
    cout << "\nRunning plugins..." << endl << endl;

    for (auto p : plugins) {
        Plugin* plug = p.Instance();
        cout << "Name: " << p.Name << endl << "Output: " << plug->Process(input) << endl << endl;
    }
}