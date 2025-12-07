#include "usuarios.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <limits>

using namespace std;

vector<Usuario> listaUsuarios;

// caminho relativo do CSV (crie a pasta data/ na raiz do projeto)
static const string CSV_PATH = "data/users.csv";

static string trim(const string &s) {
    size_t a = s.find_first_not_of(" \t\r\n");
    if (a == string::npos) return "";
    size_t b = s.find_last_not_of(" \t\r\n");
    return s.substr(a, b - a + 1);
}

void carregarUsuarios() {
    listaUsuarios.clear();

    ifstream f(CSV_PATH);
    if (!f.is_open()) {
        // arquivo pode não existir na primeira execução — criamos vazio
        ofstream out(CSV_PATH); // cria arquivo
        return;
    }

    string linha;
    while (getline(f, linha)) {
        if (linha.empty()) continue;
        stringstream ss(linha);
        string nome, tema;
        if (!getline(ss, nome, ',')) continue;
        if (!getline(ss, tema)) tema = "";
        nome = trim(nome);
        tema = trim(tema);
        if (!nome.empty()) listaUsuarios.push_back({nome, tema});
    }
    f.close();
}

void salvarUsuarios() {
    ofstream f(CSV_PATH, ios::trunc);
    if (!f.is_open()) {
        cerr << "Erro ao salvar " << CSV_PATH << "\n";
        return;
    }
    for (const auto &u : listaUsuarios) {
        f << u.nome << "," << u.tema << "\n";
    }
    f.close();
}

Usuario escolherUsuario() {
    if (listaUsuarios.empty()) {
        // fallback: criar um usuário temporário
        Usuario fallback = {"Usuario", "Padrão"};
        return fallback;
    }

    cout << "\n=== SELECIONE UM USUÁRIO ===\n\n";
    for (size_t i = 0; i < listaUsuarios.size(); ++i) {
        cout << (i+1) << " - " << listaUsuarios[i].nome
             << " (Tema: " << (listaUsuarios[i].tema.empty() ? "Padrão" : listaUsuarios[i].tema) << ")\n";
    }
    cout << "0 - Cancelar\n";
    cout << "\nEscolha (número): ";

    int opc = -1;
    if (!(cin >> opc)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Entrada inválida. Retornando ao menu.\n";
        return listaUsuarios[0];
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (opc == 0) {
        cout << "Operação cancelada. Usando primeiro usuário.\n";
        return listaUsuarios[0];
    }
    if (opc < 1 || opc > (int)listaUsuarios.size()) {
        cout << "Índice inválido. Usando primeiro usuário.\n";
        return listaUsuarios[0];
    }
    return listaUsuarios[opc - 1];
}

static string pedirNomeComConfirmacao() {
    string nome;
    string resp;
    while (true) {
        cout << "\nDigite o nome do usuário: ";
        getline(cin, nome);
        if (nome.empty()) {
            cout << "Nome não pode ser vazio. Tente novamente.\n";
            continue;
        }
        cout << "Seu nome é \"" << nome << "\"? (sim/nao): ";
        getline(cin, resp);
        string r = resp;
        transform(r.begin(), r.end(), r.begin(), ::tolower);
        if (r == "sim" || r == "s") return nome;
        cout << "Vamos tentar novamente...\n";
    }
}

string escolherTemaComConfirmacao() {
    string resp;
    int opc = 0;
    while (true) {
        cout << "\nEscolha um tema:\n";
        cout << "1 - Escuro\n";
        cout << "2 - Claro\n";
        cout << "3 - Vermelho\n";
        cout << "4 - Amarelo\n";
        cout << "5 - Padrão\n";
        cout << "Opção: ";
        if (!(cin >> opc)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada inválida. Tente novamente.\n";
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string tema;
        switch (opc) {
            case 1: tema = "Escuro"; break;
            case 2: tema = "Claro"; break;
            case 3: tema = "Vermelho"; break;
            case 4: tema = "Amarelo"; break;
            default: tema = "Padrão"; break;
        }

        cout << "Confirmar tema \"" << tema << "\"? (sim/nao): ";
        getline(cin, resp);
        string r = resp;
        transform(r.begin(), r.end(), r.begin(), ::tolower);
        if (r == "sim" || r == "s") return tema;
        cout << "Vamos escolher novamente...\n";
    }
}

Usuario criarNovoUsuario() {
    Usuario novo;
    novo.nome = pedirNomeComConfirmacao();
    novo.tema = escolherTemaComConfirmacao();

    // adiciona ao vetor e salva
    listaUsuarios.push_back(novo);
    salvarUsuarios();

    cout << "\nUsuário criado com sucesso: " << novo.nome << " (Tema: " << novo.tema << ")\n";
    return novo;
}

