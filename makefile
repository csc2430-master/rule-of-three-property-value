# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -g -std=c++20 -Wall

# Directories
DIR_A = v1
DIR_B = v2
DIR_C = v3
DIR_D = v4

# Source files
SRC_FILES = main.cpp property.cpp

# Targets
all:
	@echo "Please provide a target: a, b, c, or d"

a:	$(DIR_A)/main.o $(DIR_A)/property.o
	$(CXX) $(CXXFLAGS) -o a $(DIR_A)/main.o $(DIR_A)/property.o

b:	$(DIR_B)/main.o $(DIR_B)/property.o
	$(CXX) $(CXXFLAGS) -o b $(DIR_B)/main.o $(DIR_B)/property.o

c:	$(DIR_C)/main.o $(DIR_C)/property.o
	$(CXX) $(CXXFLAGS) -o c $(DIR_C)/main.o $(DIR_C)/property.o

d:	$(DIR_D)/main.o $(DIR_D)/property.o
	$(CXX) $(CXXFLAGS) -o d $(DIR_D)/main.o $(DIR_D)/property.o

# Pattern rule for compiling .cpp files to .o files
$(DIR_A)/%.o:	$(DIR_A)/%.cpp $(DIR_A)/property.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(DIR_B)/%.o:	$(DIR_B)/%.cpp $(DIR_B)/property.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(DIR_C)/%.o:	$(DIR_C)/%.cpp $(DIR_C)/property.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(DIR_D)/%.o:	$(DIR_D)/%.cpp $(DIR_D)/property.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(DIR_A)/*.o $(DIR_B)/*.o $(DIR_C)/*.o $(DIR_D)/*.o a b c d
