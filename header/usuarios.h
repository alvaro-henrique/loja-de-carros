#ifndef USUARIOS_H
#define USUARIOS_H

#include <string>
#include <vector>

struct Usuario {
    std::string nome;
    std::string tema;
};

extern std::vector<Usuario> listaUsuarios;

void carregarUsuarios();          // lê data/users.csv -> listaUsuarios
void salvarUsuarios();            // escreve listaUsuarios -> data/users.csv
Usuario escolherUsuario();        // mostra lista e retorna o escolhido (por índice)
Usuario criarNovoUsuario();       // cria novo (com confirmações) e salva
std::string escolherTemaComConfirmacao();


#endif // USUARIOS_H
