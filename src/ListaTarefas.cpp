#include "../include/ListaTarefas.h"

ListaTarefas::ListaTarefas(int id, const std::string &titulo) : Tarefa(titulo), id(id) {}

ListaTarefas::ListaTarefas(int id, const std::string &titulo, const std::string &descricao)
    : Tarefa(titulo, descricao), id(id) {}

ListaTarefas::ListaTarefas(int id, const std::string &titulo, const std::string &descricao, int prioridade)
    : Tarefa(titulo, descricao, prioridade), id(id) {}

ListaTarefas::ListaTarefas(int id, const std::string &titulo, const std::string &descricao, int prioridade, const std::string &dataVencimento)
    : Tarefa(titulo, descricao, prioridade, dataVencimento), id(id) {}

ListaTarefas::~ListaTarefas() {}

void ListaTarefas::imprimirTarefa() const
{
    std::cout << "ID: " << id << std::endl;
    std::cout << "Titulo: " << titulo << std::endl;
    std::cout << "Descricao: " << descricao << std::endl;
    std::cout << "Prioridade: ";

    switch (prioridade)
    {
    case 1:
        std::cout << "1 - Baixa" << std::endl;
        break;
    case 2:
        std::cout << "2 - Media" << std::endl;
        break;
    case 3:
        std::cout << "3 - Alta" << std::endl;
        break;
    default:
        break;
    }
    std::cout << "Data de vencimento: " << dataVencimento << std::endl;
}

bool ListaTarefas::operator==(const ListaTarefas &other) const
{
    return this->id == other.id && this->titulo == other.titulo && this->descricao == other.descricao;
}

void ListaTarefas::definirId(int id) { this->id = id; }
int ListaTarefas::pegarId() const { return id; }


std::string ListaTarefas::pegarTituloId() const
{
    std::stringstream ss;
    ss << id;

    return titulo + " (ID:" + ss.str() + ")";

}

// Implementação dos outros métodos da lista de tarefas
