#ifndef VENDEDOR_H
#define VENDEDOR_H

#include "funcionario.h"
#include <iostream>
#include <string>

using namespace std;

/**
 * @class Vendedor
 * @brief Representa um vendedor na concessionária
 * @details Herda de Funcionario e adiciona comissão sobre vendas
 */
class Vendedor : public Funcionario {
private:
    float comissao;  ///< Taxa de comissão (ex: 0.05 = 5%)

public:
    /// Construtor
    Vendedor(const std::string& CPF, const std::string& nome, int idade, 
             const std::string& telefone, const std::string& email, 
             Endereco* endereco, int codigo, float salario, float comissao = 0.05, 
             const std::string& tema = "claro", const std::string& nomeExibicao = "Vendedor")
        : Funcionario(CPF, nome, idade, telefone, email, endereco, codigo, salario, tema, nomeExibicao), 
          comissao(comissao) {}
    
    /// Retorna a taxa de comissão
    float getComissao() const { return comissao; }
    
    /// Define a taxa de comissão
    void setComissao(float comissao) { 
        this->comissao = comissao; 
    }
    
    /// Calcula a comissão sobre um valor de venda
    float calcularComissao(float valorVenda) const {
        return valorVenda * comissao;
    }
    
    /// Exibe informações do vendedor
    void exibirInformacoes() override {
        Funcionario::exibirInformacoes();
        cout << "\nComissão: " << (comissao * 100) << "%";
    }
};

#endif