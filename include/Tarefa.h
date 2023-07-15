#ifndef TAREFA_H
#define TAREFA_H

#include <iostream>
#include <string>

class Tarefa 
{
protected:
    std::string titulo;
    std::string descricao;
    int prioridade;
    std::string dataVencimento;

public:
    Tarefa();
    Tarefa(const std::string &titulo, const std::string &descricao, int prioridade, const std::string &dataVencimento);
    Tarefa(const std::string &titulo, const std::string &descricao, int prioridade);
    Tarefa(const std::string &titulo, const std::string &descricao);
    Tarefa(const std::string &titulo);

    Tarefa(const Tarefa &other): titulo(other.titulo), descricao(other.descricao), prioridade(other.prioridade), dataVencimento(other.dataVencimento) {}

    virtual ~Tarefa(){};

    std::string pegarTitulo() const;
    std::string pegarDescricao() const;
    int pegarPrioridade() const;
    std::string pegarVencimento() const;

    void definirTitulo(std::string titulo);
    void definirDescricao(std::string descricao);
    void definirPrioridade(int prioridade);
    void definirVencimento(std::string dataVencimento);

    virtual void imprimirTarefa() const = 0;
};

#endif 

