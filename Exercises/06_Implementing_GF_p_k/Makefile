CXX = g++
CXXFLAGS = -ggdb

all: build test util


build: main.cpp gf_p_k.cpp
	$(CXX) $(CXXFLAGS) main.cpp gf_p_k.cpp -o GFTool

test: testmain.cpp gf_p_k.cpp
	$(CXX) $(CXXFLAGS) testmain.cpp gf_p_k.cpp -o GFTest

util: utilmain.cpp gf_p_k.cpp
	$(CXX) $(CXXFLAGS) utilmain.cpp gf_p_k.cpp -o GFUtil
