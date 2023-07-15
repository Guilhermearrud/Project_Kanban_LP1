#ifndef COLUNAS_H
#define COLUNAS_H

#include <iostream>
#include <string>
#include <cstdlib> 
#include <dirent.h> 

#include "QuadroKanban.h"
#include "Estruturas.hpp"
#include "AlgoritmosOrdenacao.hpp"

int ReceberQuantasColunas();
int perguntarQualColuna(const QuadroKanban &quadroKaban, int flag);
void ReceberColunas(QuadroKanban *quadroKaban, int numColunas);

#endif // BUSCABINARIA_H
