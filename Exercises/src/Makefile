CXX = g++
CXXFLAGS = -ggdb

all: build test03


build: main.cpp gf_p.cpp
	$(CXX) $(CXXFLAGS) main.cpp gf_p.cpp -o GFTool

test03: testmain03.cpp gf_p.cpp
	$(CXX) $(CXXFLAGS) testmain03.cpp gf_p.cpp -o Test03

