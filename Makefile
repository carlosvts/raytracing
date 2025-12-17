# O compilador a ser usado
CXX = g++

# Flags do compilador:
# -Wall -Wextra: Habilita a maioria dos avisos (warnings) importantes
# -std=c++17: Define o padrão da linguagem para C++17
# -g: Adiciona símbolos de debug (útil se você usar gdb depois)
CXXFLAGS = -Wall -Wextra -std=c++17 -g

# Bibliotecas do SFML necessárias para linkar
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

# Seus arquivos fonte (.cpp)
SRC = main.cpp renderer.cpp raytracing.cpp

# Transforma a lista de .cpp em .o (objetos) automaticamente
OBJ = $(SRC:.cpp=.o)

# Nome do executável final
TARGET = raytracing

# Regra padrão (o que acontece quando você digita apenas 'make')
all: $(TARGET)

# Linkagem: Junta todos os objetos para criar o executável
$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET) $(LDFLAGS)

# Compilação: Transforma cada .cpp em .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regra para limpar arquivos gerados (digite 'make clean')
clean:
	rm -f $(OBJ) $(TARGET)

# Regra de conveniência para rodar o programa (digite 'make run')
run: $(TARGET)
	./$(TARGET)