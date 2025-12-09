#include <iostream>
#include <vector>
#include <string>

#include "menus.h"
using namespace std;


void menuPrincipal() {
    system("clear");
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
    cout << "2. Listar clientes" << endl;
    cout << "3. Ver histórico de cliente" << endl;
    cout << "4. Alterar Cliente" << endl;
    cout << "5. Voltar" << endl;
    cout << "Escolha uma opção: ";
}

void menu_alterar_cliente() {
    cout << "\n--- ALTERAR CLIENTE ---" << endl;
    cout << "1. Alterar Nome" << endl;
    cout << "2. Alterar Idade" << endl;
    cout << "3. Alterar Telefone" << endl;
    cout << "4. Alterar Email" << endl;
    cout << "5. Alterar Endereço" << endl;
    cout << "0. Voltar" << endl;
    cout << "Escolha uma opção: ";
}

void menuFuncionarios() {
    cout << "\n--- GERENCIAR FUNCIONÁRIOS ---" << endl;
    cout << "1. Cadastrar funcionário" << endl;

    cout << "2. Listar funcionários\n";
    cout << "3. Atualizar funcionário\n";
    cout << "4. Remover funcionário\n";
    cout << "0. Sair\n";
    cout << "Escolha uma opção: ";
}

void menuVendas() {
    cout << "\n=== REALIZAR VENDA ===" << endl;
    cout << "1. Nova Venda" << endl;
    cout << "2. Histórico de Vendas" << endl;
    cout << "3. Voltar" << endl;
    cout << "Escolha uma opção: ";
}

void menu_alterar_funcionario() {
    cout << "\n--- ALTERAR FUNCIONÁRIO ---" << endl;
    cout << "1. Alterar Nome" << endl;
    cout << "2. Alterar Idade" << endl;
    cout << "3. Alterar Telefone" << endl;
    cout << "4. Alterar Email" << endl;
    cout << "5. Alterar Endereço" << endl;
    cout << "6. Alterar Salário" << endl;
    cout << "7. Alterar Código" << endl;
    cout << "8. Alterar Tema" << endl;
    cout << "9. Alterar Nome de Exibicao" << endl;
    cout << "0. Voltar" << endl;
    cout << "Escolha uma opção: ";
}

void menuPreferenciaUsuario() {
    // Menu para o usuário final
    cout << "\n--- PREFERÊNCIAS DO USUÁRIO ---" << endl;
    cout << "1. Listar Preferencias" << endl;
    cout << "2. Alterar Tema" << endl;
    cout << "3. Altera Nome de Exibicao" << endl;
    cout << "4. Menu de Inicio" << endl;
}




