#ifndef PESSOA_H
#define PESSOA_H

#include <string>
#include <vector>
#include "endereco.h" // Dependência
#include "excecoes.h" // Dependência

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
    Pessoa(std::string CPF, std::string nome, int idade, std::string telefone, 
           std::string email, Endereco* endereco);
    
    // Destrutor 
    virtual ~Pessoa();
    
    // Getters
    std::string getCPF() const;
    std::string getNome() const;
    int getIdade() const;
    std::string getTelefone() const;
    std::string getEmail() const;
    Endereco* getEndereco() const;
    
    // Setters
    void setCPF(std::string CPF);
    void setNome(std::string nome);
    void setIdade(int idade);
    void setTelefone(std::string telefone);
    void setEmail(std::string email);
    void setEndereco(Endereco* endereco);
    
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