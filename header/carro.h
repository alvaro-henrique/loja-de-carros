#ifndef CARRO_H
#define CARRO_H

#include <string>
#include <vector>
#include "excecoes.h" 

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
    
    // Metodos get 
    std::string getPlaca() const;
    std::string getModelo();
    std::string getCor();
    std::string getMarca();
    int getAno();
    float getPrecoCompra();
    float getPrecoVenda();
    std::string getStatus();
    
    // Metodos set
    void setPlaca(std::string placa);
    void setModelo(std::string modelo);
    void setCor(std::string cor);
    void setMarca(std::string marca);
    void setAno(int ano);
    void setPrecoCompra(float precoCompra);
    void setPrecoVenda(float precoVenda);
    void setStatus(std::string status);
    
    // Validação de duplicidade
    static void verificarPlacaDuplicada(const std::vector<Carro*>& carros, const std::string& placa);
    
    // Outros metodos
    bool estaDisponivel();
    void vender();
    void comprar();
    float calcularLucro();
    void exibirCarro();
};

#endif // CARRO_H