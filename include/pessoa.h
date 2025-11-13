#ifndef PESSOA_H
#define PESSOA_H

#include <string>
#include "endereco.h" // Dependência para composição
#include "excecoes.h" // Dependência para validações

// Classe base para Pessoa (Cliente e Funcionario herdam dela)
class Pessoa {
protected:
   // Atributos protegidos (acessíveis por classes derivadas)
    std::string CPF;        // Número do CPF
    std::string nome;       // Nome completo
    int idade;              // Idade em anos
    std::string telefone;   // Número de telefone
    std::string email;      // Endereço de email
    Endereco* endereco;     // Ponteiro para objeto Endereco (composição)

    bool validarCPF(std::string cpf); //Retorna true se o CPF é válido, false caso contrário.

public:
    // Construtor
    Pessoa(std::string CPF, std::string nome, int idade, std::string telefone, 
           std::string email, Endereco* endereco);
    
    // Destrutor 
    virtual ~Pessoa();
    
    // Getters
    std::string getCPF();
    std::string getNome();
    int getIdade();
    std::string getTelefone();
    std::string getEmail();
    Endereco* getEndereco();
    
    // Setters
    void setCPF(std::string CPF);
    void setNome(std::string nome);
    void setIdade(int idade);
    void setTelefone(std::string telefone);
    void setEmail(std::string email);
    void setEndereco(Endereco* endereco);
    
    // Exibe informações da pessoa
    virtual void exibirInformacoes();
};

#endif 