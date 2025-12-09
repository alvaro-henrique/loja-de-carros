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
    std::string tema;
    std::string nomeExibicao;

public:
    // Construtor
    Funcionario(std::string CPF, std::string nome, int idade, std::string telefone, 
                std::string email, Endereco* endereco, int codigo, float salario,
                std::string tema = "claro", std::string nomeExibicao = "Funcionario");
    
    // Getters
    int getCodigo();
    std::string getDataContratacao();
    float getSalario();
    std::string getTema();
    std::string getNomeExibicao();
    
    // Setters
    void setCodigo(int codigo);
    void setSalario(float salario);
    void setTema(std::string tema);
    void setNomeExibicao(std::string nomeExibicao);
    
    // virtuais
    virtual float calcularSalario();
    void exibirInformacoes() override;
};

#endif // FUNCIONARIO_H