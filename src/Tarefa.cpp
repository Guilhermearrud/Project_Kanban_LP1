#include "../include/Tarefa.h"

// ==== Construtores ====
Tarefa::Tarefa() {}

Tarefa::Tarefa(const std::string &titulo, const std::string &descricao, int prioridade, const std::string &dataVencimento)
    : titulo(titulo), descricao(descricao), prioridade(prioridade), dataVencimento(dataVencimento) {}

Tarefa::Tarefa(const std::string &titulo, const std::string &descricao, int prioridade)
    : titulo(titulo), descricao(descricao), prioridade(prioridade) {}

Tarefa::Tarefa(const std::string &titulo, const std::string &descricao)
    : titulo(titulo), descricao(descricao) {}

Tarefa::Tarefa(const std::string &titulo)
    : titulo(titulo) {}

// ==== Métodos getters ====
std::string Tarefa::pegarTitulo() const { return titulo; }
std::string Tarefa::pegarDescricao() const { return descricao; }
int Tarefa::pegarPrioridade() const { return prioridade; }
std::string Tarefa::pegarVencimento() const { return dataVencimento; }

// ==== Métodos setters ====
void Tarefa::definirTitulo(std::string titulo) { this->titulo = titulo; }
void Tarefa::definirDescricao(std::string descricao) { this->descricao = descricao; }
void Tarefa::definirPrioridade(int prioridade) { this->prioridade = prioridade; }
void Tarefa::definirVencimento(std::string dataVencimento) { this->dataVencimento = dataVencimento; }