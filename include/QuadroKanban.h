#ifndef QUADROKANBAN_H
#define QUADROKANBAN_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "ListaTarefas.h"
#include "Estruturas.hpp"
#include "AlgoritmosOrdenacao.hpp"

class QuadroKanban
{
private:
    struct ColunaQuadro
    {
        std::string name;
        ListaDuplamenteEncadeada<ListaTarefas> tarefas;

        ColunaQuadro(const std::string &nomeColuna) : name(nomeColuna) {}

        ListaDuplamenteEncadeada<ListaTarefas> &getTasks()
        {
            return tarefas;
        }
    };

    ListaDuplamenteEncadeada<ColunaQuadro> colunas;

public:
    QuadroKanban();
    ~QuadroKanban();

    void adicionarColuna(const std::string &nomeColuna);
    void adicionarTarefaColuna(int idColuna, const ListaTarefas &tarefa);
    void mostrarColuna(int idColuna) const;
    void moverTarefa(int idTarefa, int idcolunaDestino);
    void organizarColuna(int idColuna, int flag);
    void MostrarQuadro() const;
    bool quadroVazio() const;
    void imprimirColuna(int columnIndex) const;
    bool colunaVazia(int columnIndex) const;
    bool removerTarefa(int idTarefa);
    int pegarColunas() const;
    void salvarTxt(const std::string &fileName) const;


    ListaTarefas *encontrarTarefa(int id);

    ColunaQuadro *encontrarColunaTarefa(int taskId) const
    {
        for (int i = 0; i < colunas.PegarTamanhoQuadro(); i++)
        {
            ColunaQuadro &coluna = colunas.get(i);
            for (int j = 0; j < coluna.tarefas.PegarTamanhoQuadro(); j++)
            {
                if (coluna.tarefas.get(j).pegarId() == taskId)
                {
                    return &coluna;
                }
            }
        }
        return NULL;
    }
};

#endif // QUADROKANBAN_H
