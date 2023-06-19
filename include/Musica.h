#ifndef MUSICA_H
#define MUSICA_H

#include <string>

class Musica {
public:
    std::string titulo;
    std::string artista;
    std::string genero;

    Musica(const std::string& titulo, const std::string& artista, const std::string& genero);
};

#endif
