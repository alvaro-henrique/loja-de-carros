#ifndef VENDEDOR_H
#define VENDEDOR_H

#include "../include/include.h"
#include <iostream>
#include <string>

using namespace std;

class Vendedor : public Funcionario {
private:
    float comissao;

public:
    Vendedor(string CPF, string nome, int idade, string telefone, string email, 
             Endereco* endereco, int codigo, float salario, float comissao = 0.05)
        : Funcionario(CPF, nome, idade, telefone, email, endereco, codigo, salario), 
          comissao(comissao) {}
    
    float getComissao() { return comissao; }
    
    void setComissao(float comissao) { 
        this->comissao = comissao; 
    }
    
    float calcularComissao(float valorVenda) {
        return valorVenda * comissao;
    }
    
    void exibirInformacoes() override {
        Funcionario::exibirInformacoes();
        cout << "\nComissão: " << (comissao * 100) << "%";
    }
};

#endif