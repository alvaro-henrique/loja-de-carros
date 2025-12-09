#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <limits>
#include <algorithm>
#include "logica_menus.h"
#include "include.h"

using namespace std;

// ============================================================
// FUNÇÕES AUXILIARES DE VALIDAÇÃO COM VERIFICAÇÃO DE DUPLICADOS
// ============================================================

/**
 * Valida CPF em tempo real (formato + duplicação)
 * @param tipo - "cliente" ou "funcionario"
 */
void validarCPFComDuplicata(string& cpf, const string& tipo) {
    while (true) {
        cout << "🔢 CPF (apenas números): ";
        getline(cin, cpf);
        
        // Remove caracteres não numéricos
        cpf.erase(remove_if(cpf.begin(), cpf.end(), 
                [](char c) { return !isdigit(c); }), cpf.end());
        
        if (cpf.empty() || cpf.length() != 11) {
            cout << "❌ CPF inválido! Deve conter 11 dígitos.\n";
            continue;
        }
        
        // Verifica duplicação
        try {
            if (tipo == "cliente") {
                vector<Cliente*> clientesTemp = crudClientes.lerTodos();
                vector<Pessoa*> clientes(clientesTemp.begin(), clientesTemp.end());
                Pessoa::verificarCPFDuplicado(clientes, cpf);
            } else if (tipo == "funcionario") {
                vector<Funcionario*> funcionariosTemp = crudFuncionarios.lerTodos();
                vector<Pessoa*> funcionarios(funcionariosTemp.begin(), funcionariosTemp.end());
                Pessoa::verificarCPFDuplicado(funcionarios, cpf);
            }
            break; // CPF válido e não duplicado
        } catch (const ExcecaoCPFDuplicado& e) {
            cout << "❌ " << e.what() << endl;
        }
    }
}

/**
 * Valida telefone em tempo real (formato + duplicação)
 */
void validarTelefoneComDuplicata(string& telefone, const string& tipo) {
    while (true) {
        cout << "📱 Telefone: ";
        getline(cin, telefone);
        
        // Remove caracteres não numéricos
        string telefoneLimpo;
        for (char c : telefone) {
            if (isdigit(c) || c == '+') {
                telefoneLimpo += c;
            }
        }
        
        if (telefoneLimpo.empty() || telefoneLimpo.length() < 10) {
            cout << "❌ Telefone inválido! Deve conter pelo menos 10 dígitos.\n";
            continue;
        }
        
        telefone = telefoneLimpo;
        
        // Verifica duplicação
        try {
            if (tipo == "cliente") {
                vector<Cliente*> clientesTemp = crudClientes.lerTodos();
                vector<Pessoa*> clientes(clientesTemp.begin(), clientesTemp.end());
                Pessoa::verificarTelefoneDuplicado(clientes, telefone);
            } else if (tipo == "funcionario") {
                vector<Funcionario*> funcionariosTemp = crudFuncionarios.lerTodos();
                vector<Pessoa*> funcionarios(funcionariosTemp.begin(), funcionariosTemp.end());
                Pessoa::verificarTelefoneDuplicado(funcionarios, telefone);
            }
            break; // Telefone válido e não duplicado
        } catch (const ExcecaoTelefoneDuplicado& e) {
            cout << "❌ " << e.what() << endl;
        }
    }
}

/**
 * Valida email em tempo real (formato + duplicação)
 */
void validarEmailComDuplicata(string& email, const string& tipo) {
    while (true) {
        cout << "📧 Email: ";
        getline(cin, email);
        
        if (email.empty() || email.find('@') == string::npos || email.find('.') == string::npos) {
            cout << "❌ Email inválido! Deve conter '@' e '.'\n";
            continue;
        }
        
        // Verifica duplicação
        try {
            if (tipo == "cliente") {
                vector<Cliente*> clientesTemp = crudClientes.lerTodos();
                vector<Pessoa*> clientes(clientesTemp.begin(), clientesTemp.end());
                Pessoa::verificarEmailDuplicado(clientes, email);
            } else if (tipo == "funcionario") {
                vector<Funcionario*> funcionariosTemp = crudFuncionarios.lerTodos();
                vector<Pessoa*> funcionarios(funcionariosTemp.begin(), funcionariosTemp.end());
                Pessoa::verificarEmailDuplicado(funcionarios, email);
            }
            break; // Email válido e não duplicado
        } catch (const ExcecaoEmailDuplicado& e) {
            cout << "❌ " << e.what() << endl;
        }
    }
}

/**
 * Valida nome em tempo real (4 caracteres + 1 espaço)
 */
void validarNomeCompleto(string& nome) {
    while (true) {
        cout << "👤 Nome: ";
        getline(cin, nome);
        
        if (nome.empty()) {
            cout << "❌ Nome é obrigatório!\n";
            continue;
        }
        
        if (nome.length() < 4) {
            cout << "❌ Nome deve ter no mínimo 4 caracteres!\n";
            continue;
        }
        
        // Verifica se tem pelo menos 1 espaço (nome e sobrenome)
        int espacos = 0;
        for (char c : nome) {
            if (c == ' ') espacos++;
        }
        
        if (espacos < 1) {
            cout << "❌ Nome deve conter nome e sobrenome (mínimo 1 espaço)!\n";
            continue;
        }
        
        break; // Nome válido
    }
}

/**
 * Valida idade em tempo real
 */
void validarIdade(int& idade) {
    while (true) {
        cout << "🎂 Idade: ";
        cin >> idade;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "❌ Idade inválida! Digite um número inteiro.\n";
            continue;
        }
        
        if (idade < 0 || idade > 120) {
            cout << "❌ Idade deve estar entre 0 e 120 anos!\n";
            continue;
        }
        
        cin.ignore();
        break; // Idade válida
    }
}

/**
 * Valida código de funcionário em tempo real
 */
void validarCodigoFuncionario(int& codigo) {
    while (true) {
        cout << "🔢 Código do funcionário: ";
        cin >> codigo;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "❌ Código inválido! Digite um número inteiro positivo.\n";
            continue;
        }
        
        if (codigo <= 0) {
            cout << "❌ Código deve ser um número positivo!\n";
            continue;
        }
        
        cin.ignore();
        break; // Código válido
    }
}

/**
 * Valida salário em tempo real
 */
void validarSalario(float& salario) {
    while (true) {
        cout << "💵 Salário: R$ ";
        cin >> salario;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "❌ Salário inválido! Digite um número decimal.\n";
            continue;
        }
        
        if (salario < 0) {
            cout << "❌ Salário não pode ser negativo!\n";
            continue;
        }
        
        cin.ignore();
        break; // Salário válido
    }
}

/**
 * Valida endereco em tempo real
 */
void validarEnderecoCompleto(string& rua, int& numero, string& bairro, string& cidade, string& estado) {
    // Validação de rua
    while (true) {
        cout << "🏠 Rua: ";
        getline(cin, rua);
        
        if (rua.empty()) {
            cout << "❌ Rua é obrigatória!\n";
        } else {
            break;
        }
    }
    
    // Validação de número
    while (true) {
        cout << "🔢 Número: ";
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
        cout << "📍 Bairro: ";
        getline(cin, bairro);
        
        if (bairro.empty()) {
            cout << "❌ Bairro é obrigatório!\n";
        } else {
            break;
        }
    }
    
    // Validação de cidade
    while (true) {
        cout << "🌆 Cidade: ";
        getline(cin, cidade);
        
        if (cidade.empty()) {
            cout << "❌ Cidade é obrigatória!\n";
        } else {
            break;
        }
    }
    
    // Validação de estado
    while (true) {
        cout << "🏷️ Estado (sigla): ";
        getline(cin, estado);
        
        // Converte para maiúsculas
        transform(estado.begin(), estado.end(), estado.begin(), ::toupper);
        
        if (estado.empty() || estado.length() != 2) {
            cout << "❌ Estado inválido! Digite a sigla (2 letras).\n";
        } else {
            break;
        }
    }
}

/**
 * Valida modelo do carro em tempo real
 */
void validarModelo(string& modelo) {
    while (true) {
        cout << "🚗 Modelo: ";
        getline(cin, modelo);
        
        if (modelo.empty()) {
            cout << "❌ Modelo é obrigatório!\n";
            continue;
        }
        
        if (modelo.length() < 2) {
            cout << "❌ Modelo deve ter no mínimo 2 caracteres!\n";
            continue;
        }
        
        break;
    }
}

/**
 * Valida cor do carro em tempo real
 */
void validarCor(string& cor) {
    while (true) {
        cout << "🎨 Cor: ";
        getline(cin, cor);
        
        if (cor.empty()) {
            cout << "❌ Cor é obrigatória!\n";
            continue;
        }
        
        if (cor.length() < 2) {
            cout << "❌ Cor deve ter no mínimo 2 caracteres!\n";
            continue;
        }
        
        break;
    }
}

/**
 * Valida marca do carro em tempo real
 */
void validarMarca(string& marca) {
    while (true) {
        cout << "🏷️ Marca: ";
        getline(cin, marca);
        
        if (marca.empty()) {
            cout << "❌ Marca é obrigatória!\n";
            continue;
        }
        
        if (marca.length() < 2) {
            cout << "❌ Marca deve ter no mínimo 2 caracteres!\n";
            continue;
        }
        
        break;
    }
}

/**
 * Valida placa em tempo real (formato + duplicação)
 */
void validarPlacaComDuplicata(string& placa) {
    while (true) {
        cout << "🔖 Placa (7 caracteres alfanuméricos): ";
        getline(cin, placa);
        
        // Valida formato (exatamente 7 caracteres alfanuméricos)
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
            continue;
        }
        
        // Verifica duplicação (busca em todo o estoque da concessionária)
        try {
            vector<Carro*> estoque = concessionaria->getEstoque();
            Carro::verificarPlacaDuplicada(estoque, placa);
            break; // Placa válida e não duplicada
        } catch (const ExcecaoPlacaDuplicada& e) {
            cout << "❌ " << e.what() << "\n";
        }
    }
}

/**
 * Valida método de pagamento em tempo real (com opções pré-definidas)
 */
void validarMetodoPagamento(string& metodo) {
    vector<string> metodosValidos = {
        "Dinheiro",
        "Cartão Crédito",
        "Cartão Débito",
        "Cheque",
        "Financiamento"
    };
    
    while (true) {
        cout << "\n--- MÉTODO DE PAGAMENTO ---" << endl;
        for (int i = 0; i < static_cast<int>(metodosValidos.size()); i++) {
            cout << "[" << (i+1) << "] " << metodosValidos[i] << endl;
        }
        
        cout << "Escolha o método (1-" << metodosValidos.size() << "): ";
        int escolha;
        cin >> escolha;
        cin.ignore();
        
        if (escolha < 1 || escolha > static_cast<int>(metodosValidos.size())) {
            cout << "❌ Opção inválida! Escolha entre 1 e " << metodosValidos.size() << "\n";
            continue;
        }
        
        metodo = metodosValidos[escolha - 1];
        break;
    }
}


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
                    
                    // Validação de placa em tempo real (com verificação de duplicata)
                    validarPlacaComDuplicata(placa);
                    
                    // Validação de modelo em tempo real
                    validarModelo(modelo);
                    
                    // Validação de cor em tempo real
                    validarCor(cor);
                    
                    // Validação de marca em tempo real
                    validarMarca(marca);
                    
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
                    
                    // Validação de CPF com verificação de duplicata
                    validarCPFComDuplicata(cpf, "cliente");
                    
                    // Validação de nome (4 caracteres + 1 espaço)
                    validarNomeCompleto(nome);
                    
                    // Validação de idade
                    validarIdade(idade);
                    
                    // Validação de telefone com verificação de duplicata
                    validarTelefoneComDuplicata(telefone, "cliente");
                    
                    // Validação de email com verificação de duplicata
                    validarEmailComDuplicata(email, "cliente");
                    
                    cout << "\n--- ENDEREÇO ---" << endl;
                    validarEnderecoCompleto(rua, numero, bairro, cidade, estado);
                    
                    try {
                        Endereco* endereco = new Endereco(rua, numero, bairro, cidade, estado);
                        Cliente* novoCliente = new Cliente(cpf, nome, idade, telefone, email, endereco);
                        crudClientes.criar(novoCliente);
                        cout << "✅ Cliente cadastrado com sucesso!" << endl;
                        
                    } catch (ExcecaoCustomizada& e) {
                        cout << "❌ Erro: " << e.what() << endl;
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
        
    } while (opcaoClientes != 4);
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
                    
                    // Validação de CPF com verificação de duplicata
                    validarCPFComDuplicata(cpf, "funcionario");
                    
                    // Validação de nome (4 caracteres + 1 espaço)
                    validarNomeCompleto(nome);

                    cout << "Nome de Exibição (opcional, Enter para pular): ";
                    getline(cin, nomeExibicao);

                    // Validação de idade
                    validarIdade(idade);

                    // Validação de telefone com verificação de duplicata
                    validarTelefoneComDuplicata(telefone, "funcionario");
                    
                    // Validação de email com verificação de duplicata
                    validarEmailComDuplicata(email, "funcionario");

                    cout << "Tema (opcional, Enter para pular): ";
                    getline(cin, tema);

                    cout << "\n--- ENDEREÇO ---" << endl;
                    validarEnderecoCompleto(rua, numero, bairro, cidade, estado);

                    // Validação de código
                    validarCodigoFuncionario(codigo);
                    
                    // Validação de salário
                    validarSalario(salario);

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
                        cout << "✅ Funcionário cadastrado com sucesso!" << endl;
                    } catch (ExcecaoCustomizada& e) {
                        cout << "❌ Erro: " << e.what() << endl;
                    } catch (bad_alloc& e) {
                        cout << "❌ Erro de memória: Não foi possível cadastrar o funcionário." << endl;
                    } catch (exception& e) {
                        cout << "❌ Erro inesperado: " << e.what() << endl;
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
                    string cpf, nome, telefone, email, rua, bairro, cidade, estado, tema, nomeExibicao;
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
                validarMetodoPagamento(metodoPagamento);
                
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
