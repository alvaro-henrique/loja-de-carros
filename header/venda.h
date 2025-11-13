#ifndef VENDA_H
#define VENDA_H

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include "../include/include.h"

using namespace std;

// Declarações forward (para evitar inclusões circulares)
class Cliente;
class Vendedor;
class Carro;

/*Gerencia todas as informações de uma venda: cliente, vendedor, carros,
  valor total, data e método de pagamento.
*/
class Venda {
private:
    static int proximoId;
    int id;
    string data;
    float valorTotal;
    string metodoPagamento;
    Cliente* cliente;
    Vendedor* vendedor;
    vector<Carro*> carros;

public:
    Venda(Cliente* cliente, Vendedor* vendedor, vector<Carro*> carros, string metodoPagamento)
        : cliente(cliente), vendedor(vendedor), carros(carros), metodoPagamento(metodoPagamento) {
        id = proximoId++;
        
        // Data atual simples
        time_t now = time(0);
        tm* data = localtime(&now);
        this->data = to_string(data->tm_mday) + "/" + to_string(data->tm_mon + 1) + "/" + to_string(data->tm_year + 1900);
        
        calcularValorTotal(); // Calcula o valor total automaticamente
    }
    
    // Getters
    int getId() { return id; }
    string getData() { return data; }
    float getValorTotal() { return valorTotal; }
    string getMetodoPagamento() { return metodoPagamento; }
    Cliente* getCliente() { return cliente; }
    Vendedor* getVendedor() { return vendedor; }
    vector<Carro*> getCarros() { return carros; }
    
    // Setters
    void setMetodoPagamento(string metodoPagamento) {
        this->metodoPagamento = metodoPagamento;
    }
    
    //Soma os preços de venda de todos os carros envolvidos na venda.
    void calcularValorTotal() {
        valorTotal = 0.0f;
        for (Carro* carro : carros) {
            valorTotal += carro->getPrecoVenda();
        }
    }
    
    // Marca o carro como vendido e finaliza a venda.
    void finalizarVenda() {
        for (Carro* carro : carros) {
            carro->vender();
        }
        cout << "Venda finalizada! Valor total: R$ " << valorTotal << endl;
    }
    
    //Exibe informações resumidas da venda
    void exibirVenda() {
        cout << "Venda ID: " << id << "\nData: " << data
             << "\nValor Total: R$ " << valorTotal
             << "\nMétodo: " << metodoPagamento 
             << "\nCarros: " << carros.size();
    }
};

#endif 