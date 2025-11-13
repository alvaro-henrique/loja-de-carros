#include "globals.h"

// Definições (sem extern) — uma única vez no projeto
CRUD<Cliente> crudClientes;
CRUD<Funcionario> crudFuncionarios;
CRUD<Venda> crudVendas;
Concessionaria* concessionaria = nullptr;
Vendedor* vendedor1 = nullptr;