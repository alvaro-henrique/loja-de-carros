#include <iostream>
#include <vector>
#include <string>

#include "../include/menus.h"
using namespace std;


void menuPrincipal() {
    cout << "\n=== SISTEMA CONCESSIONÁRIA ===" << endl;
    cout << "1. Gerenciar Estoque" << endl;
    cout << "2. Gerenciar Clientes" << endl;
    cout << "3. Gerenciar Funcionários" << endl;
    cout << "4. Realizar Venda" << endl;
    cout << "5. Ver Relatórios" << endl;
    cout << "6. Sair" << endl;
    cout << "Escolha uma opção: ";
}

void menuEstoque() {
    cout << "\n=== GERENCIAR ESTOQUE ===" << endl;
    cout << "1. Comprar Carro" << endl;
    cout << "2. Ver Estoque" << endl;
    cout << "3. Ver Balanço" << endl;
    cout << "4. Voltar" << endl;
    cout << "Escolha uma opção: ";
}

void menuClientes() {
    cout << "\n=== GERENCIAR CLIENTES ===" << endl;
    cout << "1. Cadastrar Cliente" << endl;
    cout << "2. Listar Clientes" << endl;
    cout << "3. Ver Histórico de Cliente" << endl;
    cout << "4. Voltar" << endl;
    cout << "Escolha uma opção: ";
}

void menuVendas() {
    cout << "\n=== REALIZAR VENDA ===" << endl;
    cout << "1. Nova Venda" << endl;
    cout << "2. Histórico de Vendas" << endl;
    cout << "3. Voltar" << endl;
    cout << "Escolha uma opção: ";
}



