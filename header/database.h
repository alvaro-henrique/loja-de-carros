#ifndef DATABASE_H
#define DATABASE_H

#include <fstream>
#include <vector>
#include <string>
#include "include.h"

class ExportarDataBase {
public:
    // Caminhos dos arquivos
    static const std::string CAMINHO_DATABASE;
    static const std::string CAMINHO_FUNCIONARIOS;
    static const std::string CAMINHO_CONCESSIONARIA;

    // Verifica e cria pasta database se não existir
    static bool verificarPastaDatabase();

    // Exporta funcionários para CSV
    static bool exportarFuncionariosCSV(CRUD<Funcionario>& crudFuncionarios);
    
    // Exporta concessionária (estoque e informações)
    static bool exportarConcessionariaCSV(Concessionaria* concessionaria);

     // Importa funcionários de CSV
    static bool importarFuncionariosCSV(CRUD<Funcionario>& crudFuncionarios);

    // Importa concessionária de CSV (estoque e informações)
    static bool importarConcessionariaCSV(Concessionaria*& concessionaria, CRUD<Funcionario>& crudFuncionarios);

    // Utilitários
    static std::vector<std::string> splitCSV(const std::string& linha, char delimitador = ';');
};

#endif