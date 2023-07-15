#ifndef OPICOES_H
#define OPICOES_H

#include <iostream>
#include <string>
#include <cstdlib> 
#include <dirent.h> 

#include "QuadroKanban.h"
#include "Estruturas.hpp"
#include "AlgoritmosOrdenacao.hpp"

void executarPrimeiraAcao(QuadroKanban *quadroKaban);
void executarSegundaAcao(QuadroKanban *quadroKaban);
void executarTerceiraAcao(QuadroKanban *quadroKaban);
void executarQuartaAcao(QuadroKanban *quadroKaban);

#endif 
