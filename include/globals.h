#ifndef GLOBALS_H
#define GLOBALS_H

#include "include.h"

// Variáveis globais do sistema

extern CRUD<Cliente> crudClientes;         ///< CRUD global para gerenciar clientes
extern CRUD<Funcionario> crudFuncionarios; ///< CRUD global para gerenciar funcionários
extern CRUD<Venda> crudVendas;             ///< CRUD global para gerenciar vendas
extern Concessionaria* concessionaria;     ///< Ponteiro para a concessionária principal
extern Vendedor* vendedor1;                ///< Ponteiro para um vendedor padrão

#endif