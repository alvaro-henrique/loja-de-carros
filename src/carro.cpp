#include "carro.h"
#include <iostream>
#include <string>
#include "excecoes.h"
#include "formatacaoreal.h" 
using namespace std;


// Construtor
Carro::Carro(const string& placa, const string& modelo, const string& cor, const string& marca, int ano, 
             float precoCompra, float precoVenda, const string& status)
    : placa(placa), modelo(modelo), cor(cor), marca(marca), ano(ano), 
      precoCompra(precoCompra), precoVenda(precoVenda), status(status) {
}

// Getters
string Carro::getPlaca() const { return placa; }
string Carro::getModelo() const { return modelo; }
string Carro::getCor() const { return cor; }
string Carro::getMarca() const { return marca; }
int Carro::getAno() const { return ano; }
float Carro::getPrecoCompra() const { return precoCompra; }
float Carro::getPrecoVenda() const { return precoVenda; }
string Carro::getStatus() const { return status; }

// Setters
void Carro::setPlaca(const string& placa) { this->placa = placa; }
void Carro::setModelo(const string& modelo) { this->modelo = modelo; }
void Carro::setCor(const string& cor) { this->cor = cor; }
void Carro::setMarca(const string& marca) { this->marca = marca; }

void Carro::setAno(int ano) { 
    if (ano < 1900 || ano > 2030) throw ExcecaoAnoInvalido(ano);
    this->ano = ano; 
}

void Carro::setPrecoCompra(float precoCompra) { 
    if (precoCompra < 0) throw ExcecaoPrecoInvalido(precoCompra, "Preço de compra");
    this->precoCompra = precoCompra; 
}

void Carro::setPrecoVenda(float precoVenda) { 
    if (precoVenda < 0) throw ExcecaoPrecoInvalido(precoVenda, "Preço de venda");
    this->precoVenda = precoVenda; 
}

void Carro::setStatus(const string& status) { this->status = status; }

// Outros Métodos
bool Carro::estaDisponivel() const {
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

// Verificação de Duplicidade de Placa
void Carro::verificarPlacaDuplicada(const vector<Carro*>& carros, const string& placa) {
    for (Carro* carro : carros) {
        if (carro && carro->getPlaca() == placa) {
            throw ExcecaoPlacaDuplicada(placa);
        }
    }
}

void Carro::exibirCarro() {
    cout << marca << " " << modelo << " " << ano << " (" << cor << ") - " 
         << "Placa: " << placa << "\n";
    
    cout << "Preço Compra: " << formatarReal(precoCompra) 
         << " | Preço Venda: " << formatarReal(precoVenda) 
         << " | Lucro: " << formatarReal(calcularLucro())
         << " | Status: " << status;
}