#ifndef CRUD_H
#define CRUD_H

#include <vector>
#include <iostream>
#include "Excecoes.h"

using namespace std;

template<typename T>
class CRUD {
private:
    vector<T*> registros;

public:
    void criar(T* registro) {
        registros.push_back(registro);
    }
    
    T* ler(int index) {
        if (index < 0 || index >= registros.size()) {
            throw ExcecaoCustomizada("Registro não encontrado!");
        }
        return registros[index];
    }
    
    vector<T*> lerTodos() {
        return registros;
    }
    
    void atualizar(int index, T* registro) {
        if (index < 0 || index >= registros.size()) {
            throw ExcecaoCustomizada("Registro não encontrado!");
        }
        registros[index] = registro;
    }
    
    void remover(int index) {
        if (index < 0 || index >= registros.size()) {
            throw ExcecaoCustomizada("Registro não encontrado!");
        }
        registros.erase(registros.begin() + index);
    }
    
    int tamanho() {
        return registros.size();
    }
    
    void exibirTodos() {
        for (int i = 0; i < registros.size(); i++) {
            cout << "[" << i << "] ";
            registros[i]->exibirInformacoes();
            cout << "\n---\n";
        }
    }
};

#endif