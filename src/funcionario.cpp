#include "funcionario.h"
#include <ctime>
#include <iostream>
#include <string>
#include "excecoes.h" 

using namespace std;

    Funcionario::Funcionario(string CPF, string nome, int idade, string telefone, string email, 
                Endereco* endereco, int codigo, float salario, string tema, string nomeExibicao)
        : Pessoa(CPF, nome, idade, telefone, email, endereco), codigo(codigo), salario(salario),
        tema(tema), nomeExibicao(nomeExibicao) {
        // Data atual simples
        time_t now = time(0);
        tm* data = localtime(&now);
        this->dataContratacao = to_string(data->tm_mday) + "/" 
                           + to_string(data->tm_mon + 1) + "/" 
                           + to_string(data->tm_year + 1900);
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
        if (salario < 0) throw ExcecaoCustomizada("Salário não pode ser negativo!");
        this->salario = salario; 
    }

    void Funcionario::setTema(string tema) {     
        this->tema = tema;
    }

    void Funcionario::setNomeExibicao(string nomeExibicao) {  
        this->nomeExibicao = nomeExibicao;
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
