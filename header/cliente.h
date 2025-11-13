#ifndef CLIENTE_H
#define CLIENTE_H

#include "pessoa.h" 
#include <vector>
#include <string>

class Venda; 

class Cliente : public Pessoa {
private:
    std::vector<Venda*> historicoCompras;

public:
    // Construtor
    Cliente(std::string CPF, std::string nome, int idade, std::string telefone, 
            std::string email, Endereco* endereco);
    
    // Getters
    std::vector<Venda*> getHistoricoCompras();
    int getTotalCompras();
    
    // Outros Métodos
    void adicionarVenda(Venda* venda);
    
    void exibirInformacoes() override;
};

#endif // CLIENTE_H