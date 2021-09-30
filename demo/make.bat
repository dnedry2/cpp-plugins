@echo off
::Windows build script, requires g++

:main
    g++ -I ../ source.cpp ../plugin.cpp -o demo.exe -std=c++17 -D_WIN64
    move demo.exe bin/

:plugins
    g++ -shared -fPIC -I ../ plugins/plugin.factorial.cpp -o factorial.dll
    g++ -shared -fPIC -I ../ plugins/plugin.fibonacci.cpp -o fibonacci.dll
    move *.dll bin/plugins/