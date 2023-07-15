#include "../include/Colunas.h"

// ==== Solicita ao usuários o número de colunas ====
int ReceberQuantasColunas()
{
    int numColunas;
    std::cout << "Para iniciar, eh necessario dizer quantas colunas gostaria de registar.\n";
    std::cin >> numColunas;
    std::cin.ignore();
    return numColunas;
}


// ==== Solicita ao usuário o nome das colunas ====
void ReceberColunas(QuadroKanban *quadroKanban, int numColunas)
{
    for (int i = 0; i < numColunas; i++)
    {
        std::string coluna;
        std::cout << (i + 1) << "# coluna: ";
        std::getline(std::cin, coluna);
        quadroKanban->adicionarColuna(coluna);
    }
}

int perguntarQualColuna(const QuadroKanban &quadroKanban, int flag)
{
    int columnIndex;
    int numColumns = quadroKanban.pegarColunas();

    switch (flag)
    {
    case 1:
        std::cout << "Digite o ID da coluna onde a tarefa vai ficar.";
        break;
    case 2:
        std::cout << "\nQual a coluna de destino?";
        break;
    case 3:
        std::cout << "Qual coluna quer ordenar? (sair: -1): ";
        break;
    default:
        std::cout << "Digite o ID da coluna";
        break;
    }

    do
    {
        std::cin >> columnIndex;
        if (columnIndex == -1)
        { 
            return -1;
        }
        if (columnIndex <= 0 || columnIndex > numColumns)
        {
            std::cout << "|!| Coluna invalida. Tente de novo. ";
        }
    } while (columnIndex <= 0 || columnIndex > numColumns);

    columnIndex -= 1;
    return columnIndex;
}

