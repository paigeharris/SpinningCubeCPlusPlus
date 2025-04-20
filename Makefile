CXX = g++
CXXFLAGS = -Iinclude/SDL2 -Wall
LDFLAGS = -Llib -lmingw32 -lSDL2main -lSDL2 -lopengl32 -lglew32 -lglu32
SRC = src/main.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = bin/sdl2game.exe

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

clean:
	rm -f $(OBJ) $(TARGET)
