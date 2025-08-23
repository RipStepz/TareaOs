
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra


SRC = Main.cpp MakeDir.cpp
HEADERS = definicion.hpp
OBJ = $(SRC:.cpp=.o)
TARGET = programa


all: $(TARGET)


$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^


%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@


run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)
