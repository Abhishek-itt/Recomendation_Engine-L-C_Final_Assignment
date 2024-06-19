# Compiler
CXX = g++

# Directories
SRC_DIR = src
INC_DIR = inc
TEST_DIR = Test

# Source files
SRC_FILES = $(wildcard $(SRC_DIR)/**/*.cpp) $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(SRC_DIR)/**/**/*.cpp) $(wildcard $(SRC_DIR)/**/**/**/*.cpp) $(wildcard Common/src/*.cpp) $(wildcard Common/src/**/*.cpp)
TEST_FILES = $(wildcard $(TEST_DIR)/*.cpp)

# Object files
OBJ_FILES = $(SRC_FILES:.cpp=.o)
TEST_OBJ_FILES = $(TEST_FILES:.cpp=.o)

# Include directories
INC_FLAGS = -I$(INC_DIR) -I$(INC_DIR)/Application -I$(INC_DIR)/Business -I$(INC_DIR)/DataAccess -I$(INC_DIR)/DataAccess/Database -I$(INC_DIR)/DatatAccess/Database/MySql -I$(INC_DIR)/Presentation -ICommon/inc

# Libraries
LIBS = -lmysqlcppconn

# Output files
SERVER_OUTPUT = $(TEST_DIR)/server

# Flags
CXXFLAGS = -std=c++17 -Wall

all: $(SERVER_OUTPUT)

# Compile server
$(SERVER_OUTPUT): $(SRC_FILES)
	$(CXX) $(CXXFLAGS) $(INC_FLAGS) -o $@ $^ $(LIBS)

# Pattern rule for compiling source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INC_FLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(SRC_DIR)/**/*.o $(SRC_DIR)/*.o $(SERVER_OUTPUT)

.PHONY: all clean
