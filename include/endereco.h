#ifndef ENDERECO_H
#define ENDERECO_H

#include <iostream>
#include <string>

using namespace std;

class Endereco {
private:
    string rua;
    int numero;
    string bairro;
    string cidade;
    string estado;

public:
    Endereco(string rua, int numero, string bairro, string cidade, string estado)
        : rua(rua), numero(numero), bairro(bairro), cidade(cidade), estado(estado) {}
    
    string getRua() { return rua; }
    int getNumero() { return numero; }
    string getBairro() { return bairro; }
    string getCidade() { return cidade; }
    string getEstado() { return estado; }
    
    void setRua(string rua) { this->rua = rua; }
    void setNumero(int numero) { this->numero = numero; }
    void setBairro(string bairro) { this->bairro = bairro; }
    void setCidade(string cidade) { this->cidade = cidade; }
    void setEstado(string estado) { this->estado = estado; }
    
    void exibirEndereco() {
        cout << rua << ", " << numero << " - " << bairro << ", " << cidade << " - " << estado;
    }
};

#endif