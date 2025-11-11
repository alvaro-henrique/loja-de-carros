#include "pessoa.h"
#include <iostream> // Necessário para std::cout

using namespace std;

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

// Método Protegido
bool Pessoa::validarCPF(string cpf) {
    return cpf.length() == 11;
}

// Getters
string Pessoa::getCPF() { return CPF; }
string Pessoa::getNome() { return nome; }
int Pessoa::getIdade() { return idade; }
string Pessoa::getTelefone() { return telefone; }
string Pessoa::getEmail() { return email; }
Endereco* Pessoa::getEndereco() { return endereco; }

// Setters
void Pessoa::setCPF(string CPF) {
    if (!validarCPF(CPF)) throw ExcecaoCustomizada("CPF inválido!");
    this->CPF = CPF;
}

void Pessoa::setNome(string nome) { this->nome = nome; }

void Pessoa::setIdade(int idade) { 
    if (idade < 0) throw ExcecaoCustomizada("Idade não pode ser negativa!");
    this->idade = idade; 
}

void Pessoa::setTelefone(string telefone) { this->telefone = telefone; }
void Pessoa::setEmail(string email) { this->email = email; }
void Pessoa::setEndereco(Endereco* endereco) { this->endereco = endereco; }

// Método Virtual
void Pessoa::exibirInformacoes() {
    cout << "CPF: " << CPF << "\nNome: " << nome << "\nIdade: " << idade 
            << "\nTelefone: " << telefone << "\nEmail: " << email 
            << "\nEndereço: ";
    endereco->exibirEndereco();
}