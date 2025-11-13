#ifndef CARRO_H
#define CARRO_H

#include <string>
#include "excecoes.h" 

// Classe que representa um carro no sistema
class Carro {
private:
    std::string placa;
    std::string modelo;
    std::string cor;
    std::string marca;
    int ano;
    float precoCompra;
    float precoVenda;
    std::string status;

public:
    // Construtor
    Carro(std::string placa, std::string modelo, std::string cor, std::string marca, int ano, 
        float precoCompra, float precoVenda, std::string status = "Disponível");
    
    // Métodos de acesso
    std::string getPlaca();
    std::string getModelo();
    std::string getCor();
    std::string getMarca();
    int getAno();
    float getPrecoCompra();
    float getPrecoVenda();
    std::string getStatus();
    
    // Métodos de modificação
    void setPlaca(std::string placa);
    void setModelo(std::string modelo);
    void setCor(std::string cor);
    void setMarca(std::string marca);
    void setAno(int ano);
    void setPrecoCompra(float precoCompra);
    void setPrecoVenda(float precoVenda);
    void setStatus(std::string status);
    
    // Métodos de negócio
    bool estaDisponivel();
    void vender();
    void comprar();
    float calcularLucro();
    void exibirCarro();
};

#endif // CARRO_H