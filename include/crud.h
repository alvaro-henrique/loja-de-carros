#ifndef CRUD_H
#define CRUD_H

#include <vector>
#include <iostream>
#include "excecoes.h"

using namespace std;

template<typename T>
class CRUD {
private:
    vector<T*> registros;

public:
    // Adiciona novo registro
    void criar(T* registro) {
        registros.push_back(registro);
    }

    // Lê registro por índice
    T* ler(int index) {
        if (index < 0 || index >= registros.size()) {
            throw ExcecaoCustomizada("Registro não encontrado!");
        }
        return registros[index];
    }
    
    // Retorna todos os registros
    vector<T*> lerTodos() {
        return registros;
    }
    
    // Atualiza registro existente
    void atualizar(int index, T* registro) {
        if (index < 0 || index >= registros.size()) {
            throw ExcecaoCustomizada("Registro não encontrado!");
        }
        registros[index] = registro;
    }
    
    // Remove registro
    void remover(int index) {
        if (index < 0 || index >= registros.size()) {
            throw ExcecaoCustomizada("Registro não encontrado!");
        }
        registros.erase(registros.begin() + index);
    }

    // Quantidade de registros
    int tamanho() {
        return registros.size();
    }
    
    // Exibe todos os registros
    void exibirTodos() {
        for (int i = 0; i < registros.size(); i++) {
            cout << "[" << i << "] ";
            registros[i]->exibirInformacoes();
            cout << "\n---\n";
        }
    }
};

#endif