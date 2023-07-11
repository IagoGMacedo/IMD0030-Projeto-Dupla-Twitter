#Makefile
# Variáveis
CC := g++
#CFLAGS := -Wall -Wextra -std=c++11 -ansi -pedantic
SRC_DIR := src
INCLUDE_DIR := include
BIN_DIR := bin

# Obter todos os arquivos .cpp da pasta src
SOURCES := $(wildcard $(SRC_DIR)/*.cpp)

# Obter o nome base de cada arquivo .cpp
BASENAMES := $(notdir $(SOURCES))
BASENAMES := $(BASENAMES:.cpp=)

# Gerar nomes dos arquivos de objeto correspondentes
OBJECTS := $(addsuffix .o, $(BASENAMES))

# Caminho para os arquivos de cabeçalho
INCLUDE_FLAGS := -I$(INCLUDE_DIR)

# Nome do arquivo binário resultante
TARGET := $(BIN_DIR)/programa

# Regra de compilação principal
all: $(TARGET)

# Regra de compilação para cada arquivo objeto
$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c $< -o $@

# Regra de ligação
$(TARGET): $(addprefix $(BIN_DIR)/, $(OBJECTS))
	$(CC) $(CFLAGS) $^ -o $@

run:
	./$(BIN_DIR)/programa

# Limpar arquivos objeto e binário
clean:
	rm -f $(BIN_DIR)/*.o $(TARGET)

.PHONY: all clean
