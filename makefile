# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g
COVERAGE_FLAGS = --coverage

# Target executables
TARGET = petspace_demo
TEST_TARGET = test_petspace

# Source files
# COMMON_SOURCES = ChatRoom.cpp \
#           CtrlCat.cpp \
#           Dogorithm.cpp \
#           Users.cpp \
#           ConcreteUsers.cpp \
#           Command.cpp \
#           SendMessageCommand.cpp \
#           SaveMessageCommand.cpp \
#           Iterator.cpp \
#           MessageHistoryIterator.cpp \
#           UserIterator.cpp \
#           Aggregate.cpp
# COMMON_SOURCES = ChatRoom.cpp \
#           CtrlCat.cpp \
#           Dogorithm.cpp \
#           Users.cpp \
#           Command.cpp \
#           SendMessageCommand.cpp \
#           SaveMessageCommand.cpp

COMMON_SOURCES = CtrlCat.cpp \
          Dogorithm.cpp \
          Users.cpp \
          SendMessageCommand.cpp \
          SaveMessageCommand.cpp \
          BasicUser.cpp \
          AdminUser.cpp \
          ModeratorUser.cpp \
          UserFactory.cpp \
          BasicUserFactory.cpp \
          AdminUserFactory.cpp \
          ModeratorUserFactory.cpp \
          UserIterator.cpp \
          MessageHistoryIterator.cpp \
          ChatRoomIterator.cpp \
          IteratorCreator.cpp

MAIN_SOURCE = DemoMain.cpp
TEST_MAIN_SOURCE = TestingMain.cpp

# Object files
COMMON_OBJECTS = $(COMMON_SOURCES:.cpp=.o)
MAIN_OBJECT = $(MAIN_SOURCE:.cpp=.o)
TEST_MAIN_OBJECT = $(TEST_MAIN_SOURCE:.cpp=.o)

# Default target
all: $(TARGET) $(TEST_TARGET)

# Build main application
$(TARGET): $(COMMON_OBJECTS) $(MAIN_OBJECT)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(COMMON_OBJECTS) $(MAIN_OBJECT)

# Build test application
$(TEST_TARGET): $(COMMON_OBJECTS) $(TEST_MAIN_OBJECT)
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $(COMMON_OBJECTS) $(TEST_MAIN_OBJECT)

# Compile source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run test program (as required by FitchFork)
run: $(TEST_TARGET)
	./$(TEST_TARGET)

# Run demo program
demo: $(TARGET)
	./$(TARGET)

# Run memory check with Valgrind
valgrind: $(TEST_TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TEST_TARGET)

# Coverage analysis (as required by FitchFork)
coverage: clean
	$(CXX) $(CXXFLAGS) $(COVERAGE_FLAGS) -c $(COMMON_SOURCES) $(TEST_MAIN_SOURCE)
	$(CXX) $(CXXFLAGS) $(COVERAGE_FLAGS) -o $(TEST_TARGET) *.o
	./$(TEST_TARGET)
	gcov *.cpp
	@echo ""
	@echo "=== Coverage Summary ==="
	@grep "Lines executed" *.cpp.gcov 2>/dev/null | head -10 || echo "Coverage files generated. Use 'ls *.gcov' to see all files."
	@echo ""
	@echo "To view detailed coverage for a specific file, use: less <filename>.cpp.gcov"

# Clean up
clean:
	rm -f *.o *.gcda *.gcno *.gcov $(TARGET) $(TEST_TARGET)

.PHONY: all run demo coverage clean valgrind