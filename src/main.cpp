#include <iostream>
#include <vector>
#include <string>
#include "include.h"

using namespace std;

// Inicializar static
int Venda::proximoId = 1;

int main() {

    ExportarDataBase::verificarPastaDatabase();

    ExportarDataBase::importarFuncionariosCSV(crudFuncionarios);
    ExportarDataBase::importarConcessionariaCSV(concessionaria, crudFuncionarios);

    cout << "Avendedor1: " << vendedor1 << endl;

    if (concessionaria == nullptr) {
        cout << "Criando nova concessionária..." << endl;
        concessionaria = new Concessionaria("UFCar", "12.345.678/0001-90", 1000000.0f);
    }

    if (vendedor1 == nullptr) {
        Endereco* endereco1 = new Endereco("Av. Principal", 123, "Nova Cidade", "Natal", "RN");
        vendedor1 = new Vendedor("84986258589", "José Francisco", 20, "11999999999", 
                                "jose@ufcar.com", endereco1, 1001, 2500.0f, 0.05f, "escuro");    
        
        crudFuncionarios.criar(vendedor1);
    }

    cout << "Dvendedor1: " << vendedor1 << endl;
    
    Endereco* endereco2 = new Endereco("Rua das Flores", 456, "Cidade Nova", "Natal", "RN");
    Cliente* cliente1 = new Cliente("84992233344", "Matheus Theus", 40, "11888888888", 
                                   "matheus@gmail.com", endereco2);
    
    crudClientes.criar(cliente1);

    iniciarInterface();
    
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