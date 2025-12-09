#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "pessoa.h"
#include <string>

/**
 * @class Funcionario
 * @brief Representa um funcionário da concessionária
 * @details Herda de Pessoa e adiciona informações trabalhistas
 */
class Funcionario : public Pessoa {
protected:
    // Atributos
    int codigo;
    std::string dataContratacao;
    float salario;
    std::string tema;
    std::string nomeExibicao;
    
    // Métodos auxiliares de validação
    bool validarNome(const std::string& nome);
    bool validarTelefone(const std::string& telefone);

public:
    /// Construtor
    Funcionario(const std::string& CPF, const std::string& nome, int idade, 
                const std::string& telefone, const std::string& email, Endereco* endereco, 
                int codigo, float salario, const std::string& tema = "claro", 
                const std::string& nomeExibicao = "Funcionario");
    
    /// Destrutor
    virtual ~Funcionario();
    
    /// @name Getters
    /// @{
    /**@brief Retorna o código do funcionário*/
    int getCodigo() const;
    /**@brief Retorna a data de contratação*/
    std::string getDataContratacao() const;
    /**@brief Retorna o salário*/
    float getSalario() const;
    /**@brief Retorna o tema da interface*/
    std::string getTema() const;
    /**@brief Retorna o nome de exibição*/
    std::string getNomeExibicao() const;
    /// @}
    
    /// @name Setters
    /// @{
    void setCodigo(int codigo);
    void setSalario(float salario);
    void setTema(const std::string& tema);
    void setNomeExibicao(const std::string& nomeExibicao);
    void setNome(const std::string& nome);
    void setTelefone(const std::string& telefone);
    void setCPF(const std::string& cpf);
    void setIdade(int idade);
    /// @}
    
    /// Calcula o salário do funcionário
    virtual float calcularSalario() const;
    /// Exibe informações do funcionário
    void exibirInformacoes() override;
};

#endif // FUNCIONARIO_H