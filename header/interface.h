#ifndef INTERFACE_H
#define INTERFACE_H

#include <string>

// variáveis globais definidas em interface.cpp
extern std::string usuarioGlobal;
extern std::string temaGlobal;

// funções da interface
void aplicarTema(const std::string &temaNome);
void iniciarInterface();     // executa login / criação de usuário e aplica tema
void mostrarCabecalho();     // exibe cabeçalho em todos os menus

#endif // INTERFACE_H
