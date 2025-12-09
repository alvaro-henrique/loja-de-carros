#ifndef CLIENTE_H
#define CLIENTE_H

#include "pessoa.h" 
#include <vector>
#include <string>

class Venda; 

class Cliente : public Pessoa {
private:
    std::vector<Venda*> historicoCompras;
    
    // Métodos auxiliares de validação
    bool validarNome(const std::string& nome);
    bool validarTelefone(const std::string& telefone);
    bool validarEmail(const std::string& email);

public:
    // Construtor
    Cliente(std::string CPF, std::string nome, int idade, std::string telefone, 
            std::string email, Endereco* endereco);
    
    // Destrutor
    ~Cliente();
    
    // Getters
    std::vector<Venda*> getHistoricoCompras();
    int getTotalCompras();
    
    // Setters com Validação
    void setNome(std::string nome);
    void setTelefone(std::string telefone);
    void setEmail(std::string email);
    void setCPF(std::string cpf);
    void setIdade(int idade);
    
    // Outros Métodos
    void adicionarVenda(Venda* venda);
    
    void exibirInformacoes() override;
};

#endif // CLIENTE_H