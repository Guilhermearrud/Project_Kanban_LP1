#ifndef PERFIL_H
#define PERFIL_H

#include <string>

class Perfil {
public:
    std::string nome;
    std::string email;

    Perfil(const std::string& nome, const std::string& genero);

    void exibirPerfil();
};

#endif
