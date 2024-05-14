# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iincludes
LDFLAGS = -lSDL2 -lSDL2_ttf

# Directories
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
DOC_DIR = doc

# Files
TARGET = $(BIN_DIR)/CasseBrique
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))
DOXYFILE = Doxyfile

# Targets
all: $(TARGET)

$(TARGET): $(OBJS)
	mkdir -p $(BIN_DIR)
	$(CXX) $(OBJS) -o $(TARGET) $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Documentation target
doc: $(DOXYFILE)
	mkdir -p $(DOC_DIR)
	doxygen $(DOXYFILE)

# Clean target
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR) $(DOC_DIR)

# Phony targets
.PHONY: clean run doc

run: $(TARGET)
	./$(TARGET)
