#ifndef VENDA_H
#define VENDA_H

#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

#include "cliente.h"
class Vendedor;
#include "carro.h"

class Venda {
private:
    static int proximoId;
    Cliente* cliente;
    Vendedor* vendedor;
    vector<Carro*> carros;
    string metodoPagamento;
    int id;
    string data;
    float valorTotal;

public:
    Venda(Cliente* cliente, Vendedor* vendedor, vector<Carro*> carros, string metodoPagamento)
        : cliente(cliente), vendedor(vendedor), carros(carros), metodoPagamento(metodoPagamento) {
        id = proximoId++;
        
        // Data atual simples
        time_t now = time(0);
        tm* data = localtime(&now);
        this->data = to_string(data->tm_mday) + "/" + to_string(data->tm_mon + 1) + "/" + to_string(data->tm_year + 1900);
        
        calcularValorTotal();
    }
    
    int getId() { return id; }
    string getData() { return data; }
    float getValorTotal() { return valorTotal; }
    string getMetodoPagamento() { return metodoPagamento; }
    Cliente* getCliente() { return cliente; }
    Vendedor* getVendedor() { return vendedor; }
    vector<Carro*> getCarros() { return carros; }
    
    void setMetodoPagamento(string metodoPagamento) {
        this->metodoPagamento = metodoPagamento;
    }
    
    void calcularValorTotal() {
        valorTotal = 0.0f;
        for (Carro* carro : carros) {
            valorTotal += carro->getPrecoVenda();
        }
    }
    
    // Método simplificado - sem Concessionaria
    void finalizarVenda() {
        cout << "Venda finalizada! Valor total: R$ " << valorTotal << endl;
    }
    
    void exibirVenda() {
        cout << "Venda ID: " << id << "\nData: " << data
             << "\nValor Total: R$ " << valorTotal
             << "\nMétodo: " << metodoPagamento 
             << "\nCarros: " << carros.size();
    }
};

#endif