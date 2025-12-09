#ifndef CLIENTE_H
#define CLIENTE_H

#include "pessoa.h" 
#include <vector>
#include <string>

class Venda; 

/**
 * @class Cliente
 * @brief Representa um cliente da concessionária
 * @details Herda de Pessoa e adiciona histórico de compras
 */
class Cliente : public Pessoa {
private:
    std::vector<Venda*> historicoCompras;
    
    // Métodos auxiliares de validação
    bool validarNome(const std::string& nome);
    bool validarTelefone(const std::string& telefone);
    bool validarEmail(const std::string& email);

public:
    /// Construtor
    Cliente(const std::string& CPF, const std::string& nome, int idade, 
            const std::string& telefone, const std::string& email, Endereco* endereco);
    
    /// Destrutor
    ~Cliente();
    
    /// @name Getters
    /// @{
    /**@brief Retorna histórico de compras*/
    std::vector<Venda*> getHistoricoCompras() const;
    /**@brief Retorna total de compras realizadas*/
    int getTotalCompras() const;
    /// @}
    
    /// @name Setters com Validação
    /// @{
    void setNome(const std::string& nome);
    void setTelefone(const std::string& telefone);
    void setEmail(const std::string& email);
    void setCPF(const std::string& cpf);
    void setIdade(int idade);
    /// @}
    
    /// Adiciona uma venda ao histórico
    void adicionarVenda(Venda* venda);
    
    /// Exibe informações do cliente
    void exibirInformacoes() override;
};

#endif // CLIENTE_H