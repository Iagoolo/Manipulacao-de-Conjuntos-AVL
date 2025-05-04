CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2 -Iinclude
LDFLAGS =
OBJDIR = obj

# Fontes principais
SRC_FILES := $(wildcard src/**/*.cpp)
SRC_OBJECTS := $(patsubst %.cpp,$(OBJDIR)/%.o,$(SRC_FILES))

# Executável principal
MAIN_EXEC = programa
MAIN_SRC = src/main/main.cpp
MAIN_OBJ = $(OBJDIR)/src/main/main.o

# Testes
TEST_EXEC = test_conjunto
TEST_SRC = test/test_set.cpp
TEST_OBJ = $(OBJDIR)/test/test_set.o

all: run

run: $(MAIN_EXEC)
	./$(MAIN_EXEC)

test: $(TEST_EXEC)
	./$(TEST_EXEC)

# Compila o programa principal
$(MAIN_EXEC): $(filter-out $(MAIN_OBJ),$(SRC_OBJECTS)) $(MAIN_SRC)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Compila os testes
$(TEST_EXEC): $(filter-out $(MAIN_OBJ),$(SRC_OBJECTS)) $(TEST_SRC)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Regras para criar objetos
$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR) $(MAIN_EXEC) $(TEST_EXEC)

.PHONY: all run test clean
