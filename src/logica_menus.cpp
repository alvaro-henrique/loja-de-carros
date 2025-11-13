#include <iostream>
#include <vector>
#include <string>
#include "logica_menus.h"
#include "include.h"

using namespace std;


void gerenciarEstoque(Concessionaria* concessionaria) {
    int opcaoEstoque;
    do {
        menuEstoque();
        cin >> opcaoEstoque;
        cin.ignore();
        
        switch (opcaoEstoque) {
            case 1: {
                string placa, modelo, cor, marca;
                int ano;
                float precoCompra, precoVenda;
                
                cout << "\n--- COMPRAR CARRO ---" << endl;
                // loop para garantir que a placa seja válida
    while (true) {
        std::cout << "Placa: ";
        std::getline(std::cin, placa);

        bool placaValida = (placa.size() == 7);
        if (placaValida) {
            for (char c : placa) {
                if (!std::isalnum(static_cast<unsigned char>(c))) {
                    placaValida = false;
                    break;
                }
            }
        }

        if (!placaValida) {
            std::cout << "❌ Placa inválida! Digite exatamente 7 letras ou números.\n";
        } else {
            break; // sai do while se a placa for válida
        }
    }
                cout << "Modelo: ";
                getline(cin, modelo);
                cout << "Cor: ";
                getline(cin, cor);
                cout << "Marca: ";
                getline(cin, marca);
                cout << "Ano: ";
                cin >> ano;
                cout << "Preço de Compra: R$ ";
                cin >> precoCompra;
                cout << "Preço de Venda: R$ ";
                cin >> precoVenda;
                cin.ignore();
                
                try {
                    Carro* novoCarro = new Carro(placa, modelo, cor, marca, ano, precoCompra, precoVenda );
                    concessionaria->comprarCarro(novoCarro);
                    cout << "Carro comprado com sucesso!" << endl;
                } catch (ExcecaoCustomizada& e) {
                    cout << "Erro: " << e.what() << endl;
                }
                break;
            }
            case 2:
                concessionaria->exibirEstoque();
                break;
            case 3:
                concessionaria->exibirBalanco();
                break;
            case 4:
                cout << "Voltando ao menu principal..." << endl;
                break;
            default:
                cout << "Opção inválida!" << endl;
        }
    } while (opcaoEstoque != 4);
}

void gerenciarClientes() {
    int opcaoClientes;
    do {
        menuClientes();
        cin >> opcaoClientes;
        cin.ignore();
        
        switch (opcaoClientes) {
            case 1: {
                string cpf, nome, telefone, email, rua, bairro, cidade, estado;
                int idade, numero;
                
                cout << "\n--- CADASTRAR CLIENTE ---" << endl;
                cout << "CPF: ";
                getline(cin, cpf);
                cout << "Nome: ";
                getline(cin, nome);
                cout << "Idade: ";
                cin >> idade;
                cin.ignore();
                cout << "Telefone: ";
                getline(cin, telefone);
                cout << "Email: ";
                getline(cin, email);
                
                cout << "\n--- ENDEREÇO ---" << endl;
                cout << "Rua: ";
                getline(cin, rua);
                cout << "Número: ";
                cin >> numero;
                cin.ignore();
                cout << "Bairro: ";
                getline(cin, bairro);
                cout << "Cidade: ";
                getline(cin, cidade);
                cout << "Estado: ";
                getline(cin, estado);
                
                try {
                    Endereco* endereco = new Endereco(rua, numero, bairro, cidade, estado);
                    Cliente* novoCliente = new Cliente(cpf, nome, idade, telefone, email, endereco);
                    crudClientes.criar(novoCliente);
                    cout << "Cliente cadastrado com sucesso!" << endl;
                } catch (ExcecaoCustomizada& e) {
                    cout << "Erro: " << e.what() << endl;
                }
                break;
            }
            case 2:
                cout << "\n--- CLIENTES CADASTRADOS ---" << endl;
                crudClientes.exibirTodos();
                break;
            case 3: {
                if (crudClientes.tamanho() == 0) {
                    cout << "Nenhum cliente cadastrado." << endl;
                    break;
                }
                
                cout << "\n--- HISTÓRICO DE CLIENTE ---" << endl;
                for (int i = 0; i < crudClientes.tamanho(); i++) {
                    cout << "[" << i << "] " << crudClientes.ler(i)->getNome() << endl;
                }
                cout << "Escolha o cliente: ";
                int index;
                cin >> index;
                cin.ignore();
                
                if (index >= 0 && index < crudClientes.tamanho()) {
                    Cliente* cliente = crudClientes.ler(index);
                    cout << "\nHistórico de " << cliente->getNome() << ":" << endl;
                    cout << "Total de compras: " << cliente->getTotalCompras() << endl;
                } else {
                    cout << "Cliente inválido!" << endl;
                }
                break;
            }
            case 4:
                cout << "Voltando ao menu principal..." << endl;
                break;
            default:
                cout << "Opção inválida!" << endl;
        }
    } while (opcaoClientes != 4);
}

void gerenciarFuncionarios() {
    int opcaoFuncionarios;
    do {
        menuFuncionarios();
        cin >> opcaoFuncionarios;
        cin.ignore();

        switch (opcaoFuncionarios) {
            case 1: {
                // Cadastrar funcionário
                string cpf, nome, telefone, email, rua, bairro, cidade, estado;
                int idade, numero, codigo;
                float salario;

                cout << "\n--- CADASTRAR FUNCIONÁRIO ---" << endl;
                cout << "CPF: ";
                getline(cin, cpf);
                cout << "Nome: ";
                getline(cin, nome);
                cout << "Idade: ";
                cin >> idade;
                cin.ignore();
                cout << "Telefone: ";
                getline(cin, telefone);
                cout << "Email: ";
                getline(cin, email);

                cout << "\n--- ENDEREÇO ---" << endl;
                cout << "Rua: ";
                getline(cin, rua);
                cout << "Número: ";
                cin >> numero;
                cin.ignore();
                cout << "Bairro: ";
                getline(cin, bairro);
                cout << "Cidade: ";
                getline(cin, cidade);
                cout << "Estado: ";
                getline(cin, estado);

                cout << "Código do funcionário: ";
                cin >> codigo;
                cout << "Salário: R$ ";
                cin >> salario;
                cin.ignore();

                try {
                    Endereco* endereco = new Endereco(rua, numero, bairro, cidade, estado);
                    Funcionario* novo = new Funcionario(cpf, nome, idade, telefone, email, endereco, codigo, salario);
                    crudFuncionarios.criar(novo);
                    cout << "Funcionário cadastrado com sucesso!" << endl;
                } catch (ExcecaoCustomizada& e) {
                    cout << "Erro: " << e.what() << endl;
                }
                break;
            }
            case 2: {
                // Listar funcionários
                cout << "\n--- FUNCIONÁRIOS CADASTRADOS ---" << endl;
                if (crudFuncionarios.tamanho() == 0) {
                    cout << "Nenhum funcionário cadastrado." << endl;
                } else {
                    for (int i = 0; i < crudFuncionarios.tamanho(); i++) {
                        cout << "[" << i << "] ";
                        Funcionario* f = crudFuncionarios.ler(i);
                        if (f) {
                            f->exibirInformacoes();
                            cout << "\n--------------------------\n";
                        }
                    }
                }
                break;
            }
            case 3: {
                // Atualizar funcionário
                if (crudFuncionarios.tamanho() == 0) {
                    cout << "Nenhum funcionário cadastrado." << endl;
                    break;
                }

                cout << "\n--- ATUALIZAR FUNCIONÁRIO ---" << endl;
                for (int i = 0; i < crudFuncionarios.tamanho(); i++) {
                    cout << "[" << i << "] " << crudFuncionarios.ler(i)->getNome() << endl;
                }
                cout << "Escolha o índice do funcionário: ";
                int idx;
                cin >> idx;
                cin.ignore();

                if (idx < 0 || idx >= crudFuncionarios.tamanho()) {
                    cout << "Índice inválido!" << endl;
                    break;
                }

                // Ler novos dados
                string cpf, nome, telefone, email, rua, bairro, cidade, estado;
                int idade, numero, codigo;
                float salario;

                cout << "CPF: ";
                getline(cin, cpf);
                cout << "Nome: ";
                getline(cin, nome);
                cout << "Idade: ";
                cin >> idade;
                cin.ignore();
                cout << "Telefone: ";
                getline(cin, telefone);
                cout << "Email: ";
                getline(cin, email);

                cout << "\n--- ENDEREÇO ---" << endl;
                cout << "Rua: ";
                getline(cin, rua);
                cout << "Número: ";
                cin >> numero;
                cin.ignore();
                cout << "Bairro: ";
                getline(cin, bairro);
                cout << "Cidade: ";
                getline(cin, cidade);
                cout << "Estado: ";
                getline(cin, estado);

                cout << "Código do funcionário: ";
                cin >> codigo;
                cout << "Salário: R$ ";
                cin >> salario;
                cin.ignore();

                try {
                    Endereco* endereco = new Endereco(rua, numero, bairro, cidade, estado);
                    Funcionario* atualizado = new Funcionario(cpf, nome, idade, telefone, email, endereco, codigo, salario);
                    crudFuncionarios.atualizar(idx, atualizado);
                    cout << "Funcionário atualizado com sucesso!" << endl;
                } catch (ExcecaoCustomizada& e) {
                    cout << "Erro: " << e.what() << endl;
                }
                break;
            }
            case 4: {
                // Remover funcionário
                if (crudFuncionarios.tamanho() == 0) {
                    cout << "Nenhum funcionário cadastrado." << endl;
                    break;
                }

                cout << "\n--- REMOVER FUNCIONÁRIO ---" << endl;
                for (int i = 0; i < crudFuncionarios.tamanho(); i++) {
                    cout << "[" << i << "] " << crudFuncionarios.ler(i)->getNome() << endl;
                }
                cout << "Escolha o índice do funcionário a remover: ";
                int idxRem;
                cin >> idxRem;
                cin.ignore();

                if (idxRem < 0 || idxRem >= crudFuncionarios.tamanho()) {
                    cout << "Índice inválido!" << endl;
                    break;
                }

                cout << "Confirma remoção do funcionário " << crudFuncionarios.ler(idxRem)->getNome() << "? (s/n): ";
                char confirma;
                cin >> confirma;
                cin.ignore();

                if (confirma == 's' || confirma == 'S') {
                    crudFuncionarios.remover(idxRem);
                    cout << "Funcionário removido." << endl;
                } else {
                    cout << "Remoção cancelada." << endl;
                }
                break;
            }
            case 0:
                cout << "Voltando ao menu principal..." << endl;
                break;
            default:
                cout << "Opção inválida!" << endl;
        }
    } while (opcaoFuncionarios != 0);
}

void gerenciarVendas() {
    int opcaoVendas;
    do {
        menuVendas();
        cin >> opcaoVendas;
        cin.ignore();
        
        switch (opcaoVendas) {
            case 1: {
                if (crudClientes.tamanho() == 0) {
                    cout << "Nenhum cliente cadastrado. Cadastre um cliente primeiro." << endl;
                    break;
                }
                
                if (concessionaria->getTamanhoEstoque() == 0) {
                    cout << "Estoque vazio. Compre carros primeiro." << endl;
                    break;
                }
                
                cout << "\n--- SELECIONAR CLIENTE ---" << endl;
                for (int i = 0; i < crudClientes.tamanho(); i++) {
                    cout << "[" << i << "] " << crudClientes.ler(i)->getNome() << endl;
                }
                cout << "Escolha o cliente: ";
                int indexCliente;
                cin >> indexCliente;
                cin.ignore();
                
                if (indexCliente < 0 || indexCliente >= crudClientes.tamanho()) {
                    cout << "Cliente inválido!" << endl;
                    break;
                }
                
                Cliente* cliente = crudClientes.ler(indexCliente);
                vector<Carro*> carrosVenda;
                vector<int> indicesEstoque;
                
                cout << "\n--- SELECIONAR CARROS ---" << endl;
                concessionaria->exibirEstoque();
                
                char continuar = 's';
                while (continuar == 's' || continuar == 'S') {
                    cout << "Digite o índice do carro: ";
                    int indexCarro;
                    cin >> indexCarro;
                    cin.ignore();
                    
                    if (indexCarro >= 0 && indexCarro < concessionaria->getTamanhoEstoque()) {
                        Carro* carro = concessionaria->getCarroEstoque(indexCarro);
                        if (carro->estaDisponivel()) {
                            carrosVenda.push_back(carro);
                            indicesEstoque.push_back(indexCarro);
                            cout << "Carro adicionado à venda." << endl;
                        } else {
                            cout << "Carro não está disponível!" << endl;
                        }
                    } else {
                        cout << "Índice inválido!" << endl;
                    }
                    
                    cout << "Adicionar outro carro? (s/n): ";
                    cin >> continuar;
                    cin.ignore();
                }
                
                if (carrosVenda.empty()) {
                    cout << "Nenhum carro selecionado." << endl;
                    break;
                }
                
                string metodoPagamento;
                cout << "Método de pagamento: ";
                getline(cin, metodoPagamento);
                
                try {
                    Venda* venda = new Venda(cliente, vendedor1, carrosVenda, metodoPagamento);
                    cliente->adicionarVenda(venda);
                    cout << "Venda registrada! ID: " << venda->getId() << endl;
                    
                    venda->finalizarVenda();
                    float comissaoValor = vendedor1->calcularComissao(venda->getValorTotal());
                    cout << "Comissão do vendedor: R$ " << comissaoValor << endl;
                    
                    
                    crudVendas.criar(venda);
                    
                    cout << "Venda concluída com sucesso!" << endl;
                    
                } catch (ExcecaoCustomizada& e) {
                    cout << "Erro na venda: " << e.what() << endl;
                }

                    // Itera sobre os índices de trás para frente para evitar problemas ao remover
                    for (int i = indicesEstoque.size() - 1; i >= 0; i--) {
                        int index = indicesEstoque[i];
                        concessionaria->venderCarro(index);
                    }

                break;
            }
            case 2:
                cout << "\n--- HISTÓRICO DE VENDAS ---" << endl;
                cout << "Total de vendas realizadas: " << crudVendas.tamanho() << endl;
                break;
            case 3:
                cout << "Voltando ao menu principal..." << endl;
                break;
            default:
                cout << "Opção inválida!" << endl;
        }
    } while (opcaoVendas != 3);
}

 void gerenciarRelatorios() {
    int opcaoRelatorio;
    do {
        
        cout << "\n--- RELATÓRIOS ---" << endl;
        concessionaria->exibirBalanco();
        cout << "\n--- RESUMO ---" << endl;
        cout << "Total de clientes: " << crudClientes.tamanho() << endl;
        cout << "Total de funcionários: " << crudFuncionarios.tamanho() << endl;
        cout << "Total de vendas: " << crudVendas.tamanho() << endl;
        cout << "Carros em estoque: " << concessionaria->getTamanhoEstoque() << endl;
        
        // Adicione uma opção para voltar ao menu principal
        cout << "\nDigite 0 para voltar ao menu principal: ";
        cin >> opcaoRelatorio;
        cin.ignore();

        if (opcaoRelatorio != 0) {
            cout << "Opção inválida!" << endl;
        }

    } while (opcaoRelatorio != 0);
    
    cout << "Voltando ao menu principal..." << endl;
}