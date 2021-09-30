cc=g++

.PHONY: build,plugin

all: build plugin

build:
	$(cc) -I ../ source.cpp ../plugin.cpp -o demo -std=c++17 -ldl
	mv demo bin/

plugin:
	$(cc) -shared -fPIC -I ../ plugins/plugin.factorial.cpp -o factorial.so
	$(cc) -shared -fPIC -I ../ plugins/plugin.fibonacci.cpp -o fibonacci.so
	mv *.so bin/plugins/