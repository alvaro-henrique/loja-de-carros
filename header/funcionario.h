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
    
    // Métodos auxiliares de validação
    bool validarNome(const std::string& nome);
    bool validarTelefone(const std::string& telefone);

public:
    // Construtor
    Funcionario(std::string CPF, std::string nome, int idade, std::string telefone, 
                std::string email, Endereco* endereco, int codigo, float salario,
                std::string tema = "claro", std::string nomeExibicao = "Funcionario");
    
    // Destrutor
    virtual ~Funcionario();
    
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
    void setNome(std::string nome);
    void setTelefone(std::string telefone);
    void setCPF(std::string cpf);
    void setIdade(int idade);
    
    // virtuais
    virtual float calcularSalario();
    void exibirInformacoes() override;
};

#endif // FUNCIONARIO_H