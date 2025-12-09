#include <iostream>
#include <vector>
#include <string>
#include "include.h"

using namespace std;

// Inicializar static
int Venda::proximoId = 1;

int main() {

    ExportarDataBase::verificarPastaDatabase();

    while (crudFuncionarios.tamanho() > 0) {
        crudFuncionarios.remover(0);
    }
    ExportarDataBase::importarFuncionariosCSV(crudFuncionarios);

    if (concessionaria == nullptr) {
        cout << "Criando nova concessionária..." << endl;
        concessionaria = new Concessionaria("UFCar", "12.345.678/0001-90", 1000000.0f);
    }
    // ExportarDataBase::importarConcessionariaCSV(concessionaria, crudFuncionarios);
    
    Endereco* endereco2 = new Endereco("Rua das Flores", 456, "Cidade Nova", "Natal", "RN");
    Cliente* cliente1 = new Cliente("84992233344", "Matheus", 40, "11888888888", 
                                   "matheus@gmail.com", endereco2);
    
    crudClientes.criar(cliente1);
    
    int opcao;
    
    do {
        menuPrincipal();
        cin >> opcao;
        cin.ignore();
        
        switch (opcao) {
            case 1:
                gerenciarEstoque(concessionaria);
                break;
            case 2:
                gerenciarClientes();
                break;
            case 3:
                gerenciarFuncionarios();
                break;
            case 4:
                gerenciarVendas();
                break;
            case 5:
                gerenciarRelatorios();
                break;
            case 6:
                gerenciarPreferenciaUsuario();
                break;
            case 7:
                cout << "Exportando dados para fechar o sistema..." << endl;

                ExportarDataBase::exportarFuncionariosCSV(crudFuncionarios);
                ExportarDataBase::exportarConcessionariaCSV(concessionaria);
                cout << "Saindo do sistema..." << endl;
                cout << "=================" << endl;
                break;
            default:
                cout << "Opção inválida!" << endl;
                break;
            }   
    }   while (opcao != 7);
    delete concessionaria;
    return 0;
}