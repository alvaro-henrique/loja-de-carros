#ifndef CARRO_H
#define CARRO_H

#include <string>
#include <vector>
#include "excecoes.h" 

/**
 * @class Carro
 * @brief Representa um veículo no sistema da concessionária
 * @details Encapsula informações do veículo: placa, modelo, marca, ano, preços e status
 */
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
    /// Construtor
    Carro(const std::string& placa, const std::string& modelo, const std::string& cor, 
          const std::string& marca, int ano, float precoCompra, float precoVenda, 
          const std::string& status = "Disponível");
    
    /// @name Getters (consultores)
    /// @{
    std::string getPlaca() const;      ///< Retorna a placa do carro
    std::string getModelo() const;     ///< Retorna o modelo do carro
    std::string getCor() const;        ///< Retorna a cor do carro
    std::string getMarca() const;      ///< Retorna a marca do carro
    int getAno() const;                ///< Retorna o ano do carro
    float getPrecoCompra() const;      ///< Retorna o preço de compra
    float getPrecoVenda() const;       ///< Retorna o preço de venda
    std::string getStatus() const;     ///< Retorna o status do carro
    /// @}
    
    /// @name Setters (modificadores)
    /// @{
    void setPlaca(const std::string& placa);           ///< Define a placa
    void setModelo(const std::string& modelo);         ///< Define o modelo
    void setCor(const std::string& cor);               ///< Define a cor
    void setMarca(const std::string& marca);           ///< Define a marca
    void setAno(int ano);                              ///< Define o ano
    void setPrecoCompra(float precoCompra);            ///< Define o preço de compra
    void setPrecoVenda(float precoVenda);              ///< Define o preço de venda
    void setStatus(const std::string& status);         ///< Define o status
    /// @}
    
    /// Verifica se placa já existe
    static void verificarPlacaDuplicada(const std::vector<Carro*>& carros, const std::string& placa);
    
    /// Verifica se está disponível para venda
    bool estaDisponivel() const;
    /// Marca como vendido
    void vender();
    /// Marca como comprado
    void comprar();
    float calcularLucro();
    void exibirCarro();
};

#endif // CARRO_H