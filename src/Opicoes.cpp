#include "../include/Colunas.h"
#include "../include/Opicoes.h"



void executarPrimeiraAcao(QuadroKanban *quadroKanban)
{
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

    std::cout << "Forneca os dados da Tarefa"
              << "\n";
    std::cout << "ID (inteiro): ";

    std::cin >> id;

    std::cout << "=================================";
    std::cout << "Titulo: ";
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
            std::cout << "Digite uma prioridade";
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

    // Pede o index da coluna para o usuário
    colunadestino = perguntarQualColuna(*quadroKanban, 1);
    quadroKanban->adicionarTarefaColuna(colunadestino, tarefa);

    std::cout << " Tarefa adicionada na coluna ";

    quadroKanban->mostrarColuna(colunadestino);
}

void executarSegundaAcao(QuadroKanban *quadroKanban)
{
    int numColunas = quadroKanban->pegarColunas();
    bool arquivoExiste;
    std::ifstream arquivo;
    int escolha, opcao;
    int id, prioridade, indexTask;
    int novoid, novaprioridade, colunadestino = 0;
    std::string novotitulo, novadescricao, novadata;
    std::string titulo, descricao, dataVencimento;
    std::string nameFile, caminhoFile;
    ListaTarefas *tarefaEscolhida;
    ListaTarefas tarefa;

    if (quadroKanban->quadroVazio())
    {
        std::cout << "Quadro Vazio." << std::endl;
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

            tarefaEscolhida = quadroKanban->encontrarTarefa(indexTask);
            if (tarefaEscolhida == NULL)
            {
                std::cout << "Tarefa nao encontrada.\n"
                          << std::endl;
            }
            else
            {

                tarefaEscolhida->imprimirTarefa();

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

                tarefaEscolhida->imprimirTarefa();

                switch (opcao)
                {

                case 1:
                    std::cout << "\nInforme um novo ID: ";
                    tarefaEscolhida->definirId(novoid);
                    break;
                    std::cout << "Tarefa Atualizada:\n";
                    tarefaEscolhida->imprimirTarefa();
                    break;

                case 2: 
                    std::cout << "\nInforme o novo titulo: ";
                    std::cin.ignore();
                    getline(std::cin, novotitulo);
                    tarefaEscolhida->definirTitulo(novotitulo);
                    std::cout << "Tarefa atualizada:\n";
                    tarefaEscolhida->imprimirTarefa();
                    break;

                case 3: 
                    std::cout << "\nInforme a nova descricao: ";
                    std::cin.ignore();
                    getline(std::cin, novadescricao);
                    tarefaEscolhida->definirDescricao(novadescricao);
                    std::cout << "Aqui está sua tarefa atualizada:\n";
                    tarefaEscolhida->imprimirTarefa();
                    break;

                case 4: 
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
                            tarefaEscolhida->definirPrioridade(novaprioridade);
                            break;
                        }
                    }

                    std::cout << "Tarefa atualizada:\n";
                    tarefaEscolhida->imprimirTarefa();
                    break;

                case 5: 
                    std::cout << "\nDigite nova data de vencimento: ";
                    std::cin >> novadata;
                    tarefaEscolhida->definirVencimento(novadata);

                    std::cout << "Aqui está sua tarefa atualizada:\n";
                    tarefaEscolhida->imprimirTarefa();
                    break;

                case 6: 
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
    
}

void executarQuartaAcao(QuadroKanban *quadroKanban)
{
    int indexTask, escolha;

    switch (escolha)
    {

        {
            quadroKanban->MostrarQuadro();

            std::cout << "\n\n\n\n\n\n\n\n\n\nDigite -1 para sair: ";
            std::cin >> indexTask;

             if (indexTask == -1)
            {
                break; // Sai do loop
            }
        }
        break;
    }
}