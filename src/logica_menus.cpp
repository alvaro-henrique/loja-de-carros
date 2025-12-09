#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <limits>
#include <algorithm>
#include "logica_menus.h"
#include "include.h"


using namespace std;


void gerenciarEstoque(Concessionaria* concessionaria) {
    int opcaoEstoque;
    do {
        menuEstoque();
        
        try {
            cin >> opcaoEstoque;
            cin.ignore();

            // Se a leitura falhar, lança exceção
            if (cin.fail()) {
                throw runtime_error("Entrada inválida! Digite apenas números de 1 a 4.");
            }
            
            switch (opcaoEstoque) {
                case 1: {
                    string placa, modelo, cor, marca;
                    int ano;
                    float precoCompra, precoVenda;
                    
                    cout << "\n--- COMPRAR CARRO ---" << endl;
                    
                    // Loop para placa válida
                    while (true) {
                        cout << "Placa: ";
                        getline(cin, placa);

                        bool placaValida = (placa.size() == 7);
                        if (placaValida) {
                            for (char c : placa) {
                                if (!isalnum(static_cast<unsigned char>(c))) {
                                    placaValida = false;
                                    break;
                                }
                            }
                        }

                        if (!placaValida) {
                            cout << "❌ Placa inválida! Digite exatamente 7 letras ou números.\n";
                        } else {
                            break;
                        }
                    }
                    
                    cout << "Modelo: ";
                    getline(cin, modelo);
                    cout << "Cor: ";
                    getline(cin, cor);
                    cout << "Marca: ";
                    getline(cin, marca);
                    
                    // Validação segura para ano
                    while (true) {
                        cout << "Ano: ";
                        cin >> ano;
                        if (cin.fail() || ano < 1900 || ano > 2100) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "❌ Ano inválido! Digite um ano entre 1900 e 2100.\n";
                        } else {
                            break;
                        }
                    }
                    
                    // Validação segura para preço de compra
                    while (true) {
                        cout << "Preço de Compra: R$ ";
                        cin >> precoCompra;
                        if (cin.fail() || precoCompra <= 0) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "❌ Preço inválido! Digite um valor positivo.\n";
                        } else {
                            break;
                        }
                    }
                    
                    // Validação segura para preço de venda
                    while (true) {
                        cout << "Preço de Venda: R$ ";
                        cin >> precoVenda;
                        if (cin.fail() || precoVenda <= 0) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "❌ Preço inválido! Digite um valor positivo.\n";
                        } else {
                            break;
                        }
                    }
                    
                    cin.ignore();
                    
                    try {
                        Carro* novoCarro = new Carro(placa, modelo, cor, marca, ano, precoCompra, precoVenda);
                        concessionaria->comprarCarro(novoCarro);
                        cout << "✅ Carro comprado com sucesso!" << endl;
                    } 
                    catch (ExcecaoCustomizada& e) {
                        cout << "❌ Erro: " << e.what() << endl;
                    }
                    catch (bad_alloc& e) {
                        cout << "❌ Erro de memória: Não foi possível alocar o carro." << endl;
                    }
                    catch (exception& e) {
                        cout << "❌ Erro inesperado: " << e.what() << endl;
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
                    throw runtime_error("Opção inválida! Digite um número entre 1 e 4.");
            }
            
        } catch (const exception& e) {
            cout << "Erro: " << e.what() << endl;
            
            // Limpa o estado de erro e o buffer
            cin.clear();
            cin.get();
        }
        
    } while (opcaoEstoque != 4);
}

void gerenciarClientes() {
    int opcaoClientes;
    do {
        menuClientes();
        
        try {
            cin >> opcaoClientes;
            cin.ignore();

            // Se a leitura falhar, lança exceção
            if (cin.fail()) {
                throw runtime_error("Entrada inválida! Digite apenas números de 1 a 4.");
            }
            
                        switch (opcaoClientes) {
            
                            case 1: {
            
                                string cpf, nome, telefone, email, rua, bairro, cidade, estado;
            
                                int idade, numero;
            
                                
            
                                cout << "\n--- CADASTRAR CLIENTE ---" << endl;
            
                                
            
                                // Validação de CPF
            
                                while (true) {
            
                                    cout << "CPF (apenas números): ";
            
                                    getline(cin, cpf);
            
                                    
            
                                    // Remove caracteres não numéricos
            
                                    cpf.erase(remove_if(cpf.begin(), cpf.end(), 
            
                                            [](char c) { return !isdigit(c); }), cpf.end());
            
                                    
            
                                    if (cpf.empty() || cpf.length() != 11) {
            
                                        cout << "❌ CPF inválido! Deve conter 11 dígitos.\n";
            
                                    } else {
            
                                        break;
            
                                    }
            
                                }
            
                                
            
                                // Validação de nome
            
                                while (true) {
            
                                    cout << "Nome: ";
            
                                    getline(cin, nome);
            
                                    
            
                                    if (nome.empty()) {
            
                                        cout << "❌ Nome é obrigatório!\n";
            
                                    } else if (nome.length() < 2) {
            
                                        cout << "❌ Nome muito curto!\n";
            
                                    } else {
            
                                        break;
            
                                    }
            
                                }
            
                                
            
                                // Validação de idade
            
                                while (true) {
            
                                    cout << "Idade: ";
            
                                    cin >> idade;
            
                                    
            
                                    if (cin.fail() || idade < 0 || idade > 120) {
            
                                        cin.clear();
            
                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
                                        cout << "❌ Idade inválida! Digite um valor entre 0 e 120.\n";
            
                                    } else {
            
                                        cin.ignore();
            
                                        break;
            
                                    }
            
                                }
            
                                
            
                                // Validação de telefone
            
                                while (true) {
            
                                    cout << "Telefone: ";
            
                                    getline(cin, telefone);
            
                                    
            
                                    // Remove caracteres não numéricos, mantendo + se presente
            
                                    string telefoneLimpo;
            
                                    for (char c : telefone) {
            
                                        if (isdigit(c) || c == '+') {
            
                                            telefoneLimpo += c;
            
                                        }
            
                                    }
            
                                    
            
                                    if (telefoneLimpo.empty() || telefoneLimpo.length() < 10) {
            
                                        cout << "❌ Telefone inválido! Deve conter pelo menos 10 dígitos.\n";
            
                                    } else {
            
                                        telefone = telefoneLimpo;
            
                                        break;
            
                                    }
            
                                }
            
                                
            
                                // Validação de email
            
                                while (true) {
            
                                    cout << "Email: ";
            
                                    getline(cin, email);
            
                                    
            
                                    if (email.empty()) {
            
                                        cout << "❌ Email é obrigatório!\n";
            
                                    } else if (email.find('@') == string::npos || email.find('.') == string::npos) {
            
                                        cout << "❌ Email inválido! Deve conter '@' e '.'\n";
            
                                    } else {
            
                                        break;
            
                                    }
            
                                }
            
                                
            
                                cout << "\n--- ENDEREÇO ---" << endl;
            
                                
            
                                // Validação de rua
            
                                while (true) {
            
                                    cout << "Rua: ";
            
                                    getline(cin, rua);
            
                                    
            
                                    if (rua.empty()) {
            
                                        cout << "❌ Rua é obrigatória!\n";
            
                                    } else {
            
                                        break;
            
                                    }
            
                                }
            
                                
            
                                // Validação de número
            
                                while (true) {
            
                                    cout << "Número: ";
            
                                    cin >> numero;
            
                                    
            
                                    if (cin.fail() || numero <= 0) {
            
                                        cin.clear();
            
                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
                                        cout << "❌ Número inválido! Digite um valor positivo.\n";
            
                                    } else {
            
                                        cin.ignore();
            
                                        break;
            
                                    }
            
                                }
            
                                
            
                                // Validação de bairro
            
                                while (true) {
            
                                    cout << "Bairro: ";
            
                                    getline(cin, bairro);
            
                                    
            
                                    if (bairro.empty()) {
            
                                        cout << "❌ Bairro é obrigatório!\n";
            
                                    } else {
            
                                        break;
            
                                    }
            
                                }
            
                                
            
                                // Validação de cidade
            
                                while (true) {
            
                                    cout << "Cidade: ";
            
                                    getline(cin, cidade);
            
                                    
            
                                    if (cidade.empty()) {
            
                                        cout << "❌ Cidade é obrigatória!\n";
            
                                    } else {
            
                                        break;
            
                                    }
            
                                }
            
                                
            
                                // Validação de estado
            
                                while (true) {
            
                                    cout << "Estado (sigla): ";
            
                                    getline(cin, estado);
            
                                    
            
                                    // Converte para maiúsculas
            
                                    transform(estado.begin(), estado.end(), estado.begin(), ::toupper);
            
                                    
            
                                    if (estado.empty() || estado.length() != 2) {
            
                                        cout << "❌ Estado inválido! Digite a sigla (2 letras).\n";
            
                                    } else {
            
                                        break;
            
                                    }
            
                                }
            
                                
            
                                try {
            
                                    Endereco* endereco = new Endereco(rua, numero, bairro, cidade, estado);
            
                                    Cliente* novoCliente = new Cliente(cpf, nome, idade, telefone, email, endereco);
            
                                    crudClientes.criar(novoCliente);
            
                                    cout << "✅ Cliente cadastrado com sucesso!" << endl;
            
                                    
            
                                } catch (ExcecaoCustomizada& e) {
            
                                    cout << "❌ Erro: " << e.what() << endl;
            
                                    // Limpeza de memória em caso de erro
            
                                    // delete endereco; // Descomente se necessário
            
                                    // delete novoCliente; // Descomente se necessário
            
                                } catch (bad_alloc& e) {
            
                                    cout << "❌ Erro de memória: Não foi possível cadastrar o cliente." << endl;
            
                                } catch (exception& e) {
            
                                    cout << "❌ Erro inesperado: " << e.what() << endl;
            
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
            
                            case 4: {
            
                                if (crudClientes.tamanho() == 0) {
            
                                    cout << "Nenhum cliente cadastrado." << endl;
            
                                    break;
            
                                }
            
            
            
                                cout << "\n--- ATUALIZAR CLIENTE ---" << endl;
            
                                for (int i = 0; i < crudClientes.tamanho(); i++) {
            
                                    cout << "[" << i << "] " << crudClientes.ler(i)->getNome() << endl;
            
                                }
            
                                cout << "Escolha o índice do cliente: ";
            
                                int idx;
            
                                cin >> idx;
            
                                cin.ignore();
            
            
            
                                if (idx < 0 || idx >= crudClientes.tamanho()) {
            
                                    cout << "Índice inválido!" << endl;
            
                                    break;
            
                                }
            
            
            
                                Cliente* cliente = crudClientes.ler(idx);
            
                                int opcao;
            
                                do {
            
                                    menu_alterar_cliente();
            
                                    cin >> opcao;
            
                                    cin.ignore();
            
            
            
                                    switch (opcao) {
            
                                        case 1: {
            
                                            string nome;
            
                                            cout << "Novo nome: ";
            
                                            getline(cin, nome);
            
                                            cliente->setNome(nome);
            
                                            break;
            
                                        }
            
                                        case 2: {
            
                                            int idade;
            
                                            cout << "Nova idade: ";
            
                                            cin >> idade;
            
                                            cin.ignore();
            
                                            cliente->setIdade(idade);
            
                                            break;
            
                                        }
            
                                        case 3: {
            
                                            string telefone;
            
                                            cout << "Novo telefone: ";
            
                                            getline(cin, telefone);
            
                                            cliente->setTelefone(telefone);
            
                                            break;
            
                                        }
            
                                        case 4: {
            
                                            string email;
            
                                            cout << "Novo email: ";
            
                                            getline(cin, email);
            
                                            cliente->setEmail(email);
            
                                            break;
            
                                        }
            
                                        case 5: {
            
                                            string rua, bairro, cidade, estado;
            
                                            int numero;
            
                                            cout << "\n--- NOVO ENDEREÇO ---" << endl;
            
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
            
                                            cliente->getEndereco()->setRua(rua);
            
                                            cliente->getEndereco()->setNumero(numero);
            
                                            cliente->getEndereco()->setBairro(bairro);
            
                                            cliente->getEndereco()->setCidade(cidade);
            
                                            cliente->getEndereco()->setEstado(estado);
            
                                            break;
            
                                        }
            
                                        case 0:
            
                                            cout << "Voltando ao menu de clientes..." << endl;
            
                                            break;
            
                                        default:
            
                                            cout << "Opção inválida!" << endl;
            
                                    }
            
                                } while (opcao != 0);
            
                                break;
            
                            }
            
                            case 5:
            
                                cout << "Voltando ao menu principal..." << endl;
            
                                break;
            
                            default:
            
                                throw runtime_error("Opção inválida! Digite um número entre 1 e 5.");
            
                        }
            
                        
            
                    } catch (const exception& e) {
            
                        cout << "Erro: " << e.what() << endl;
            
                        
            
                        // Limpa o estado de erro e o buffer
            
                        cin.clear();
            
                        cin.get();
            
                    }
            
                    
            
                } while (opcaoClientes != 5);
}

void gerenciarFuncionarios() {
    int opcaoFuncionarios;
    do {
        menuFuncionarios();
        
        try {
            cin >> opcaoFuncionarios;
            cin.ignore();

            // Se a leitura falhar, lança exceção
            if (cin.fail()) {
                throw runtime_error("Entrada inválida! Digite apenas números de 0 a 4.");
            }

            switch (opcaoFuncionarios) {
                case 1: {
                    // Cadastrar funcionário
                    string cpf, nome, telefone, email, rua, bairro, cidade, estado, tema, nomeExibicao;
                    int idade, numero, codigo;
                    float salario;

                    cout << "\n--- CADASTRAR FUNCIONÁRIO ---" << endl;
                    cout << "CPF: ";
                    getline(cin, cpf);
                    cout << "Nome: ";
                    getline(cin, nome);

                    cout << "Nome de Exibição (opcional, Enter para pular): ";
                    getline(cin, nomeExibicao);

                    cout << "Idade: ";
                    cin >> idade;
                    cin.ignore();

                    cout << "Telefone: ";
                    getline(cin, telefone);
                    cout << "Email: ";
                    getline(cin, email);

                    cout << "Tema (opcional, Enter para pular): ";
                    getline(cin, tema);

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
                        Funcionario* novo = nullptr;
            
                        // DIFERENÇA AQUI: Verifica se os campos estão vazios
                        if (tema.empty() && nomeExibicao.empty()) {
                            // Se ambos vazios, usa construtor sem os últimos parâmetros
                            novo = new Funcionario(cpf, nome, idade, telefone, email, 
                                                endereco, codigo, salario);
                        } 
                        else if (tema.empty()) {
                            // Só nomeExibicao foi preenchido
                            novo = new Funcionario(cpf, nome, idade, telefone, email, 
                                                endereco, codigo, salario,
                                                "", nomeExibicao);  // Tema vazio, nomeExibicao preenchido
                        }
                        else if (nomeExibicao.empty()) {
                            // Só tema foi preenchido
                            novo = new Funcionario(cpf, nome, idade, telefone, email, 
                                                endereco, codigo, salario,
                                                tema, "");  // Tema preenchido, nomeExibicao vazio
                        }
                        else {
                            // Ambos preenchidos
                            novo = new Funcionario(cpf, nome, idade, telefone, email, 
                                                endereco, codigo, salario,
                                                tema, nomeExibicao);
                        }
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

                    Funcionario* funcionario = crudFuncionarios.ler(idx);
                    int opcao;
                    do {
                        menu_alterar_funcionario();
                        cin >> opcao;
                        cin.ignore();

                        switch (opcao) {
                            case 1: {
                                string nome;
                                cout << "Novo nome: ";
                                getline(cin, nome);
                                funcionario->setNome(nome);
                                break;
                            }
                            case 2: {
                                int idade;
                                cout << "Nova idade: ";
                                cin >> idade;
                                cin.ignore();
                                funcionario->setIdade(idade);
                                break;
                            }
                            case 3: {
                                string telefone;
                                cout << "Novo telefone: ";
                                getline(cin, telefone);
                                funcionario->setTelefone(telefone);
                                break;
                            }
                            case 4: {
                                string email;
                                cout << "Novo email: ";
                                getline(cin, email);
                                funcionario->setEmail(email);
                                break;
                            }
                            case 5: {
                                string rua, bairro, cidade, estado;
                                int numero;
                                cout << "\n--- NOVO ENDEREÇO ---" << endl;
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
                                funcionario->getEndereco()->setRua(rua);
                                funcionario->getEndereco()->setNumero(numero);
                                funcionario->getEndereco()->setBairro(bairro);
                                funcionario->getEndereco()->setCidade(cidade);
                                funcionario->getEndereco()->setEstado(estado);
                                break;
                            }
                            case 6: {
                                float salario;
                                cout << "Novo salário: R$ ";
                                cin >> salario;
                                cin.ignore();
                                funcionario->setSalario(salario);
                                break;
                            }
                            case 7: {
                                int codigo;
                                cout << "Novo código: ";
                                cin >> codigo;
                                cin.ignore();
                                funcionario->setCodigo(codigo);
                                break;
                            }
                            case 8: {
                                string tema;
                                cout << "Novo tema: ";
                                getline(cin, tema);
                                funcionario->setTema(tema);
                                break;
                            }
                            case 9: {
                                string nomeExibicao;
                                cout << "Novo nome de exibição: ";
                                getline(cin, nomeExibicao);
                                funcionario->setNomeExibicao(nomeExibicao);
                                break;
                            }
                            case 0:
                                cout << "Voltando ao menu de funcionários..." << endl;
                                break;
                            default:
                                cout << "Opção inválida!" << endl;
                        }
                    } while (opcao != 0);
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
                    throw runtime_error("Opção inválida! Digite um número entre 0 e 4.");
            }
            
        } catch (const exception& e) {
            cout << "Erro: " << e.what() << endl;
            
            // Limpa o estado de erro e o buffer
            cin.clear();
            cin.get();
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
                
                if (crudFuncionarios.tamanho() == 0) {
                    cout << "Nenhum funcionário cadastrado. Cadastre um funcionário primeiro." << endl;
                    break;
                }

                vector<Vendedor*> vendedores;
                for (int i = 0; i < crudFuncionarios.tamanho(); i++) {
                    Funcionario* f = crudFuncionarios.ler(i);
                    Vendedor* v = dynamic_cast<Vendedor*>(f);
                    if (v) {
                        vendedores.push_back(v);
                    }
                }

                if (vendedores.empty()) {
                    cout << "Nenhum vendedor cadastrado. Cadastre um vendedor primeiro." << endl;
                    break;
                }

                cout << "\n--- SELECIONAR VENDEDOR ---" << endl;
                for (int i = 0; i < static_cast<int>(vendedores.size()); i++) {
                    cout << "[" << i << "] " << vendedores[i]->getNome() << endl;
                }
                cout << "Escolha o vendedor: ";
                int indexVendedor;
                cin >> indexVendedor;
                cin.ignore();

                if (indexVendedor < 0 || indexVendedor >= static_cast<int>(vendedores.size())) {
                    cout << "Vendedor inválido!" << endl;
                    break;
                }

                Vendedor* vendedorSelecionado = vendedores[indexVendedor];


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

                        bool carroJaAdicionado = false;
                        for (Carro* c : carrosVenda) {
                            if (c == carro) {
                                carroJaAdicionado = true;
                                break;
                            }
                        }

                        if (carroJaAdicionado) {
                            cout << "❌ Este carro já foi adicionado à venda." << endl;
                        } else if (carro->estaDisponivel()) {
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
                    Venda* venda = new Venda(cliente, vendedorSelecionado, carrosVenda, metodoPagamento);
                    cliente->adicionarVenda(venda);
                    cout << "Venda registrada! ID: " << venda->getId() << endl;
                    
                    venda->finalizarVenda();
                    float comissaoValor = vendedorSelecionado->calcularComissao(venda->getValorTotal());
                    cout << "Comissão do vendedor: R$ " << comissaoValor << endl;
                    
                    
                    crudVendas.criar(venda);
                    
                    // Itera sobre os índices de trás para frente para evitar problemas ao remover
                    float comissaoPorCarro = comissaoValor / carrosVenda.size();
                    for (int i = indicesEstoque.size() - 1; i >= 0; i--) {
                        int index = indicesEstoque[i];
                        concessionaria->venderCarro(index, comissaoPorCarro);
                    }
                    
                    cout << "Venda concluída com sucesso!" << endl;
                    
                } catch (ExcecaoCustomizada& e) {
                    cout << "Erro na venda: " << e.what() << endl;
                }
                break;
            }
            case 2:
                cout << "\n--- HISTÓRICO DE VENDAS ---" << endl;
                if (crudVendas.tamanho() == 0) {
                    cout << "Nenhuma venda registrada." << endl;
                } else {
                    for (int i = 0; i < crudVendas.tamanho(); i++) {
                        Venda* venda = crudVendas.ler(i);
                        cout << "--- Venda " << venda->getId() << " ---" << endl;
                        cout << "Data: " << venda->getData() << endl;
                        cout << "Cliente: " << venda->getCliente()->getNome() << endl;
                        cout << "Carros:" << endl;
                        vector<Carro*> carros = venda->getCarros();
                        for (Carro* carro : carros) {
                            cout << "  - Modelo: " << carro->getModelo() << endl;
                        }
                        cout << "Valor Total: R$ " << venda->getValorTotal() << endl;
                        cout << "--------------------" << endl;
                    }
                }
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
        
        try {
            cin >> opcaoRelatorio;
            cin.ignore();

            // Se a leitura falhar, lança exceção
            if (cin.fail()) {
                throw runtime_error("Entrada inválida! Digite apenas números.");
            }

            if (opcaoRelatorio != 0) {
                throw runtime_error("Opção inválida! Digite 0 para voltar.");
            }

        } catch (const exception& e) {
            cout << "Erro: " << e.what() << endl;
            
            // Limpa o estado de erro e o buffer
            cin.clear();
            cin.get();
        }

    } while (opcaoRelatorio != 0);
    
    cout << "Voltando ao menu principal..." << endl;
}

void gerenciarPreferenciaUsuario() {
    int opcaoPreferencias;

    do {
        menuPreferenciaUsuario();
        try {
            cin >> opcaoPreferencias;
            cin.ignore();

            // Se a leitura falhar, lança exceção
            if (cin.fail()) {
                throw runtime_error("Entrada inválida! Digite apenas números de 1 a 4.");
            }

            switch (opcaoPreferencias) {
                case 1: {
                    // Listar preferencias
                    //Ler csv funcionarios e listar cada funcionario e seu tema e nome de exibicao
                    cout << "listando preferencias..." << endl;
                    break;
                }
                case 2: {
                    // alterar tema 
                    // logica escolher black ou white
                    // gravar escolha no csv
                    cout << "listando tema..." << endl;

                    break;
                }
                case 3: {
                    // alterar nome exibicao
                    // logica recolher nome e gravar no csv
                    cout << "listando nome..." << endl;

                    break;
                }
                case 4:
                    cout << "Voltando ao menu principal..." << endl;
                    break;
                default:
                    throw runtime_error("Opção inválida! Digite um número entre 1 e 4.");
            }
            
        } catch (const exception& e) {
            cout << "Erro: " << e.what() << endl;
            
            // Limpa o estado de erro e o buffer
            cin.clear();
            cin.get();
        }

    } while (opcaoPreferencias != 4);
}
