#include "../header/excecoes.h"

/**
 * Arquivo de implementação para exceções customizadas.
 * 
 * Hierarquia de exceções:
 * 
 * ExcecaoCustomizada (base)
 * ├── ExcecaoDadosInvalidos
 * │   ├── ExcecaoCPFInvalido
 * │   ├── ExcecaoIdadeInvalida
 * │   ├── ExcecaoAnoInvalido
 * │   └── ExcecaoPrecoInvalido
 * │       └── ExcecaoSalarioInvalido
 * ├── ExcecaoRecursoNaoEncontrado
 * │   ├── ExcecaoCarroNaoEncontrado
 * │   ├── ExcecaoClienteNaoEncontrado
 * │   ├── ExcecaoFuncionarioNaoEncontrado
 * │   ├── ExcecaoVendaNaoEncontrada
 * │   └── ExcecaoIndiceInvalido
 * ├── ExcecaoOperacaoNaoPossivel
 * │   ├── ExcecaoCaixaInsuficiente
 * │   ├── ExcecaoCarroNaoDisponivel
 * │   └── ExcecaoVendaInvalida
 * └── ExcecaoIO
 *     ├── ExcecaoPastaDatabase
 *     └── ExcecaoArquivo
 */

// ============================================================
// EXCEÇÃO BASE CUSTOMIZADA
// ============================================================

ExcecaoCustomizada::ExcecaoCustomizada(const string& mensagem) 
    : runtime_error(mensagem) {}

// ============================================================
// EXCEÇÕES DE VALIDAÇÃO DE DADOS
// ============================================================

ExcecaoDadosInvalidos::ExcecaoDadosInvalidos(const string& campo) 
    : ExcecaoCustomizada("Dados inválidos - " + campo) {}

ExcecaoCPFInvalido::ExcecaoCPFInvalido(const string& cpf) 
    : ExcecaoDadosInvalidos("CPF inválido: " + cpf) {}

ExcecaoIdadeInvalida::ExcecaoIdadeInvalida(int idade) 
    : ExcecaoDadosInvalidos("Idade não pode ser negativa: " + to_string(idade)) {}

ExcecaoAnoInvalido::ExcecaoAnoInvalido(int ano) 
    : ExcecaoDadosInvalidos("Ano inválido (1900-2030): " + to_string(ano)) {}

ExcecaoPrecoInvalido::ExcecaoPrecoInvalido(float preco, const string& tipo) 
    : ExcecaoDadosInvalidos(tipo + " não pode ser negativo: " + to_string(preco)), 
      valor(preco) {}

ExcecaoSalarioInvalido::ExcecaoSalarioInvalido(float salario) 
    : ExcecaoPrecoInvalido(salario, "Salário") {}

// ============================================================
// EXCEÇÕES DE RECURSO / BANCO DE DADOS
// ============================================================

ExcecaoRecursoNaoEncontrado::ExcecaoRecursoNaoEncontrado(const string& tipo, const string& id) 
    : ExcecaoCustomizada(tipo + " não encontrado" + (id.empty() ? "" : ": " + id)) {}

ExcecaoCarroNaoEncontrado::ExcecaoCarroNaoEncontrado(const string& placa) 
    : ExcecaoRecursoNaoEncontrado("Carro", placa) {}

ExcecaoClienteNaoEncontrado::ExcecaoClienteNaoEncontrado(const string& cpf) 
    : ExcecaoRecursoNaoEncontrado("Cliente", cpf) {}

ExcecaoFuncionarioNaoEncontrado::ExcecaoFuncionarioNaoEncontrado(int codigo) 
    : ExcecaoRecursoNaoEncontrado("Funcionário", to_string(codigo)) {}

ExcecaoVendaNaoEncontrada::ExcecaoVendaNaoEncontrada(int id) 
    : ExcecaoRecursoNaoEncontrado("Venda", to_string(id)) {}

ExcecaoIndiceInvalido::ExcecaoIndiceInvalido(int indice, int tamanho) 
    : ExcecaoRecursoNaoEncontrado("Índice inválido: " + to_string(indice) + 
                                  " (tamanho: " + to_string(tamanho) + ")") {}

// ============================================================
// EXCEÇÕES DE NEGÓCIO / LÓGICA
// ============================================================

ExcecaoOperacaoNaoPossivel::ExcecaoOperacaoNaoPossivel(const string& motivo) 
    : ExcecaoCustomizada("Operação não possível: " + motivo) {}

ExcecaoCaixaInsuficiente::ExcecaoCaixaInsuficiente(float saldo, float necessario) 
    : ExcecaoOperacaoNaoPossivel("Caixa insuficiente (saldo: " + to_string(saldo) + 
                                 ", necessário: " + to_string(necessario) + ")"),
      saldoAtual(saldo), valorNecessario(necessario) {}

ExcecaoCarroNaoDisponivel::ExcecaoCarroNaoDisponivel(const string& placa, const string& status) 
    : ExcecaoOperacaoNaoPossivel("Carro " + placa + " não está disponível (status: " + status + ")") {}

ExcecaoVendaInvalida::ExcecaoVendaInvalida(const string& motivo) 
    : ExcecaoOperacaoNaoPossivel("Venda inválida: " + motivo) {}

// ============================================================
// EXCEÇÕES DE ARQUIVO / IO
// ============================================================

ExcecaoIO::ExcecaoIO(const string& operacao) 
    : ExcecaoCustomizada("Erro de I/O - " + operacao) {}

ExcecaoPastaDatabase::ExcecaoPastaDatabase() 
    : ExcecaoIO("Não foi possível criar/acessar a pasta database") {}

ExcecaoArquivo::ExcecaoArquivo(const string& nomeArquivo, const string& operacao) 
    : ExcecaoIO("Erro ao " + operacao + " arquivo: " + nomeArquivo) {}

// ============================================================
// EXCEÇÕES DE CAMPOS VAZIOS / STRINGS INVÁLIDAS
// ============================================================

ExcecaoCampoVazio::ExcecaoCampoVazio(const string& nomeCampo) 
    : ExcecaoDadosInvalidos(nomeCampo + " não pode estar vazio") {}

ExcecaoNomeInvalido::ExcecaoNomeInvalido() 
    : ExcecaoCampoVazio("Nome deve ter mínimo 4 caracteres e 1 espaço (nome e sobrenome)") {}

ExcecaoTelefoneInvalido::ExcecaoTelefoneInvalido(const string& telefone) 
    : ExcecaoCampoVazio("Telefone deve ter pelo menos 10 dígitos" + 
                       (telefone.empty() ? "" : ": " + telefone)) {}

ExcecaoEmailInvalido::ExcecaoEmailInvalido(const string& email) 
    : ExcecaoCampoVazio("Email inválido" + (email.empty() ? "" : ": " + email)) {}

ExcecaoEnderecoInvalido::ExcecaoEnderecoInvalido(const string& campo) 
    : ExcecaoCampoVazio("Endereço - " + campo) {}

// ============================================================
// EXCEÇÕES DE DADOS DUPLICADOS
// ============================================================

ExcecaoDadosDuplicados::ExcecaoDadosDuplicados(const string& campo, const string& valor) 
    : ExcecaoDadosInvalidos(campo + " duplicado: " + valor) {}

ExcecaoCPFDuplicado::ExcecaoCPFDuplicado(const string& cpf) 
    : ExcecaoDadosDuplicados("CPF", cpf) {}

ExcecaoTelefoneDuplicado::ExcecaoTelefoneDuplicado(const string& telefone) 
    : ExcecaoDadosDuplicados("Telefone", telefone) {}

ExcecaoEmailDuplicado::ExcecaoEmailDuplicado(const string& email) 
    : ExcecaoDadosDuplicados("Email", email) {}

ExcecaoPlacaDuplicada::ExcecaoPlacaDuplicada(const string& placa) 
    : ExcecaoDadosDuplicados("Placa", placa) {}