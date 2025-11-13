#ifndef PESSOA_H
#define PESSOA_H

#include <string>
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
    
    virtual void exibirInformacoes();
};

#endif 