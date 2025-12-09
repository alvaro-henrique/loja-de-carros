#ifndef CONCESSIONARIA_H
#define CONCESSIONARIA_H

#include "carro.h"
#include "crud.h"
#include "excecoes.h"
#include <vector>
#include <iostream>
#include "formatacaoreal.h"

using namespace std;

/**
 * @class Concessionaria
 * @brief Representa a concessionária de carros
 * @details Gerencia estoque de carros, caixa e transações
 */
class Concessionaria {
private:
    std::string nome;
    std::string cnpj;
    float caixa;  ///< Dinheiro em caixa
    CRUD<Carro> estoque;  ///< Estoque de carros disponíveis

public:
    /// Construtor
    Concessionaria(const std::string& nome, const std::string& cnpj, float caixaInicial)
        : nome(nome), cnpj(cnpj), caixa(caixaInicial) {}
    
    /// @name Getters
    /// @{
    /**@brief Retorna o nome da concessionária*/
    std::string getNome() const { return nome; }
    /**@brief Retorna o CNPJ da concessionária*/
    std::string getCNPJ() const { return cnpj; }
    /**@brief Retorna o saldo do caixa*/
    float getCaixa() const { return caixa; }
    /// @}
    
    /// Compra um carro para o estoque
    void comprarCarro(Carro* carro);
    
    /// Vende um carro do estoque
    void venderCarro(int indexEstoque);
    
    /// Retorna um carro específico do estoque
    Carro* getCarroEstoque(int index);
    
    /// Retorna o tamanho do estoque
    int getTamanhoEstoque() const;
    
    /// Retorna todos os carros do estoque
    std::vector<Carro*> getEstoque() const;
    
    /// Exibe o estoque completo
    void exibirEstoque() const;
    
    /// Exibe o balanço financeiro
    void exibirBalanco() const;
};

#endif