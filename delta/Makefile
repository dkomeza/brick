TARGET_EXEC := delta
TEST_EXEC := delta_test

BUILD_DIR := ./build
SRC_DIR := ./src
TESTS_DIR := ./tests

SRCS := $(shell find $(SRC_DIR) -name *.cpp -or -name *.c -or -name *.s)
TEST_SRCS := $(shell find $(TESTS_DIR) -name *.cpp -or -name *.c)

OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
TEST_OBJS := $(TEST_SRCS:%=$(BUILD_DIR)/%.o)

DEPS := $(OBJS:.o=.d)
TEST_DEPS := $(TEST_OBJS:.o=.d)

INC_DIRS := $(shell find $(SRC_DIR) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CFLAGS := $(INC_FLAGS) -Wall -Wextra -std=c2x -O3 -g
CPPFLAGS := $(INC_FLAGS) -MMD -MP -Wall -Wextra -std=c++20 -O3 -g

# Main executable
$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	@mkdir -p $(dir $@)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

# Test executable
$(BUILD_DIR)/$(TEST_EXEC): $(TEST_OBJS) $(filter-out %/main.c.o,$(OBJS))
	@mkdir -p $(dir $@)
	$(CXX) $^ -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.cpp.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(BUILD_DIR)/%.c.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean run test debug

# Clean build artifacts
clean:
	rm -rf $(BUILD_DIR)

# Run the main executable
run: $(BUILD_DIR)/$(TARGET_EXEC)
	@echo "Running $(TARGET_EXEC)..."
	@$(BUILD_DIR)/$(TARGET_EXEC)

# Run tests
test: $(BUILD_DIR)/$(TEST_EXEC)
	@echo "Running tests..."
	@$(BUILD_DIR)/$(TEST_EXEC)

# Debug target with GDB
debug: $(BUILD_DIR)/$(TARGET_EXEC)
	@echo "Debugging $(TARGET_EXEC)..."
	gdb $(BUILD_DIR)/$(TARGET_EXEC)

# Memory check with Valgrind
valgrind: $(BUILD_DIR)/$(TARGET_EXEC)
	@echo "Running Valgrind memory check..."
	valgrind --leak-check=full --show-leak-kinds=all $(BUILD_DIR)/$(TARGET_EXEC)

# Include dependency files
-include $(DEPS) $(TEST_DEPS)