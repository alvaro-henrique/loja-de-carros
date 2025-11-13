# Nome do executável final
TARGET = concessionaria

# Compilador
CXX = g++

# Opções de compilação
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic -Iheader

# Diretórios
SRC_DIR = src
OBJ_DIR = obj

# Lista de todos os arquivos .cpp e correspondentes .o
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# Regra principal (gera o executável)
$(TARGET): $(OBJS)
	@echo "🔗 Ligando tudo em $(TARGET)..."
	$(CXX) $(OBJS) -o $(TARGET)
	@echo "✅ Compilação concluída com sucesso!"

# Compilação individual de cada .cpp
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@echo "🔧 Compilando $< ..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Cria a pasta obj se não existir
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Executa o programa após compilar
run: $(TARGET)
	@echo "🚀 Executando $(TARGET)..."
	@./$(TARGET)

# Limpeza (remove objetos e binário)
clean:
	rm -rf $(OBJ_DIR) $(TARGET)
	@echo "🧹 Tudo limpo!"
