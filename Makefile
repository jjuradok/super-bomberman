# Replace this with the path you get from `brew info sfml`
SFML_PATH = /opt/homebrew/Cellar/sfml/2.6.1

# Source files
cppFileNames := $(shell find ./src -type f -name "*.cpp")
cppFileNames += $(shell find ./include -type f -name "*.cpp")

all: compile

compile:	
	mkdir -p bin
	g++ -std=c++11 $(cppFileNames) -I$(SFML_PATH)/include -I./include -o bin/app -L$(SFML_PATH)/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network

clean:
	rm -rf bin
