# Compiler
CXX = g++

# Directories
SRC_DIR = src
INC_DIR = inc
APP_DIR = App
TEST_DIR = Test

# Source files
SRC_FILES = $(wildcard $(SRC_DIR)/**/*.cpp) $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(SRC_DIR)/*/*/*.cpp) $(wildcard $(SRC_DIR)/*/*/*/*.cpp) $(wildcard Common/src/*.cpp) $(wildcard Common/src/**/*.cpp)
TEST_FILES = $(wildcard $(TEST_DIR)/*.cpp)

# Object files
OBJ_FILES = $(SRC_FILES:.cpp=.o)
TEST_OBJ_FILES = $(TEST_FILES:.cpp=.o)

# Include directories
INC_FLAGS = -I$(INC_DIR) -I$(INC_DIR)/Controller -I$(INC_DIR)/Model -I$(INC_DIR)/View -ICommon/inc -ICommon/inc/DTO -I$(INC_DIR)

# Libraries
LIBS = -lmysqlcppconn

# Output files
APP_OUTPUT = $(APP_DIR)/main

# Flags
CXXFLAGS = -std=c++17 -Wall

all: $(APP_OUTPUT) 

# Compile main application
$(APP_OUTPUT): $(APP_DIR)/main.cpp $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) $(INC_FLAGS) -o $@ $^ $(LIBS)

# Pattern rule for compiling source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INC_FLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(SRC_DIR)/Controller/*.o $(SRC_DIR)/Model/*.o $(SRC_DIR)/View/*.o $(TEST_DIR)/*.o $(APP_OUTPUT) $(TEST_OUTPUT)

.PHONY: all clean
