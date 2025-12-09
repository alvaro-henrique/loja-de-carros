#ifndef PESSOA_H
#define PESSOA_H

#include <string>
#include <vector>
#include "endereco.h" // Dependência
#include "excecoes.h" // Dependência

/**
 * @class Pessoa
 * @brief Classe base para pessoas no sistema (clientes, funcionários, vendedores)
 * @details Encapsula dados pessoais como CPF, nome, idade, contato e endereço.
 *          Fornece validações e verificação de duplicatas.
 */
class Pessoa {
protected:
    // Atributos
    std::string CPF;
    std::string nome;
    int idade;
    std::string telefone;
    std::string email;
    Endereco* endereco; 

    bool validarCPF(std::string cpf);
    bool validarNome(const std::string& nome);
    bool validarTelefone(const std::string& telefone);
    bool validarEmail(const std::string& email);

public:
    // Construtor
    Pessoa(const std::string& CPF, const std::string& nome, int idade, 
           const std::string& telefone, const std::string& email, Endereco* endereco);
    
    // Destrutor 
    virtual ~Pessoa();
    
    /// @name Getters
    /// @{
    /**@brief Retorna o CPF da pessoa*/
    std::string getCPF() const;
    /**@brief Retorna o nome da pessoa*/
    std::string getNome() const;
    /**@brief Retorna a idade da pessoa*/
    int getIdade() const;
    /**@brief Retorna o telefone da pessoa*/
    std::string getTelefone() const;
    /**@brief Retorna o email da pessoa*/
    std::string getEmail() const;
    /**@brief Retorna o endereço da pessoa*/
    Endereco* getEndereco() const;
    /// @}
    
    /// @name Setters
    /// @{
    /**@brief Define o CPF da pessoa*/
    void setCPF(const std::string& CPF);
    /**@brief Define o nome da pessoa*/
    void setNome(const std::string& nome);
    /**@brief Define a idade da pessoa*/
    void setIdade(int idade);
    /**@brief Define o telefone da pessoa*/
    void setTelefone(const std::string& telefone);
    /**@brief Define o email da pessoa*/
    void setEmail(const std::string& email);
    /**@brief Define o endereço da pessoa*/
    void setEndereco(Endereco* endereco);
    /// @}
    
    // ============================================================
    // MÉTODOS ESTÁTICOS DE VALIDAÇÃO DE DUPLICADOS
    // ============================================================
    
    /**
     * Verifica se CPF já existe na lista de pessoas
     * @param pessoas - Vector com ponteiros para Pessoa ou derivadas
     * @param cpf - CPF a ser verificado
     * @throws ExcecaoCPFDuplicado - Se CPF já existe
     */
    static void verificarCPFDuplicado(const std::vector<Pessoa*>& pessoas, const std::string& cpf);

    /**
     * Verifica se telefone já existe na lista de pessoas
     * @param pessoas - Vector com ponteiros para Pessoa ou derivadas
     * @param telefone - Telefone a ser verificado
     * @throws ExcecaoTelefoneDuplicado - Se telefone já existe
     */
    static void verificarTelefoneDuplicado(const std::vector<Pessoa*>& pessoas, const std::string& telefone);

    /**
     * Verifica se email já existe na lista de pessoas
     * @param pessoas - Vector com ponteiros para Pessoa ou derivadas
     * @param email - Email a ser verificado
     * @throws ExcecaoEmailDuplicado - Se email já existe
     */
    static void verificarEmailDuplicado(const std::vector<Pessoa*>& pessoas, const std::string& email);

    /**
     * Verifica todos os três campos (CPF, telefone e email) de uma vez
     * @param pessoas - Vector com ponteiros para Pessoa ou derivadas
     * @param cpf - CPF a ser verificado
     * @param telefone - Telefone a ser verificado
     * @param email - Email a ser verificado
     * @throws Exceção de duplicado se algum campo já existe
     */
    static void verificarTodosDuplicados(const std::vector<Pessoa*>& pessoas, 
                                        const std::string& cpf, 
                                        const std::string& telefone, 
                                        const std::string& email);
    
    virtual void exibirInformacoes();
};

#endif