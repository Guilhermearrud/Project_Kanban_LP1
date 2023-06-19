#ifndef LISTADEMUSICAS_H
#define LISTADEMUSICAS_H

#include <vector>
#include "Musica.h"

class ListaDeMusicas {
public:
    std::vector<Musica> musicas;

    void adicionarMusica(const Musica& musica);
    void removerMusica(const Musica& musica);
};

#endif
