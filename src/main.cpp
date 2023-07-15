#include <iostream>
#include <string>
#include "../include/QuadroKanban.h"
#include "../include/Colunas.h"
#include "../include/Estruturas.hpp"
#include "../include/Opicoes.h"
#include <fstream>

int main()
{
    QuadroKanban *quadroKanban = new QuadroKanban();
    int opcao;
    int numColunas = quadroKanban->pegarColunas();
    bool arquivoExiste;
    std::ifstream arquivo;
    int escolha;
    int id, prioridade, indexTask;
    int novoid, novaprioridade, colunadestino = 0;
    std::string novotitulo, novadescricao, novadata;
    std::string titulo, descricao, dataVencimento;
    std::string nameFile, caminhoFile;
    ListaTarefas *escolherTarefa;
    ListaTarefas tarefa;

    std::cout << "Seja bem-vindo ao meu Projeto de quadro KanBan! \n";

    // Recebendo o número de colunas
    numColunas = ReceberQuantasColunas();

    // Recebendo os nomes das colunas
    ReceberColunas(quadroKanban, numColunas);

    // Imprime o quadro com as colunas inseridas
    quadroKanban->MostrarQuadro();

    std::cout << std::endl
              << std::endl;

    do
    {
        std::cout << "| ============== MENU ===============   |\n";
        std::cout << "| 1. Adicionar Tarefa                   |\n";
        std::cout << "| 2. Editar Tarefa                      |\n";
        std::cout << "| 3. Ver Informacoes sobre uma Tarefa   |\n";
        std::cout << "| 4. Abir Quadro Kanban                 |\n";
        std::cout << "| 5. Ordernar tarefas                   |\n";
        std::cout << "| 6. Salvar Quadro em Txt               |\n";
        std::cout << "| 0. Sair                               |\n";
        std::cout << "| ===================================   |\n";
        std::cout << " Digite sua opcao:";
        std::cin >> opcao;

        switch (opcao)
        {
        case 1:
        {
            std::cout << "Forneca os dados da Tarefa"
                      << "\n";
            std::cout << "ID (inteiro): ";
            std::cin >> id;

            std::cout << "=================================";
            std::cout << "\n Titulo: ";
            std::cin.ignore(); // Limpar o buffer do teclado
            getline(std::cin, titulo);
            tarefa.definirTitulo(titulo);

            std::cout << "=================================";
            std::cout << "\nDescricao: ";
            getline(std::cin, descricao);
            tarefa.definirDescricao(descricao);

            std::cout << "=================================";
            std::cout << "\n("
                      << "1: Baixa"
                      << ","
                      << " 2: Media"
                      << ","
                      << " 3: Alta"
                      << ")";
            std::cout << "\nPrioridade: ";
            while (true)
            {
                std::cin >> prioridade;
                if (prioridade < 1 || prioridade > 3)
                {
                    std::cout << "Digite uma prioridade válida: ";
                }
                else
                {
                    tarefa.definirPrioridade(prioridade);
                    break;
                }
            }

            std::cout << "=================================";
            std::cout << "\nData de vencimento: ";
            std::cin.ignore(); // Limpar o buffer do teclado
            getline(std::cin, dataVencimento);
            tarefa.definirVencimento(dataVencimento);

            // Imprime todas as colunas
            for (int i = 0; i < numColunas; i++)
            {
                quadroKanban->mostrarColuna(i);
            }

            // Pede o índice da coluna para o usuário
            colunadestino = perguntarQualColuna(*quadroKanban, 1);
            quadroKanban->adicionarTarefaColuna(colunadestino, tarefa);

            std::cout << " Tarefa adicionada na coluna ";
            quadroKanban->mostrarColuna(colunadestino);

            std::cout << "\n";

            break;
        }
        case 2:
        {
            if (quadroKanban->quadroVazio())
            {
                std::cout << "Quadro Vazio." << std::endl;
                break;
            }

            std::cout << "| ============= MENU EDITAR =========   |\n";
            std::cout << "| 1. Editar Informacoes                 |\n";
            std::cout << "| 2. Sair                               |\n";
            std::cout << "| ===================================   |\n";
            std::cout << " Digite sua opcao:";
            std::cin >> escolha;

            switch (escolha)
            {
            case 1:
                while (true)
                {
                    quadroKanban->MostrarQuadro();
                    std::cout << "\nDigite o ID da tarefa: (Sair: 0) ";
                    std::cin >> indexTask;

                    if (indexTask == 0)
                    {
                        std::cout << "\nOperação cancelada.\n"
                                  << std::endl;
                        break;
                    }

                    escolherTarefa = quadroKanban->encontrarTarefa(indexTask);
                    if (escolherTarefa == NULL)
                    {
                        std::cout << "Tarefa nao encontrada.\n"
                                  << std::endl;
                    }
                    else
                    {
                        escolherTarefa->imprimirTarefa();

                        std::cout << "| ======= Quer Editar O Que? ========   |\n";
                        std::cout << "| 1. ID                                 |\n";
                        std::cout << "| 2. Titulo                             |\n";
                        std::cout << "| 3. Descricao                          |\n";
                        std::cout << "| 4. Prioridade                         |\n";
                        std::cout << "| 5. Data                               |\n";
                        std::cout << "| 6. Sair                               |\n";
                        std::cout << "| ===================================   |\n";
                        std::cout << "Digite o número da operação: ";
                        std::cin >> opcao;

                        escolherTarefa->imprimirTarefa();

                        switch (opcao)
                        {
                        case 1: // ==== CASO: EDITAR ID ====
                            std::cout << "\nInforme um novo ID: ";
                            std::cin >> novoid;
                            escolherTarefa->definirId(novoid);
                            std::cout << "Tarefa Atualizada:\n";
                            escolherTarefa->imprimirTarefa();
                            break;

                        case 2:
                            std::cout << "\nInforme o novo titulo: ";
                            std::cin.ignore();
                            getline(std::cin, novotitulo);
                            escolherTarefa->definirTitulo(novotitulo);
                            std::cout << "Tarefa atualizada:\n";
                            escolherTarefa->imprimirTarefa();
                            break;

                        case 3: // ==== CASO: EDITAR DESCRICAO ====
                            std::cout << "\nInforme a nova descricao: ";
                            std::cin.ignore();
                            getline(std::cin, novadescricao);
                            escolherTarefa->definirDescricao(novadescricao);
                            std::cout << "Aqui está sua tarefa atualizada:\n";
                            escolherTarefa->imprimirTarefa();
                            break;

                        case 4: // ==== CASO: EDITAR PRIORIDADE ====
                            std::cout << "\n("
                                      << "1: Baixa"
                                      << ","
                                      << " 2: Media"
                                      << ","
                                      << " 3: Alta"
                                      << ")";
                            std::cout << "\nInforme a nova prioridade: ";
                            while (true)
                            {
                                std::cin >> novaprioridade;
                                if (novaprioridade < 1 || novaprioridade > 3)
                                {
                                    std::cout << "|!| Digite uma prioridade válida: ";
                                }
                                else
                                {
                                    escolherTarefa->definirPrioridade(novaprioridade);
                                    break;
                                }
                            }

                            std::cout << "Tarefa atualizada:\n";
                            escolherTarefa->imprimirTarefa();
                            break;

                        case 5: // ==== CASO: EDITAR DATA DE VENCIMENTO ====
                            std::cout << "\nDigite nova data de vencimento: ";
                            std::cin.ignore();
                            getline(std::cin, novadata);
                            escolherTarefa->definirVencimento(novadata);

                            std::cout << "Aqui está sua tarefa atualizada:\n";
                            escolherTarefa->imprimirTarefa();
                            break;

                        case 6: // ==== CASO: VOLTAR ====
                            break;
                        default:
                            std::cout << "Opção Inválida." << std::endl;
                            break;
                        }
                    }
                }
                break;
            case 2:
                break;
            }
            break;
        }
        case 3:
        {
            if (quadroKanban->quadroVazio())
            {
                std::cout << "É necessário adicionar uma tarefa primeiro." << std::endl;
                break;
            }

            while (true)
            {
                quadroKanban->MostrarQuadro();
                std::cout << "\nDigite o ID da tarefa que deseja ver as informações (sair: 0): ";
                std::cin >> indexTask;

                if (indexTask == 0)
                {
                    std::cout << "\nOperação cancelada.\n"
                              << std::endl;
                    break; // Sai do loop
                }

                escolherTarefa = quadroKanban->encontrarTarefa(indexTask);

                if (escolherTarefa == NULL)
                { // Verifica se o ID existe
                    std::cout << "\n Tarefa não encontrada." << std::endl;
                }
                else
                {
                    escolherTarefa->imprimirTarefa();
                }
            }
            break;
        }
        case 4:
        {
            int indexTask, escolha;
            quadroKanban->MostrarQuadro();

            std::cout << "\n\n\n\n\n\n\n\n\n\nDigite 0 para sair: ";
            std::cin >> indexTask;

            if (indexTask == 0)
            {
                break; // Sai do loop
            }
            break;
        }
        case 5:
        {
            if (quadroKanban->quadroVazio())
            {
                std::cout << "Quadro Vazio." << std::endl;
                break;
            }

            std::cout << "| ============= MENU EDITAR =========   |\n";
            std::cout << "| 1. Ordernar por menor Prioridade      |\n";
            std::cout << "| 2. Ordernar por maior Prioridade      |\n";
            std::cout << "| 3. Sair                               |\n";
            std::cout << "| ===================================   |\n";
            std::cout << " Digite sua opcao:";
            std::cin >> escolha;

            switch (escolha)
            {
            case 1:
                while (true)
                {
                    for (int i = 0; i < numColunas; i++)
                    {
                        quadroKanban->imprimirColuna(i);
                    }
                    // Pede a coluna para o usuário
                    colunadestino = perguntarQualColuna(*quadroKanban, 3);

                    if (colunadestino == -1)
                    {
                        std::cout << "\nOperação cancelada.\n"
                                  << std::endl;
                        break;
                    }

                    if (quadroKanban->colunaVazia(colunadestino))
                    {
                        std::cout << "Coluna Vazia. \n"
                                  << std::endl;
                        continue;
                    }

                    quadroKanban->organizarColuna(colunadestino, 1);

                    std::cout << "A coluna " << (colunadestino + 1) << " foi ordenada pela maior prioridade\n";
                    std::cout << std::endl;
                }
                break;
            case 2:
                while (true)
                {
                    for (int i = 0; i < numColunas; i++)
                    {
                        quadroKanban->imprimirColuna(i);
                    }
                    // Pede a coluna para o usuário
                    colunadestino = perguntarQualColuna(*quadroKanban, 3);

                    if (colunadestino == -1)
                    {
                        std::cout << "\nOperação cancelada.\n"
                                  << std::endl;
                        break;
                    }

                    if (quadroKanban->colunaVazia(colunadestino))
                    {
                        std::cout << "Coluna Vazia. \n"
                                  << std::endl;
                        continue;
                    }

                    quadroKanban->organizarColuna(colunadestino, 2);

                    std::cout << "A coluna " << (colunadestino + 1) << " foi ordenada pela menor prioridade.\n";
                    std::cout << std::endl;
                }
                break;
            case 3:
                break;
            default:
                std::cout << "Opcao invalida." << std::endl;
                break;
            }
            break;
        }
        case 6:
        {
            while (true)
            {
                std::cout << "| ============= MENU EDITAR =========   |\n";
                std::cout << "| 1. Salvar em arquivo TXT              |\n";
                std::cout << "| 2. Sair                               |\n";
                std::cout << "| ===================================   |\n";
                std::cout << " Digite sua opcao:";
                std::cin >> escolha;

                if (escolha == 2)
                {
                    std::cout << "\nOperação cancelada.\n"
                              << std::endl;
                    break; // Sai do loop
                }

                switch (escolha)
                {
                case 1:
                    arquivoExiste = false;

                    do
                    {
  
                        std::cout << "Informe o nome do arquivo onde seu quadro será salvo (exemplo.txt): ";
                        std::cin >> nameFile;

                        if (nameFile.length() <= 4 || nameFile.substr(nameFile.length() - 4) != ".txt")
                        {
                         
                            std::cout <<  "Nome inválido. É necessário ter a extensão .txt " << std::endl;
                        }

                    } while (nameFile.length() <= 4 || nameFile.substr(nameFile.length() - 4) != ".txt");

                    caminhoFile = "txt/" + nameFile;

                  
                    quadroKanban->salvarTxt(caminhoFile);
                    break;

                    break;
                case 2:
                    break;
                }
            }
        }
        case 0:
            std::cout << "Saindo do programa...\n";
            break;
        default:
            std::cout << "Opção inválida. Por favor, tente novamente.\n";
            break;
        }
    } while (opcao != 0);

    delete quadroKanban;
    return 0;
}
