#include <iostream>
#include <vector>
#include <string>
#include "../include/include.h"

using namespace std;

// Inicializar static
int Venda::proximoId = 1;

int main() {
    // atribuir à variável global definida em src/globals.cpp
    concessionaria = new Concessionaria("UFCar", "12.345.678/0001-90", 1000000.0f);
    
    Endereco* endereco1 = new Endereco("Av. Principal", 123, "Nova Cidade", "Natal", "RN");
    Endereco* endereco2 = new Endereco("Rua das Flores", 456, "Cidade Nova", "Natal", "RN");
    
    // atribuir à variável global vendedor1
    vendedor1 = new Vendedor("84986258589", "José", 20, "11999999999", 
                                      "jose@ufcar.com", endereco1, 1001, 2500.0f, 0.05f);
    
    Cliente* cliente1 = new Cliente("84992233344", "Matheus", 40, "11888888888", 
                                   "matheus@gmail.com", endereco2);
    
    crudFuncionarios.criar(vendedor1);
    crudClientes.criar(cliente1);
    
    int opcao;
    
    do {
        menuPrincipal();
        
        try {
            cin >> opcao;
            cin.ignore();

            // Se a leitura falhar, lança exceção
            if (cin.fail()) {
                throw runtime_error("Entrada inválida! Digite apenas números de 1 a 6.");
            }
            
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
                    cout << "Saindo do sistema..." << endl;
                    cout << "=================" << endl;
                    break;
                default:
                    throw runtime_error("Opção inválida! Digite um número entre 1 e 6.");
            }
            
        } catch (const exception& e) {
            cout << e.what() << endl;
            
            // Limpa o estado de erro e o buffer
            cin.clear();
            cin.get();
        }
        
    } while (opcao != 6);
    return 0;
}