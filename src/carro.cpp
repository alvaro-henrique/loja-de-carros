#include "../include/carro.h"
#include <iostream>
#include <string>
#include "../include/excecoes.h"
#include "../include/formatacaoreal.h" 
using namespace std;


// Construtor
Carro::Carro(string placa, string modelo, string cor, string marca, int ano, 
             float precoCompra, float precoVenda, string status)
    : placa(placa), modelo(modelo), cor(cor), marca(marca), ano(ano), 
      precoCompra(precoCompra), precoVenda(precoVenda), status(status) {
}

// Getters
string Carro::getPlaca() { return placa; }
string Carro::getModelo() { return modelo; }
string Carro::getCor() { return cor; }
string Carro::getMarca() { return marca; }
int Carro::getAno() { return ano; }
float Carro::getPrecoCompra() { return precoCompra; }
float Carro::getPrecoVenda() { return precoVenda; }
string Carro::getStatus() { return status; }

// Setters
void Carro::setPlaca(string placa) { this->placa = placa; }
void Carro::setModelo(string modelo) { this->modelo = modelo; }
void Carro::setCor(string cor) { this->cor = cor; }
void Carro::setMarca(string marca) { this->marca = marca; }

void Carro::setAno(int ano) { 
    if (ano < 1900 || ano > 2030) throw ExcecaoCustomizada("Ano inválido!");
    this->ano = ano; 
}

void Carro::setPrecoCompra(float precoCompra) { 
    if (precoCompra < 0) throw ExcecaoCustomizada("Preço de compra não pode ser negativo!");
    this->precoCompra = precoCompra; 
}

void Carro::setPrecoVenda(float precoVenda) { 
    if (precoVenda < 0) throw ExcecaoCustomizada("Preço de venda não pode ser negativo!");
    this->precoVenda = precoVenda; 
}

void Carro::setStatus(string status) { this->status = status; }

// Outros Métodos
bool Carro::estaDisponivel() {
    return status == "Disponível";
}

void Carro::vender() {
    status = "Vendido";
}

void Carro::comprar() {
    status = "Disponível";
}

float Carro::calcularLucro() {
    return precoVenda - precoCompra;
}

void Carro::exibirCarro() {
    cout << marca << " " << modelo << " " << ano << " (" << cor << ") - " 
         << "Placa: " << placa << "\n";
    
    cout << "Preço Compra: " << formatarReal(precoCompra) 
         << " | Preço Venda: " << formatarReal(precoVenda) 
         << " | Lucro: " << formatarReal(calcularLucro())
         << " | Status: " << status;
}