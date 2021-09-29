.PHONY: build,plugin

all: build plugin

build:
	clang++ -I ../ source.cpp ../plugin.cpp -o demo -arch arm64 -std=c++17
	mv demo bin/

plugin:
	clang++ -shared -I ../ plugins/plugin.factorial.cpp -o factorial.so -arch arm64
	clang++ -shared -I ../ plugins/plugin.fibonacci.cpp -o fibonacci.so -arch arm64
	mv *.so bin/plugins/