
ProjDir =$(shell pwd)
OutLib  =$(ProjDir)/lib
BuildTmpDir=$(ProjDir)/build

INCLUDE=-I/usr/include \
		-I/usr/include/python2.7 \
		-I$(ProjDir)/include \

LDFLAGS=-L/usr/lib/x86_64-linux-gnu/ \
		-lopencv_core -lopencv_highgui -lopencv_imgproc -lboost_python

sourcefiles=$(wildcard $(ProjDir)/src/*.cpp)
objects=$(addprefix $(BuildTmpDir)/,$(subst .cpp,.o,$(notdir $(sourcefiles))))

CXXFLAGS=-std=c++11 -shared -fPIC

$(shell mkdir -p $(OutLib) $(BuildTmpDir))

.PHONY:all

all:$(OutLib)/libvtp.so toPython
	rm -rf $(BuildTmpDir)

toPython: $(OutLib)/libvtp.so
	cp $< $(ProjDir)/python

$(OutLib)/libvtp.so:$(objects)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LDFLAGS)

$(BuildTmpDir)/%.o:$(ProjDir)/src/%.cpp $(ProjDir)/src/%.cpp.d
	$(CXX) -o $@ -c $< $(CXXFLAGS) $(INCLUDE)

$(ProjDir)/src/%.cpp.d:$(ProjDir)/src/%.cpp
	$(CXX) $< -MM $(CXXFLAGS) $(INCLUDE) > $@

clean:
	rm -rf $(OutLib)

