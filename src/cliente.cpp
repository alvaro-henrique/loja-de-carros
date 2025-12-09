#include "cliente.h"
#include "excecoes.h"
#include <vector>
#include <iostream>
#include <regex>

using namespace std;

// Métodos Auxiliares de Validação
bool Cliente::validarNome(const string& nome) {
    // Validar: mínimo 4 caracteres e 1 espaço (nome + sobrenome)
    if (nome.length() < 4) return false;
    
    int espacos = 0;
    for (char c : nome) {
        if (c == ' ') espacos++;
    }
    
    return espacos >= 1;  // Pelo menos 1 espaço (nome e sobrenome)
}

bool Cliente::validarTelefone(const string& telefone) {
    // Remove caracteres não-dígitos para contar
    int digitos = 0;
    for (char c : telefone) {
        if (isdigit(c)) digitos++;
    }
    return digitos >= 10;
}

bool Cliente::validarEmail(const string& email) {
    // Validação básica de email (contém @ e .)
    regex emailRegex(R"(^[^\s@]+@[^\s@]+\.[^\s@]+$)");
    return !email.empty() && regex_match(email, emailRegex);
}

// Construtor
Cliente::Cliente(string CPF, string nome, int idade, string telefone, string email, Endereco* endereco)
    : Pessoa(CPF, nome, idade, telefone, email, endereco) {
    
    // Validações adicionais no construtor
    if (!validarNome(nome)) {
        throw ExcecaoNomeInvalido();
    }
    if (!validarTelefone(telefone)) {
        throw ExcecaoTelefoneInvalido(telefone);
    }
    if (!validarEmail(email)) {
        throw ExcecaoEmailInvalido(email);
    }
}

// Destrutor
Cliente::~Cliente() {
    // NÃO libera Venda* porque Cliente não é proprietário delas
    // O CRUD<Venda> é responsável por liberar as vendas
    historicoCompras.clear();
}

// Getters
vector<Venda*> Cliente::getHistoricoCompras() { 
    return historicoCompras; 
}

int Cliente::getTotalCompras() {
    return historicoCompras.size();
}

// Setters com Validação
void Cliente::setNome(string nome) {
    if (!validarNome(nome)) {
        throw ExcecaoNomeInvalido();
    }
    Pessoa::setNome(nome);
}

void Cliente::setTelefone(string telefone) {
    if (!validarTelefone(telefone)) {
        throw ExcecaoTelefoneInvalido(telefone);
    }
    Pessoa::setTelefone(telefone);
}

void Cliente::setEmail(string email) {
    if (!validarEmail(email)) {
        throw ExcecaoEmailInvalido(email);
    }
    Pessoa::setEmail(email);
}

void Cliente::setCPF(string cpf) {
    Pessoa::setCPF(cpf);  // Usa validação de CPF da classe Pessoa
}

void Cliente::setIdade(int idade) {
    Pessoa::setIdade(idade);  // Usa validação de idade da classe Pessoa
}

// Outros Métodos
void Cliente::adicionarVenda(Venda* venda) {
    if (venda == nullptr) {
        throw ExcecaoVendaInvalida("Venda nula não pode ser adicionada");
    }
    historicoCompras.push_back(venda);
}

void Cliente::exibirInformacoes(){
    Pessoa::exibirInformacoes();
    cout << "\nTotal de Compras: " << getTotalCompras();
}

