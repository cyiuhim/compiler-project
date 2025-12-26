# Makefile for lexer unit tests with Google Test

CXX = g++
CXXFLAGS = -std=c++20 -Wall -g -fPIC
GTEST_FLAGS = 

# Directories
SRC_DIR = ../src
LEXER_DIR = $(SRC_DIR)/lexer
TEST_DIR = .

# Source files from lexer
LEXER_SOURCES = $(LEXER_DIR)/dfa.cpp \
                $(LEXER_DIR)/state.cpp \
                $(LEXER_DIR)/state_list.cpp \
                $(LEXER_DIR)/trie_node.cpp

LEXER_OBJECTS = $(LEXER_SOURCES:.cpp=.o)

# Test file
TEST_SOURCES = $(TEST_DIR)/lexer_test.cpp
TEST_OBJECTS = $(TEST_SOURCES:.cpp=.o)

# Output
TEST_EXECUTABLE = lexer_test

# Google Test library
GTEST_LIB = -lgtest -lgtest_main -pthread

# Default target
all: $(TEST_EXECUTABLE)

# Build the test executable
$(TEST_EXECUTABLE): $(LEXER_OBJECTS) $(TEST_OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(GTEST_LIB)

# Build object files from lexer
$(LEXER_DIR)/%.o: $(LEXER_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Build test object file
$(TEST_DIR)/%.o: $(TEST_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(GTEST_FLAGS) -c $< -o $@

# Run tests
run: $(TEST_EXECUTABLE)
	./$(TEST_EXECUTABLE)

# Clean up
clean:
	rm -f $(LEXER_OBJECTS) $(TEST_OBJECTS) $(TEST_EXECUTABLE)
	rm -f ../src/lexer/*.d
	rm -f *.o

.PHONY: all run clean
