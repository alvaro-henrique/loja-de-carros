#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "pessoa.h"
#include <string>


class Funcionario : public Pessoa {
protected:
    // Atributos
    int codigo;
    std::string dataContratacao;
    float salario;

public:
    // Construtor
    Funcionario(std::string CPF, std::string nome, int idade, std::string telefone, 
                std::string email, Endereco* endereco, int codigo, float salario);
    
    // Getters
    int getCodigo();
    std::string getDataContratacao();
    float getSalario();
    
    // Setters
    void setCodigo(int codigo);
    void setSalario(float salario);
    
    // virtuais
    virtual float calcularSalario();
    void exibirInformacoes() override;
};

#endif // FUNCIONARIO_H