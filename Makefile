CXX=g++
CXXFLAGS=-O2 -Wall
OBJ=main.o
TARGET=app

.o:.cpp
	$(CXX) $(CXXFLAGS) -c $<

all: $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
