#include "pessoa.h"
#include <iostream>
#include <cctype>
#include <regex>

using namespace std;

// Métodos Auxiliares de Validação
bool Pessoa::validarCPF(string cpf) {
    return cpf.length() == 11;
}

bool Pessoa::validarNome(const string& nome) {
    // Validar: mínimo 4 caracteres e 1 espaço (nome + sobrenome)
    if (nome.length() < 4) return false;
    
    int espacos = 0;
    for (char c : nome) {
        if (c == ' ') espacos++;
    }
    
    return espacos >= 1;  // Pelo menos 1 espaço (nome e sobrenome)
}

bool Pessoa::validarTelefone(const string& telefone) {
    // Remove caracteres não-dígitos para contar
    int digitos = 0;
    for (char c : telefone) {
        if (isdigit(c)) digitos++;
    }
    return digitos >= 10;
}

bool Pessoa::validarEmail(const string& email) {
    // Validação básica de email
    regex emailRegex(R"(^[^\s@]+@[^\s@]+\.[^\s@]+$)");
    return !email.empty() && regex_match(email, emailRegex);
}

// Construtor
Pessoa::Pessoa(string CPF, string nome, int idade, string telefone, string email, Endereco* endereco)
    : nome(nome), idade(idade), telefone(telefone), email(email), endereco(endereco) {

    setCPF(CPF);
}

// Destrutor
Pessoa::~Pessoa() {
    // Libera a memória alocada para o endereço
    delete endereco;
}

// Getters
string Pessoa::getCPF() const { return CPF; }
string Pessoa::getNome() const { return nome; }
int Pessoa::getIdade() const { return idade; }
string Pessoa::getTelefone() const { return telefone; }
string Pessoa::getEmail() const { return email; }
Endereco* Pessoa::getEndereco() const { return endereco; }

// Setters
void Pessoa::setCPF(string CPF) {
    if (!validarCPF(CPF)) throw ExcecaoCPFInvalido(CPF);
    this->CPF = CPF;
}

void Pessoa::setNome(string nome) { 
    if (!validarNome(nome)) throw ExcecaoNomeInvalido();
    this->nome = nome; 
}

void Pessoa::setIdade(int idade) { 
    if (idade < 18) throw ExcecaoIdadeInvalida(idade);
    this->idade = idade; 
}

void Pessoa::setTelefone(string telefone) { 
    if (!validarTelefone(telefone)) throw ExcecaoTelefoneInvalido(telefone);
    this->telefone = telefone; 
}

void Pessoa::setEmail(string email) { 
    if (!validarEmail(email)) throw ExcecaoEmailInvalido(email);
    this->email = email; 
}

void Pessoa::setEndereco(Endereco* endereco) { 
    if (endereco == nullptr) throw ExcecaoEnderecoInvalido("Endereço não pode ser nulo");
    delete this->endereco;
    this->endereco = endereco; 
}

// Método Virtual
void Pessoa::exibirInformacoes() {
    cout << "CPF: " << CPF << "\nNome: " << nome << "\nIdade: " << idade 
            << "\nTelefone: " << telefone << "\nEmail: " << email 
            << "\nEndereço: ";
    endereco->exibirEndereco();
}

// ============================================================
// MÉTODOS ESTÁTICOS DE VALIDAÇÃO DE DUPLICADOS
// ============================================================

void Pessoa::verificarCPFDuplicado(const vector<Pessoa*>& pessoas, const string& cpf) {
    for (const Pessoa* pessoa : pessoas) {
        if (pessoa->getCPF() == cpf) {
            throw ExcecaoCPFDuplicado(cpf);
        }
    }
}

void Pessoa::verificarTelefoneDuplicado(const vector<Pessoa*>& pessoas, const string& telefone) {
    for (const Pessoa* pessoa : pessoas) {
        if (pessoa->getTelefone() == telefone) {
            throw ExcecaoTelefoneDuplicado(telefone);
        }
    }
}

void Pessoa::verificarEmailDuplicado(const vector<Pessoa*>& pessoas, const string& email) {
    for (const Pessoa* pessoa : pessoas) {
        if (pessoa->getEmail() == email) {
            throw ExcecaoEmailDuplicado(email);
        }
    }
}

void Pessoa::verificarTodosDuplicados(const vector<Pessoa*>& pessoas, 
                                     const string& cpf, 
                                     const string& telefone, 
                                     const string& email) {
    verificarCPFDuplicado(pessoas, cpf);
    verificarTelefoneDuplicado(pessoas, telefone);
    verificarEmailDuplicado(pessoas, email);
}