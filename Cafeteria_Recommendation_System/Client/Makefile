# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Iinc
LDFLAGS = -lmysqlcppconn

# Directories
SRC_DIR = src
INC_DIR = inc
OBJ_DIR = obj
APP_DIR = app

# Source files
SRC_FILES = \
	$(SRC_DIR)/Controller/AdminController.cpp \
	$(SRC_DIR)/Controller/SocketController.cpp \
	$(SRC_DIR)/Controller/UserController.cpp \
	$(SRC_DIR)/View/AdminView.cpp \
	$(SRC_DIR)/Utils/Serializer.cpp \
	$(SRC_DIR)/main.cpp

OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC_FILES))

# Target executable
TARGET = client

# Default target
all: $(TARGET)

# Link the target executable
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

# Compile source files to object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp 
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

# Phony targets
.PHONY: all clean