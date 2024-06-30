# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Iinc
LDFLAGS = -lmysqlcppconn

# Directories
SRC_DIR = src
INC_DIR = inc
OBJ_DIR = obj

# Source files
SRC_FILES = \
	$(SRC_DIR)/Controller/CRUDController.cpp \
	$(SRC_DIR)/Controller/MealMenuController.cpp \
	$(SRC_DIR)/Controller/MealMenuResponseController.cpp \
	$(SRC_DIR)/Controller/RolloutController.cpp \
	$(SRC_DIR)/Controller/UserController.cpp \
	$(SRC_DIR)/Controller/VotingController.cpp \
	$(SRC_DIR)/DBAccessor/FoodFeedbackDAO.cpp \
	$(SRC_DIR)/DBAccessor/FoodItemDAO.cpp \
	$(SRC_DIR)/DBAccessor/MealMenuDAO.cpp \
	$(SRC_DIR)/DBAccessor/MealMenuResponseDAO.cpp \
	$(SRC_DIR)/DBAccessor/MySQL/MySqlDBAccess.cpp \
	$(SRC_DIR)/DBAccessor/RolloutMenuDAO.cpp \
	$(SRC_DIR)/DBAccessor/RolloutVotingDAO.cpp \
	$(SRC_DIR)/DBAccessor/UsersDAO.cpp \
	$(SRC_DIR)/RequestHandler/ClientRequestHandler.cpp \
	$(SRC_DIR)/RequestHandler/SocketServer.cpp \
	$(SRC_DIR)/Utils/Serializar.cpp \
	$(SRC_DIR)/main.cpp

OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC_FILES))

# Target executable
TARGET = server

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
