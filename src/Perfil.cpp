#include <iostream>
#include "Perfil.h"

Perfil::Perfil(const std::string& nome, const std::string& email)
    : nome(nome), email(email) {}

void Perfil::exibirPerfil() {
    std::cout << "Nome: " << nome << std::endl;
    std::cout << "E-mail: " << email << std::endl;
}
