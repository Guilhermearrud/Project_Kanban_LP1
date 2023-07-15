#include "../include/QuadroKanban.h"

QuadroKanban::QuadroKanban() {}
QuadroKanban::~QuadroKanban() {}

void QuadroKanban::adicionarColuna(const std::string &nomeColuna)
{
  ColunaQuadro coluna(nomeColuna);
  colunas.pushBack(coluna);
};

void QuadroKanban::adicionarTarefaColuna(int idColuna, const ListaTarefas &tarefa)
{
  ColunaQuadro &coluna = colunas.get(idColuna);
  coluna.tarefas.pushBack(tarefa);
};

void QuadroKanban::mostrarColuna(int idColuna) const
{
  const ColunaQuadro &coluna = colunas.get(idColuna);

  std::cout << "Coluna " << (idColuna + 1) << " - " << coluna.name << ":\n";
  for (int i = 0; i < coluna.tarefas.PegarTamanhoQuadro(); ++i)
  {
    const ListaTarefas &tarefa = coluna.tarefas.get(i);
    std::cout << tarefa.pegarTituloId() << "\n";
  }
  std::cout << std::endl;
}

void QuadroKanban::MostrarQuadro() const
{

  // RESPONSIVIDADE
  int numColumn = colunas.PegarTamanhoQuadro();
  int columnWidth = 0;
  
  switch (numColumn)
  {
  case 1:
    columnWidth = 72;
    break;
  case 2:
    columnWidth = 48;
    break;
  case 3:
    columnWidth = 35;
    break;
  case 4:
    columnWidth = 32;
    break;
  }

  int firstColumnWidth = 0;

  if (numColumn <= 4)
  {
    firstColumnWidth = columnWidth - 14;
  }
 

  std::cout << std::right << std::setw(firstColumnWidth) << "";
  // Imprime os títulos das colunas lado a lado
  for (int i = 0; i < colunas.PegarTamanhoQuadro(); i++)
  {
    std::cout << std::left << std::setw(columnWidth) << std::setfill(' ') << colunas.get(i).name;
  }
  std::cout << std::endl;

  // Encontra a maior quantidade de tarefas em uma coluna
  int maxTasks = 0;
  for (int i = 0; i < colunas.PegarTamanhoQuadro(); ++i)
  {
    int columnSize = colunas.get(i).tarefas.PegarTamanhoQuadro();
    if (columnSize > maxTasks)
    {
      maxTasks = columnSize;
    }
  }


  for (int i = 0; i < maxTasks; ++i)
  {
    std::cout << std::right << std::setw(firstColumnWidth) << "";
    for (int j = 0; j < colunas.PegarTamanhoQuadro(); ++j)
    {

      if (i < colunas.get(j).tarefas.PegarTamanhoQuadro())
      { // se i for menor que o número de tarefas de uma coluna
        std::cout << std::left << std::setw(columnWidth + 9) << std::setfill(' ');
        const ListaTarefas &tarefa = colunas.get(j).tarefas.get(i); 
        std::string taskTitle = tarefa.pegarTituloId();
        std::cout << taskTitle;
      }
      else
      {
        std::cout << std::left << std::setw(columnWidth) << std::setfill(' ');
        std::cout << "";
      }
    }
    std::cout << std::endl;
  }

}

bool QuadroKanban::quadroVazio() const
{
  for (int i = 0; i < colunas.PegarTamanhoQuadro(); ++i)
  {
    ColunaQuadro &coluna = colunas.get(i);
    if (!coluna.tarefas.isEmpty())
    {
      return false;
    }
  }
  return true;
}

void QuadroKanban::moverTarefa(int idTarefa, int idcolunaDestino)
{
  ListaTarefas *tarefa = encontrarTarefa(idTarefa);

  if (tarefa == NULL)
  {
    std::cout << "Tarefa nao encontrada." << std::endl;
    return;
  }

  ColunaQuadro *colunaOrigem = encontrarColunaTarefa(idTarefa);
  if (colunaOrigem == NULL)
  {
    std::cout << "Coluna de origem não encontrada para a tarefa." << std::endl;
    return;
  }

  ColunaQuadro &colunaDestino = colunas.get(idcolunaDestino);

  colunaDestino.tarefas.pushBack(*tarefa);
  colunaOrigem->tarefas.removeValue(*tarefa);
};

void QuadroKanban::organizarColuna(int idColuna, int flag)
{

  if (idColuna < 0 || idColuna >= colunas.PegarTamanhoQuadro())
  {
    std::cout << "Coluna inválida." << std::endl;
    return;
  };

  ColunaQuadro &coluna = colunas.get(idColuna);
  ListaDuplamenteEncadeada<ListaTarefas> &tarefas = coluna.tarefas;
  int numTarefas = tarefas.PegarTamanhoQuadro();

  switch (flag)
  {

  case 1:
    AlgoritmosOrdenacao<ListaTarefas>::bubbleSort(tarefas, numTarefas);
    break;

  case 2:
    AlgoritmosOrdenacao<ListaTarefas>::selectionSort(tarefas, numTarefas);
    break;

  default:
    return;
  }
}

void QuadroKanban::imprimirColuna(int columnIndex) const
{
  const ColunaQuadro &coluna = colunas.get(columnIndex);

  std::cout << "Coluna " << (columnIndex + 1) << " - " << coluna.name << ":\n";
  for (int i = 0; i < coluna.tarefas.PegarTamanhoQuadro(); ++i)
  {
    const ListaTarefas &tarefa = coluna.tarefas.get(i);
    std::cout << tarefa.pegarTituloId() << "\n";
  }
  std::cout << std::endl;
}

bool QuadroKanban::colunaVazia(int columnIndex) const
{
  const ColunaQuadro &coluna = colunas.get(columnIndex);
  if (coluna.tarefas.isEmpty())
  {
    return true;
  }
  else
  {
    return false;
  }
}

int QuadroKanban::pegarColunas() const
{
  return colunas.PegarTamanhoQuadro();
}

ListaTarefas *QuadroKanban::encontrarTarefa(int id)
{
  for (int j = 0; j < colunas.PegarTamanhoQuadro(); ++j)
  {
    ColunaQuadro &coluna = colunas.get(j);
    for (int i = 0; i < coluna.tarefas.PegarTamanhoQuadro(); ++i)
    {
      if (id == coluna.tarefas.get(i).pegarId() && coluna.tarefas.isEmpty() == false)
      {
        return &coluna.tarefas.get(i);
      }
    }
  }
  return NULL;
}

bool QuadroKanban::removerTarefa(int taskId)
{
  ListaTarefas *tarefa = encontrarTarefa(taskId);

  if (tarefa == NULL)
    return false;

  ColunaQuadro *coluna = encontrarColunaTarefa(taskId);
  coluna->tarefas.removeValue(*tarefa);
  return true;
}

void QuadroKanban::salvarTxt(const std::string& fileName) const
{
          std::ofstream file(fileName.c_str());
          
          if (!file) {
              std::cout << "Erro ao abrir o arquivo " << fileName << std::endl;
              return;
          }

          int numTasks = 1;
          // Imprime no arquivo txt
          for (int i = 0; i < colunas.PegarTamanhoQuadro(); i++) {
              const ColunaQuadro& coluna = colunas.get(i);
              file << "*======================================*\n";
              file << "           Coluna " << (i + 1) << ": " << coluna.name << std::endl;
              file << "\n" << std::endl;
              const ListaDuplamenteEncadeada<ListaTarefas>& tarefas = coluna.tarefas;
              for (int j = 0; j < tarefas.PegarTamanhoQuadro(); j++) {
                  const ListaTarefas& tarefa = tarefas.get(j);
                  file << "+-------------------------------------+\n";
                  file << "|              Tarefa " << numTasks << "               |\n"; 
                  file << "+-------------------------------------+\n";
                  file << " Título: " << tarefa.pegarTitulo() << "\n";
                  file << " Descrição: " << tarefa.pegarDescricao() << "\n";
                  file << "+-------------------------------------+\n\n";
                  numTasks++; 
              }
              file << std::endl;
              file << "*======================================*\n";
              file << "\n" << std::endl;
          }

          file.close();

          std::cout << "Tabela salva no arquivo " << fileName << " com sucesso." << std::endl;
}

