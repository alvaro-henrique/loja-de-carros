#ifndef CONCESSIONARIA_H
#define CONCESSIONARIA_H

#include "carro.h"
#include "crud.h"
#include <vector>
#include <iostream>
#include "formatacaoreal.h" // <-- INCLUI A FUNÇÃO DE FORMATAR

using namespace std;

class Concessionaria {
private:
    string nome;
    string cnpj;
    float caixa;  // Dinheiro em caixa
    CRUD<Carro> estoque;

public:
    Concessionaria(string nome, string cnpj, float caixaInicial)
        : nome(nome), cnpj(cnpj), caixa(caixaInicial) {}
    
    string getNome() { return nome; }
    string getCNPJ() { return cnpj; }
    float getCaixa() { return caixa; }
    
    void comprarCarro(Carro* carro) {
        if (caixa >= carro->getPrecoCompra()) {
            estoque.criar(carro);
            caixa -= carro->getPrecoCompra();
            carro->comprar();
            // (A mensagem de "sucesso" foi movida para o main.cpp)
        } else {
            throw ExcecaoCustomizada("Caixa insuficiente para comprar o carro!");
        }
    }
    
    void venderCarro(int indexEstoque) {
        Carro* carro = estoque.ler(indexEstoque);
        if (carro->estaDisponivel()) {
            caixa += carro->getPrecoVenda();
            carro->vender();
            cout << "Carro vendido! Lucro: " << formatarReal(carro->calcularLucro()) 
                 << " | Caixa atual: " << formatarReal(caixa) << endl;
            estoque.remover(indexEstoque);
        } else {
            throw ExcecaoCustomizada("Carro não está disponível para venda!");
        }
    }
    
    Carro* getCarroEstoque(int index) {
        return estoque.ler(index);
    }
    
    int getTamanhoEstoque() {
        return estoque.tamanho();
    }
    
    void exibirEstoque() {
        cout << "=== ESTOQUE DA CONCESSIONÁRIA ===" << endl;
        cout << "Nome: " << nome << " | CNPJ: " << cnpj << " | Caixa: " << formatarReal(caixa) << endl;
        for (int i = 0; i < estoque.tamanho(); i++) {
            cout << "[" << i << "] ";
            estoque.ler(i)->exibirCarro();
            cout << "\n---\n";
        }
    }
    
    // --- MÉTODO ATUALIZADO ---
    void exibirBalanco() {
        float totalInvestido = 0;
        int carrosDisponiveis = 0;
        
        for (int i = 0; i < estoque.tamanho(); i++) {
            Carro* carro = estoque.ler(i);
            totalInvestido += carro->getPrecoCompra();
            if (carro->estaDisponivel()) {
                carrosDisponiveis++;
            }
        }
        
        cout << "=== BALANÇO ===" << endl;
        
        cout << "Caixa: " << formatarReal(caixa) << endl;
        cout << "Total investido em estoque: " << formatarReal(totalInvestido) << endl;
        
        cout << "Carros disponíveis: " << carrosDisponiveis << "/" << estoque.tamanho() << endl;
    }
};

#endif