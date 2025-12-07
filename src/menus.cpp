#include <iostream>
#include <vector>
#include <string>

#include "menus.h"
#include "include.h"
using namespace std;


void menuPrincipal() {
    system("clear");
    mostrarCabecalho();
    cout << "\n=== SISTEMA CONCESSIONÁRIA ===" << endl;
    cout << "1. Gerenciar Estoque" << endl;
    cout << "2. Gerenciar Clientes" << endl;
    cout << "3. Gerenciar Funcionários" << endl;
    cout << "4. Realizar Venda" << endl;
    cout << "5. Ver Relatórios" << endl;
    cout << "6. Preferências do Usuário" << endl;
    cout << "7. Sair" << endl;
    cout << "Escolha uma opção: ";
}

void menuEstoque() {
    system("clear");
    mostrarCabecalho();
    cout << "\n=== GERENCIAR ESTOQUE ===" << endl;
    cout << "1. Comprar Carro" << endl;
    cout << "2. Ver Estoque" << endl;
    cout << "3. Ver Balanço" << endl;
    cout << "4. Voltar" << endl;
    cout << "Escolha uma opção: ";
}

void menuClientes() {
    system("clear");
    mostrarCabecalho();
    cout << "\n=== GERENCIAR CLIENTES ===" << endl;
    cout << "1. Cadastrar Cliente" << endl;
    cout << "2. Listar Clientes" << endl;
    cout << "3. Ver Histórico de Cliente" << endl;
    cout << "4. Voltar" << endl;
    cout << "Escolha uma opção: ";
}

void menuFuncionarios() {
    system("clear");
    mostrarCabecalho();
    cout << "\n===== MENU DE FUNCIONÁRIOS =====\n";
    cout << "1. Adicionar funcionário\n";
    cout << "2. Listar funcionários\n";
    cout << "3. Atualizar funcionário\n";
    cout << "4. Remover funcionário\n";
    cout << "0. Sair\n";
    cout << "Escolha uma opção: ";
}

void menuVendas() {
    system("clear");
    mostrarCabecalho();
    cout << "\n=== REALIZAR VENDA ===" << endl;
    cout << "1. Nova Venda" << endl;
    cout << "2. Histórico de Vendas" << endl;
    cout << "3. Voltar" << endl;
    cout << "Escolha uma opção: ";
}

void menuPreferenciaUsuario() {
    system("clear");
    mostrarCabecalho();
    cout << "\n ==== PREFERENCIAS DO USUARIO ====" << endl;
    cout << "1 - Listar Preferências" << endl;
    cout << "2 - Alterar Tema" << endl;
    cout << "3 - Alterar Nome de Exibição" << endl;
    cout << "4 - Trocar Usuário" << endl;
    cout << "5 - Voltar ao menu principal" << endl;
    cout << "Escolha uma opção: ";
}




