CXX = g++
CXXFLAGS = -ggdb

all: build test


build: main.cpp gf_p.cpp
	$(CXX) $(CXXFLAGS) main.cpp gf_p.cpp -o GFTool

test: testmain.cpp gf_p.cpp
	$(CXX) $(CXXFLAGS) testmain.cpp gf_p.cpp -o GFTest

