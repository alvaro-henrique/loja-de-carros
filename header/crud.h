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
    ~CRUD() {
        for (T* registro : registros) {
            delete registro;
        }
    }

    void criar(T* registro) {
        registros.push_back(registro);
    }
    
    T* ler(int index) const {
        if (index < 0 || index >= (int)registros.size()) {
            throw ExcecaoIndiceInvalido(index, registros.size());
        }
        return registros[index];
    }
    
    vector<T*> lerTodos() {
        return registros;
    }
    
    void atualizar(int index, T* registro) {
        if (index < 0 || index >= (int)registros.size()) {
            throw ExcecaoIndiceInvalido(index, registros.size());
        }
        delete registros[index];
        registros[index] = registro;
    }
    
    void remover(int index) {
        if (index < 0 || index >= (int)registros.size()) {
            throw ExcecaoIndiceInvalido(index, registros.size());
        }
        delete registros[index];
        registros.erase(registros.begin() + index);
    }
    
    /// Retorna a quantidade de registros
    int tamanho() const {
        return registros.size();
    }
    
    /// Retorna todos os registros
    std::vector<T*> lerTodos() const {
        return registros;
    }
    
    /// Exibe todos os registros
    void exibirTodos() const {
        for (int i = 0; i < (int)registros.size(); i++) {
            cout << "[" << i << "] ";
            registros[i]->exibirInformacoes();
            cout << "\n---\n";
        }
    }
};

#endif