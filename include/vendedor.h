#ifndef VENDEDOR_H
#define VENDEDOR_H

#include "funcionario.h"
#include <iostream>
#include <string>

using namespace std;

// Vendedor da concessionária - herda de Funcionario
class Vendedor : public Funcionario {
private:
    float comissao; // Percentual de comissão sobre vendas (ex: 0.05 = 5%)

public:
    Vendedor(string CPF, string nome, int idade, string telefone, string email, 
             Endereco* endereco, int codigo, float salario, float comissao = 0.05)
        : Funcionario(CPF, nome, idade, telefone, email, endereco, codigo, salario), 
          comissao(comissao) {}
    
    // Getters
    float getComissao() { return comissao; }
    
    // Setters
    void setComissao(float comissao) { 
        this->comissao = comissao; 
    }

    // Calcula comissão sobre venda
    float calcularComissao(float valorVenda) {
        return valorVenda * comissao;
    }
    
    //Sobrescreve o método da classe base para incluir informações de comissão.
    void exibirInformacoes() override {
        Funcionario::exibirInformacoes(); // Chama a implementação da classe base
        cout << "\nComissão: " << (comissao * 100) << "%"; // Adiciona informação de comissão
    }
};

#endif