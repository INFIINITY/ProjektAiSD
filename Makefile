CXX=g++
CXXFLAGS=-O2 -Wall -fopenmp -fPIC
LDFLAGS=-shared
TARGET=library.dll

all: $(TARGET)

$(TARGET): library.cpp library.h
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $(TARGET) library.cpp

clean:
	rm -f $(TARGET)

.PHONY: all clean
