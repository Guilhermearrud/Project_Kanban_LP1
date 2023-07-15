#ifndef LISTATAREFAS_H
#define LISTATAREFAS_H

#include <iostream>
#include <string>
#include <sstream>
#include "Tarefa.h"

class ListaTarefas : public Tarefa {
private:
    int id;

public:
    ListaTarefas() {};
    
    ListaTarefas(int id, const std::string &titulo);
    ListaTarefas(int id, const std::string &titulo, const std::string &descricao);
    ListaTarefas(int id, const std::string &titulo, const std::string &descricao, int prioridade);
    ListaTarefas(int id, const std::string &titulo, const std::string &descricao, int prioridade, const std::string &dataVencimento);
    ListaTarefas(const ListaTarefas& other) : Tarefa(other), id(other.id) {}
    ~ListaTarefas();

    void definirId(int id);
    int pegarId() const;
    std::string pegarTituloId() const;
    bool operator==(const ListaTarefas &other) const;

    void imprimirTarefa() const; // Corrected function name

    friend std::ostream& operator<<(std::ostream& os, const ListaTarefas& tarefa) {
        os << tarefa.id << " " << tarefa.titulo << " " << tarefa.descricao << " " << tarefa.prioridade << " " << tarefa.dataVencimento;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, ListaTarefas& tarefa) {
        is >> tarefa.id >> tarefa.titulo >> tarefa.descricao >> tarefa.prioridade >> tarefa.dataVencimento;
        return is;
    }
};

#endif
