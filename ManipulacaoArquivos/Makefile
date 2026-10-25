# Nome do executável
EXEC = sistema_Library

# Compilador e flags
CXX = g++
CXXFLAGS = -Wall -std=c++11

# Arquivos fonte e objetos
SOURCES = main.cpp Book.cpp Member.cpp Library.cpp
OBJECTS = $(SOURCES:.cpp=.o)

# Regra principal: compilar o executável
all: $(EXEC)

# Como linkar os objetos para criar o executável
$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJECTS)

# Como compilar cada .cpp em .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regra para limpar os arquivos compilados 
clean:
	rm -f $(OBJECTS) $(EXEC)