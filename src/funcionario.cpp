#include "funcionario.h"
#include <ctime>
#include <iostream>
#include <string>
#include <cctype>
#include "excecoes.h" 

using namespace std;

// Métodos Auxiliares de Validação
bool Funcionario::validarNome(const string& nome) {
    // Validar: mínimo 4 caracteres e 1 espaço (nome + sobrenome)
    if (nome.length() < 4) return false;
    
    int espacos = 0;
    for (char c : nome) {
        if (c == ' ') espacos++;
    }
    
    return espacos >= 1;  // Pelo menos 1 espaço (nome e sobrenome)
}

bool Funcionario::validarTelefone(const string& telefone) {
    // Remove caracteres não-dígitos para contar
    int digitos = 0;
    for (char c : telefone) {
        if (isdigit(c)) digitos++;
    }
    return digitos >= 10;
}

// Construtor
Funcionario::Funcionario(string CPF, string nome, int idade, string telefone, string email, 
            Endereco* endereco, int codigo, float salario, string tema, string nomeExibicao)
    : Pessoa(CPF, nome, idade, telefone, email, endereco), codigo(codigo), salario(salario),
    tema(tema), nomeExibicao(nomeExibicao) {
    
    // Validações adicionais no construtor
    if (!validarNome(nome)) {
        throw ExcecaoNomeInvalido();
    }
    if (!validarTelefone(telefone)) {
        throw ExcecaoTelefoneInvalido(telefone);
    }
    
    // Data atual simples
    time_t now = time(0);
    tm* data = localtime(&now);
    this->dataContratacao = to_string(data->tm_mday) + "/" 
                       + to_string(data->tm_mon + 1) + "/" 

                       + to_string(data->tm_year + 1900);
}

// Destrutor
Funcionario::~Funcionario() {
    // Apenas strings e dados primitivos são limpados automaticamente
    // Endereco será liberado pelo destrutor de Pessoa
}

// Getters
int Funcionario::getCodigo() { return codigo; }
string Funcionario::getDataContratacao() { return dataContratacao; }
float Funcionario::getSalario() { return salario; }
string Funcionario::getTema() { return tema; }                    
string Funcionario::getNomeExibicao() { return nomeExibicao; }    

// Setters
void Funcionario::setCodigo(int codigo) { this->codigo = codigo; }

void Funcionario::setSalario(float salario) { 
    if (salario < 0) throw ExcecaoSalarioInvalido(salario);
    this->salario = salario; 
}

void Funcionario::setTema(string tema) {     
    this->tema = tema;
}

void Funcionario::setNomeExibicao(string nomeExibicao) {  
    this->nomeExibicao = nomeExibicao;
}

void Funcionario::setNome(string nome) {
    if (!validarNome(nome)) {
        throw ExcecaoNomeInvalido();
    }
    Pessoa::setNome(nome);
}

void Funcionario::setTelefone(string telefone) {
    if (!validarTelefone(telefone)) {
        throw ExcecaoTelefoneInvalido(telefone);
    }
    Pessoa::setTelefone(telefone);
}

void Funcionario::setCPF(string cpf) {
    Pessoa::setCPF(cpf);  // Usa validação de CPF da classe Pessoa
}

void Funcionario::setIdade(int idade) {
    Pessoa::setIdade(idade);  // Usa validação de idade da classe Pessoa
}

float Funcionario::calcularSalario() {
    // Implementação padrão (como no original)
    return salario;
}

void Funcionario::exibirInformacoes() {
    Pessoa::exibirInformacoes();
    cout << "\nCódigo: " << codigo << "\nSalário: R$ " << salario
         << "\nData de Contratação: " << dataContratacao
         << "\nTema: " << tema          
        << "\nNome de Exibição: " << nomeExibicao; 
}