#Makefile for "Laboratorio 05" C++ aplication
#Created by Dionísio Carvalho

# Comandos do sistema operacional
# Linux: rm -rf
# Windows: cmd //C del
RM = rm -rf

# Compilador
CC = g++

# Variaveis para os subdiretorios
BIN_DIR = ./bin
OBJ_DIR = ./build
DOC_DIR = ./doc
INC_DIR = ./include
SRC_DIR = ./src
TST_DIR = ./test

# Opcoes de compilacao
CFLAGS = -Wall -pedantic -ansi -std=c++11 -I $(INC_DIR)

# Garante que os alvos desta lista nao sejam confundidos com arquivos de mesmo nome
.PHONY: all clean distclean doxy

# Define o alvo (target) para a compilacao completa.
# Ao final da compilacao, remove os arquivos objeto.
all: clean lab05 dados teste doxy
debug: CFLAGS += -g -O0
debug: clean lab05 dados teste

# Alvo (target) para a construcao do executavel teste
# Define os arquivos empresa.o, funcionario.o, bancodados.o, funcoes.o, menu.o e teste.o como dependencias
teste: $(OBJ_DIR)/empresa.o $(OBJ_DIR)/funcionario.o $(OBJ_DIR)/bancodados.o $(OBJ_DIR)/funcoes.o $(OBJ_DIR)/menu.o $(OBJ_DIR)/teste.o
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel $@ criado em $(BIN_DIR)] +++"
	@echo "============="

# Alvo (target) para a construcao do executavel dados
# Define os arquivos funcionario.o e dados.o como dependencia
dados: $(OBJ_DIR)/funcionario.o $(OBJ_DIR)/dados.o
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel $@ criado em $(BIN_DIR)] +++"
	@echo "============="

# Alvo (target) para a construcao do objeto dados.o
# Define o arquivo dados.cpp como dependencia.
$(OBJ_DIR)/dados.o: $(SRC_DIR)/dados.cpp
	$(CC) -c $(CFLAGS) -o $@ $<

# Alvo (target) para a construcao do executavel lab05
# Define os arquivos empresa.o, funcionario.o, funcoes.o, menu.o e main.o como dependencias
lab05: $(OBJ_DIR)/empresa.o $(OBJ_DIR)/funcionario.o $(OBJ_DIR)/bancodados.o $(OBJ_DIR)/funcoes.o $(OBJ_DIR)/menu.o $(OBJ_DIR)/main.o
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel $@ criado em $(BIN_DIR)] +++"
	@echo "============="

# Alvo (target) para a construcao do objeto empresa.o
# Define os arquivos empresa.cpp e empresa.h como dependencias.
$(OBJ_DIR)/empresa.o: $(SRC_DIR)/empresa.cpp $(INC_DIR)/empresa.h
	$(CC) -c $(CFLAGS) -o $@ $<

# Alvo (target) para a construcao do objeto funcionario.o
# Define os arquivos funcionario.cpp e funcionario.h como dependencias.
$(OBJ_DIR)/funcionario.o: $(SRC_DIR)/funcionario.cpp $(INC_DIR)/funcionario.h
	$(CC) -c $(CFLAGS) -o $@ $<

# Alvo (target) para a construcao do objeto menu.o
# Define os arquivos menu.cpp e menu.h como dependencias.
$(OBJ_DIR)/menu.o: $(SRC_DIR)/menu.cpp $(INC_DIR)/menu.h
	$(CC) -c $(CFLAGS) -o $@ $<

# Alvo (target) para a construcao do objeto bancodados.o
# Define os arquivos bancodados.cpp e bancodados.h como dependencias.
$(OBJ_DIR)/bancodados.o: $(SRC_DIR)/bancodados.cpp $(INC_DIR)/bancodados.h
	$(CC) -c $(CFLAGS) -o $@ $<

# Alvo (target) para a construcao do objeto funcoes.o
# Define os arquivos funcoes.cpp e funcoes.h como dependencias.
$(OBJ_DIR)/funcoes.o: $(SRC_DIR)/funcoes.cpp $(INC_DIR)/funcoes.h
	$(CC) -c $(CFLAGS) -o $@ $<

# Alvo (target) para a construcao do objeto main.o
# Define o arquivo main.cpp como dependencia.
$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp
	$(CC) -c $(CFLAGS) -o $@ $<

# Alvo (target) para a construcao do objeto teste.o
# Define o arquivo teste.cpp como dependencias.
$(OBJ_DIR)/teste.o: $(TST_DIR)/teste.cpp
	$(CC) -c $(CFLAGS) -o $@ $<

# Alvo (target) para a geração automatica de documentacao usando o Doxygen.
# Sempre remove a documentacao anterior (caso exista) e gera uma nova.
doxy:
	$(RM) $(DOC_DIR)/*
	doxygen Doxyfile

# Alvo (target) usado para limpar os arquivos temporarios (objeto)
# gerados durante a compilacao, assim como os arquivos binarios/executaveis.
clean:
	$(RM) $(BIN_DIR)/*
	$(RM) $(OBJ_DIR)/*
