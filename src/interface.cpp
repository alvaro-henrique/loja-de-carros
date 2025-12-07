#include "include.h"

#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;

// definição das variáveis globais (apenas aqui)
string usuarioGlobal = "";
string temaGlobal = "";

// helper: converte string para minúsculas
static string toLower(const string &s) {
    string out = s;
    transform(out.begin(), out.end(), out.begin(), [](unsigned char c){ return std::tolower(c); });
    return out;
}

// aplica tema apenas mostrando mensagem
void aplicarTema(const std::string &temaNome) {
    temaGlobal = temaNome;
    cout << "\nTema escolhido: " << temaGlobal << " ♡\n";
}

// limpa tela (WSL / UNIX)
static void limparTela() {
    system("clear");
}

// inicia a interface: carrega usuários, escolhe ou cria, aplica tema
void iniciarInterface() {
    carregarUsuarios(); // popula listaUsuarios

    // Se não houver usuários, forçamos criação
    if (listaUsuarios.empty()) {
        cout << "Nenhum usuário cadastrado ainda. Vamos criar um agora.\n";
        Usuario novo = criarNovoUsuario();
        usuarioGlobal = novo.nome;
        temaGlobal = novo.tema;
        aplicarTema(temaGlobal);
        limparTela();
        cout << "Bem-vindo, " << usuarioGlobal << " ♡\n\n";
        return;
    }

    // menu simples de login / criação
    int opc = 0;
    while (true) {
        limparTela();
        cout << "===========================================\n";
        cout << "              INTERFACE - LOGIN\n";
        cout << "===========================================\n\n";
        cout << "1 - Entrar com usuário existente\n";
        cout << "2 - Criar novo usuário\n";
        cout << "0 - Sair\n";
        cout << "\nEscolha: ";
        
        if (!(cin >> opc)) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (opc == 0) {
            cout << "Encerrando...\n";
            exit(0);
        } else if (opc == 1) {
            Usuario logado = escolherUsuario();
            usuarioGlobal = logado.nome;
            temaGlobal = logado.tema;
            aplicarTema(temaGlobal);
            limparTela();
            cout << "Bem-vindo de volta, " << usuarioGlobal << " ♡\n\n";
            break;
        } else if (opc == 2) {
            Usuario novo = criarNovoUsuario();
            usuarioGlobal = novo.nome;
            temaGlobal = novo.tema;
            aplicarTema(temaGlobal);
            limparTela();
            cout << "Bem-vindo, " << usuarioGlobal << " ♡\n\n";
            break;
        }
    }
}

// exibe cabeçalho sem perguntar nada (usar em cada menu)
void mostrarCabecalho() {
    cout << "===========================================\n";
    cout << " Usuario: " << (usuarioGlobal.empty() ? "N/A" : usuarioGlobal)
         << " | Tema: " << (temaGlobal.empty() ? "Padrão" : temaGlobal) << "\n";
    cout << "===========================================\n";
}
