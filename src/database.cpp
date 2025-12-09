#include "database.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <ctime>
#include "formatacaoreal.h"
#include <sys/stat.h> // Para verificar diretórios

using namespace std;

// Definição dos caminhos
const string ExportarDataBase::CAMINHO_DATABASE = "database/";
const string ExportarDataBase::CAMINHO_FUNCIONARIOS = CAMINHO_DATABASE + "funcionarios.csv";
const string ExportarDataBase::CAMINHO_CONCESSIONARIA = CAMINHO_DATABASE + "concessionaria.csv";

// Exporta funcionários para CSV

// Função para verificar e criar pasta database
bool ExportarDataBase::verificarPastaDatabase() {
    struct stat info;
    
    // Verifica se a pasta existe
    if (stat(CAMINHO_DATABASE.c_str(), &info) != 0) {
        // Pasta não existe, tenta criar
        #ifdef _WIN32
            int resultado = system(("mkdir " + CAMINHO_DATABASE).c_str());
        #else
            int resultado = system(("mkdir -p " + CAMINHO_DATABASE).c_str());
        #endif
        
        if (resultado != 0) {
            cerr << "Erro ao criar pasta database!" << endl;
            return false;
        }
        cout << "Pasta 'database' criada com sucesso!" << endl;
        return true;
    } 
    else if (info.st_mode & S_IFDIR) {
        // Pasta já existe
        return true;
    }
    
    return false;
}

// Função auxiliar para dividir strings CSV
vector<string> ExportarDataBase::splitCSV(const string& linha, char delimitador) {
    vector<string> tokens;
    string token;
    bool dentroDeAspas = false;
    
    for (char c : linha) {
        if (c == '"') {
            dentroDeAspas = !dentroDeAspas;
        } 
        else if (c == delimitador && !dentroDeAspas) {
            // Remove aspas do token
            if (!token.empty() && token.front() == '"' && token.back() == '"') {
                token = token.substr(1, token.length() - 2);
            }
            tokens.push_back(token);
            token.clear();
        } 
        else {
            token += c;
        }
    }
    
    // Último token
    if (!token.empty() && token.front() == '"' && token.back() == '"') {
        token = token.substr(1, token.length() - 2);
    }
    tokens.push_back(token);
    
    return tokens;
}

// Exporta funcionários para CSV na pasta database
bool ExportarDataBase::exportarFuncionariosCSV(CRUD<Funcionario>& crudFuncionarios) {
    try {
        // Verifica se a pasta existe
        if (!verificarPastaDatabase()) {
            throw ExcecaoPastaDatabase();
        }
        
        ofstream arquivo(CAMINHO_FUNCIONARIOS);
        
        if (!arquivo.is_open()) {
            throw ExcecaoArquivo(CAMINHO_FUNCIONARIOS, "abertura");
        }
        
        // Cabeçalho do CSV
        arquivo << "CPF;Nome;Idade;Telefone;Email;Endereco_Rua;Endereco_Numero;Endereco_Bairro;Endereco_Cidade;Endereco_Estado;Codigo;Salario;Tema;NomeExibicao;Comissao;Tipo" << endl;
        
        // Dados dos funcionários
        vector<Funcionario*> funcionarios = crudFuncionarios.lerTodos();
        
        for (Funcionario* func : funcionarios) {
            Endereco* endereco = func->getEndereco();
            
            arquivo << func->getCPF() << ";"
                    << func->getNome() << ";"
                    << func->getIdade() << ";"
                    << func->getTelefone() << ";"
                    << func->getEmail() << ";"
                    << endereco->getRua() << ";"
                    << endereco->getNumero() << ";"
                    << endereco->getBairro() << ";"
                    << endereco->getCidade() << ";"
                    << endereco->getEstado() << ";"
                    << func->getCodigo() << ";"
                    << fixed << setprecision(2) << func->getSalario() << ";"
                    << func->getTema() << ";"
                    << func->getNomeExibicao() << ";";
            
            // Identifica se é Vendedor ou Funcionário comum
            Vendedor* vendedor = dynamic_cast<Vendedor*>(func);
            if (vendedor) {
                arquivo << fixed << setprecision(3) << vendedor->getComissao() << ";"
                        << "Vendedor";
            } else {
                arquivo << "0.000;" << "Funcionario";
            }
            
            arquivo << endl;
        }
        
        arquivo.close();
        cout << "Funcionários exportados para " << CAMINHO_FUNCIONARIOS << " com sucesso!" << endl;
        cout << "Total de funcionários exportados: " << funcionarios.size() << endl;
        
        return true;
    }
    catch (const exception& e) {
        cerr << "Erro ao exportar funcionários: " << e.what() << endl;
        return false;
    }
}

// Exporta concessionária para CSV na pasta database
bool ExportarDataBase::exportarConcessionariaCSV(Concessionaria* concessionaria) {
    try {
        // Verifica se a pasta existe
        if (!verificarPastaDatabase()) {
            throw ExcecaoPastaDatabase();
        }
        
        ofstream arquivo(CAMINHO_CONCESSIONARIA);
        
        if (!arquivo.is_open()) {
            throw ExcecaoArquivo(CAMINHO_CONCESSIONARIA, "abertura");
        }
        
        // Obter data atual
        time_t now = time(0);
        tm* dataAtual = localtime(&now);
        string dataExportacao = to_string(dataAtual->tm_mday) + "/" + 
                                to_string(dataAtual->tm_mon + 1) + "/" + 
                                to_string(dataAtual->tm_year + 1900);
        
        // Informações da concessionária
        arquivo << "=== CONCESSIONARIA ===" << endl;
        arquivo << "DataExportacao;" << dataExportacao << endl;
        arquivo << "Nome;" << concessionaria->getNome() << endl;
        arquivo << "CNPJ;" << concessionaria->getCNPJ() << endl;
        arquivo << "Caixa;" << fixed << setprecision(2) << concessionaria->getCaixa() << endl;
        arquivo << endl;
        
        // Cabeçalho do estoque
        arquivo << "=== ESTOQUE ===" << endl;
        arquivo << "Placa;Marca;Modelo;Ano;Cor;PrecoCompra;PrecoVenda;Status;Lucro" << endl;
        
        // Dados do estoque
        int totalEstoque = concessionaria->getTamanhoEstoque();
        
        for (int i = 0; i < totalEstoque; i++) {
            Carro* carro = concessionaria->getCarroEstoque(i);
            
            arquivo << carro->getPlaca() << ";"
                    << carro->getMarca() << ";"
                    << carro->getModelo() << ";"
                    << carro->getAno() << ";"
                    << carro->getCor() << ";"
                    << fixed << setprecision(2) << carro->getPrecoCompra() << ";"
                    << fixed << setprecision(2) << carro->getPrecoVenda() << ";"
                    << carro->getStatus() << ";"
                    << fixed << setprecision(2) << carro->calcularLucro()
                    << endl;
        }
        
        // Resumo
        arquivo << endl;
        arquivo << "=== RESUMO ===" << endl;
        arquivo << "TotalCarros;" << totalEstoque << endl;
        
        int carrosDisponiveis = 0;
        float totalInvestido = 0;
        float valorTotalVenda = 0;
        
        for (int i = 0; i < totalEstoque; i++) {
            Carro* carro = concessionaria->getCarroEstoque(i);
            
            totalInvestido += carro->getPrecoCompra();
            valorTotalVenda += carro->getPrecoVenda();
            if (carro->estaDisponivel()) {
                carrosDisponiveis++;
            }
        }
        
        arquivo << "CarrosDisponiveis;" << carrosDisponiveis << endl;
        arquivo << "TotalInvestido;" << fixed << setprecision(2) << totalInvestido << endl;
        arquivo << "ValorTotalVenda;" << fixed << setprecision(2) << valorTotalVenda << endl;
        arquivo << "LucroPotencial;" << fixed << setprecision(2) << (valorTotalVenda - totalInvestido) << endl;
        
        arquivo.close();
        cout << "Dados da concessionária exportados para " << CAMINHO_CONCESSIONARIA << " com sucesso!" << endl;
        
        return true;
    }
    catch (const exception& e) {
        cerr << "Erro ao exportar dados da concessionária: " << e.what() << endl;
        return false;
    }
}

// Importa funcionários do CSV
bool ExportarDataBase::importarFuncionariosCSV(CRUD<Funcionario>& crudFuncionarios) {
    try {
        ifstream arquivo(CAMINHO_FUNCIONARIOS);
        
        if (!arquivo.is_open()) {
            cout << "Arquivo " << CAMINHO_FUNCIONARIOS << " não encontrado." << endl;
            return false;
        }
        
        string linha;
        int linhaNum = 0;
        int funcionariosImportados = 0;
        
        // Limpa os funcionários existentes
        while (crudFuncionarios.tamanho() > 0) {
            crudFuncionarios.remover(0);
        }
        
        while (getline(arquivo, linha)) {
            linhaNum++;
            
            // Pula cabeçalho
            if (linhaNum == 1) continue;
            
            // Pula linhas vazias
            if (linha.empty()) continue;
            
            // Divide a linha
            vector<string> campos = splitCSV(linha, ';');
            
            // Verifica número de campos
            if (campos.size() < 15) {
                cerr << "Linha " << linhaNum << " inválida: campos insuficientes" << endl;
                continue;
            }
            
            try {
                // Extrai dados
                string cpf = campos[0];
                string nome = campos[1];
                int idade = stoi(campos[2]);
                string telefone = campos[3];
                string email = campos[4];
                
                // Cria endereço
                Endereco* endereco = new Endereco(
                    campos[5],                   // rua
                    stoi(campos[6]),            // numero
                    campos[7],                   // bairro
                    campos[8],                   // cidade
                    campos[9]                    // estado
                );
                
                int codigo = stoi(campos[10]);
                float salario = stof(campos[11]);
                string tema = campos[12];
                string nomeExibicao = campos[13];
                float comissao = stof(campos[14]);
                string tipo = campos[15];
                
                // Cria funcionário baseado no tipo
                if (tipo == "Vendedor") {
                    Vendedor* vendedor = new Vendedor(
                        cpf, nome, idade, telefone, email, endereco,
                        codigo, salario, comissao, tema, nomeExibicao
                    );
                    crudFuncionarios.criar(vendedor);
                } else {
                    Funcionario* funcionario = new Funcionario(
                        cpf, nome, idade, telefone, email, endereco,
                        codigo, salario, tema, nomeExibicao
                    );
                    crudFuncionarios.criar(funcionario);
                }
                
                funcionariosImportados++;
                
            } catch (const exception& e) {
                cerr << "Erro ao processar linha " << linhaNum << ": " << e.what() << endl;
                continue;
            }
        }
        
        arquivo.close();
        cout << "Funcionários importados com sucesso!" << endl;
        cout << "Total de funcionários importados: " << funcionariosImportados << endl;
        
        return true;
    }
    catch (const exception& e) {
        cerr << "Erro ao importar funcionários: " << e.what() << endl;
        return false;
    }
}

// Importa concessionária do CSV
bool ExportarDataBase::importarConcessionariaCSV(Concessionaria*& concessionaria, CRUD<Funcionario>& crudFuncionarios) {
    try {
        ifstream arquivo(CAMINHO_CONCESSIONARIA);
        
        if (!arquivo.is_open()) {
            cout << "Arquivo " << CAMINHO_CONCESSIONARIA << " não encontrado. Criando nova concessionária..." << endl;
            return false;
        }
        
        string linha;
        string nome = "", cnpj = "";
        float caixa = 0.0f;
        bool lendoEstoque = false;
        int estoqueImportado = 0;
        
        // Se já existe uma concessionária, deleta para criar nova
        if (concessionaria != nullptr) {
            delete concessionaria;
            concessionaria = nullptr;
        }
        
        while (getline(arquivo, linha)) {
            // Pula linhas vazias
            if (linha.empty()) continue;
            
            // Verifica seções
            if (linha.find("=== CONCESSIONARIA ===") != string::npos) {
                continue;
            }
            else if (linha.find("=== ESTOQUE ===") != string::npos) {
                lendoEstoque = true;
                // Pula cabeçalho do estoque
                getline(arquivo, linha);
                continue;
            }
            else if (linha.find("=== RESUMO ===") != string::npos) {
                lendoEstoque = false;
                continue;
            }
            
            if (!lendoEstoque) {
                // Lê informações da concessionária
                vector<string> campos = splitCSV(linha, ';');
                
                if (campos.size() >= 2) {
                    string chave = campos[0];
                    string valor = campos[1];
                    
                    if (chave == "Nome") {
                        nome = valor;
                    } 
                    else if (chave == "CNPJ") {
                        cnpj = valor;
                    } 
                    else if (chave == "Caixa") {
                        caixa = stof(valor);
                    }
                }
            } 
            else {
                // Lê dados do estoque
                vector<string> campos = splitCSV(linha, ';');
                
                if (campos.size() >= 8) {
                    // Cria carro
                    Carro* carro = new Carro(
                        campos[0],               // placa
                        campos[2],               // modelo
                        campos[4],               // cor
                        campos[1],               // marca
                        stoi(campos[3]),         // ano
                        stof(campos[5]),         // precoCompra
                        stof(campos[6]),         // precoVenda
                        campos[7]                // status
                    );
                    
                    // Adiciona à concessionária
                    if (concessionaria == nullptr && !nome.empty()) {
                        concessionaria = new Concessionaria(nome, cnpj, caixa);
                    }
                    
                    if (concessionaria != nullptr) {
                        try {
                            concessionaria->comprarCarro(carro);
                            estoqueImportado++;
                        } catch (const exception& e) {
                            cerr << "Erro ao adicionar carro ao estoque: " << e.what() << endl;
                            delete carro;
                        }
                    } else {
                        delete carro;
                    }
                }
            }
        }
        
        arquivo.close();
        
        if (concessionaria == nullptr && !nome.empty()) {
            concessionaria = new Concessionaria(nome, cnpj, caixa);
            cout << "Concessionária criada com dados importados!" << endl;
        }
        
        cout << "Concessionária importada com sucesso!" << endl;
        cout << "Nome: " << nome << " | CNPJ: " << cnpj << " | Caixa: " << formatarReal(caixa) << endl;
        cout << "Carros no estoque: " << estoqueImportado << endl;
        
        return true;
    }
    catch (const exception& e) {
        cerr << "Erro ao importar concessionária: " << e.what() << endl;
        return false;
    }
}