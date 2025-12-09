#include "carro.h"
#include <iostream>
#include <string>
#include "excecoes.h"
#include "formatacaoreal.h" 
using namespace std;


// Construtor
Carro::Carro(string placa, string modelo, string cor, string marca, int ano, 
             float precoCompra, float precoVenda, string status)
    : placa(placa), modelo(modelo), cor(cor), marca(marca), ano(ano), 
      precoCompra(precoCompra), precoVenda(precoVenda), status(status) {
}

// Getters
string Carro::getPlaca() const { return placa; }
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