#ifndef EXCECOES_H
#define EXCECOES_H

#include <stdexcept>
#include <string>

using namespace std;

// ============================================================
// EXCEÇÃO BASE CUSTOMIZADA
// ============================================================

/**
 * @class ExcecaoCustomizada
 * @brief Exceção base para todas as exceções personalizadas do projeto 
 */
class ExcecaoCustomizada : public runtime_error {
public:
    explicit ExcecaoCustomizada(const string& mensagem);
    virtual ~ExcecaoCustomizada() = default;
};

// ============================================================
// EXCEÇÕES DE VALIDAÇÃO DE DADOS
// ============================================================

/**
 * @class ExcecaoDadosInvalidos
 * @brief Lançada quando dados de entrada não passam em validação
 */
class ExcecaoDadosInvalidos : public ExcecaoCustomizada {
public:
    explicit ExcecaoDadosInvalidos(const string& campo);
};

/**
 * @class ExcecaoCPFInvalido
 * @brief Lançada quando CPF não passa na validação
 */
class ExcecaoCPFInvalido : public ExcecaoDadosInvalidos {
public:
    explicit ExcecaoCPFInvalido(const string& cpf = "");
};

/**
 * @class ExcecaoIdadeInvalida
 * @brief Lançada quando idade é negativa ou inválida
 */
class ExcecaoIdadeInvalida : public ExcecaoDadosInvalidos {
public:
    explicit ExcecaoIdadeInvalida(int idade);
};

/**
 * @class ExcecaoAnoInvalido
 * @brief Lançada quando ano do veículo está fora do intervalo permitido
 */
class ExcecaoAnoInvalido : public ExcecaoDadosInvalidos {
public:
    explicit ExcecaoAnoInvalido(int ano);
};

/**
 * @class ExcecaoPrecoInvalido
 * @brief Lançada quando preço é negativo ou inconsistente
 */
class ExcecaoPrecoInvalido : public ExcecaoDadosInvalidos {
private:
    float valor;
public:
    explicit ExcecaoPrecoInvalido(float preco, const string& tipo = "preço");
    float getValor() const { return valor; }
};

/**
 * @class ExcecaoSalarioInvalido
 * @brief Lançada quando salário é negativo
 */
class ExcecaoSalarioInvalido : public ExcecaoPrecoInvalido {
public:
    explicit ExcecaoSalarioInvalido(float salario);
};

// ============================================================
// EXCEÇÕES DE RECURSO / BANCO DE DADOS
// ============================================================

/**
 * @class ExcecaoRecursoNaoEncontrado
 * @brief Lançada quando um registro não é encontrado
 */
class ExcecaoRecursoNaoEncontrado : public ExcecaoCustomizada {
public:
    explicit ExcecaoRecursoNaoEncontrado(const string& tipo, const string& id = "");
};

/**
 * @class ExcecaoCarroNaoEncontrado
 * @brief Lançada quando um carro não é encontrado no estoque
 */
class ExcecaoCarroNaoEncontrado : public ExcecaoRecursoNaoEncontrado {
public:
    explicit ExcecaoCarroNaoEncontrado(const string& placa);
};

/**
 * @class ExcecaoClienteNaoEncontrado
 * @brief Lançada quando um cliente não é encontrado
 */
class ExcecaoClienteNaoEncontrado : public ExcecaoRecursoNaoEncontrado {
public:
    explicit ExcecaoClienteNaoEncontrado(const string& cpf);
};

/**
 * @class ExcecaoFuncionarioNaoEncontrado
 * @brief Lançada quando um funcionário não é encontrado
 */
class ExcecaoFuncionarioNaoEncontrado : public ExcecaoRecursoNaoEncontrado {
public:
    explicit ExcecaoFuncionarioNaoEncontrado(int codigo);
};

/**
 * @class ExcecaoVendaNaoEncontrada
 * @brief Lançada quando uma venda não é encontrada
 */
class ExcecaoVendaNaoEncontrada : public ExcecaoRecursoNaoEncontrado {
public:
    explicit ExcecaoVendaNaoEncontrada(int id);
};

/**
 * @class ExcecaoIndiceInvalido
 * @brief Lançada quando índice está fora dos limites
 */
class ExcecaoIndiceInvalido : public ExcecaoRecursoNaoEncontrado {
public:
    explicit ExcecaoIndiceInvalido(int indice, int tamanho);
};

// ============================================================
// EXCEÇÕES DE NEGÓCIO / LÓGICA
// ============================================================

/**
 * @class ExcecaoOperacaoNaoPossivel
 * @brief Lançada quando operação não pode ser realizada
 */
class ExcecaoOperacaoNaoPossivel : public ExcecaoCustomizada {
public:
    explicit ExcecaoOperacaoNaoPossivel(const string& motivo);
};

/**
 * @class ExcecaoCaixaInsuficiente
 * @brief Lançada quando concessionária não tem saldo suficiente
 */
class ExcecaoCaixaInsuficiente : public ExcecaoOperacaoNaoPossivel {
private:
    float saldoAtual;
    float valorNecessario;
public:
    ExcecaoCaixaInsuficiente(float saldo, float necessario);
    float getSaldoAtual() const { return saldoAtual; }
    float getValorNecessario() const { return valorNecessario; }
};

/**
 * @class ExcecaoCarroNaoDisponivel
 * @brief Lançada quando carro não está disponível para venda
 */
class ExcecaoCarroNaoDisponivel : public ExcecaoOperacaoNaoPossivel {
public:
    explicit ExcecaoCarroNaoDisponivel(const string& placa, const string& status);
};

/**
 * @class ExcecaoVendaInvalida
 * @brief Lançada quando há problema na realização de venda
 */
class ExcecaoVendaInvalida : public ExcecaoOperacaoNaoPossivel {
public:
    explicit ExcecaoVendaInvalida(const string& motivo);
};

// ============================================================
// EXCEÇÕES DE ARQUIVO / IO
// ============================================================

/**
 * @class ExcecaoIO
 * @brief Lançada quando há erro de entrada/saída
 */
class ExcecaoIO : public ExcecaoCustomizada {
public:
    explicit ExcecaoIO(const string& operacao);
};

/**
 * @class ExcecaoPastaDatabase
 * @brief Lançada quando não consegue acessar pasta database
 */
class ExcecaoPastaDatabase : public ExcecaoIO {
public:
    explicit ExcecaoPastaDatabase();
};

/**
 * @class ExcecaoArquivo
 * @brief Lançada quando há erro ao abrir/escrever arquivo
 */
class ExcecaoArquivo : public ExcecaoIO {
public:
    explicit ExcecaoArquivo(const string& nomeArquivo, const string& operacao = "acesso");
};

// ============================================================
// EXCEÇÕES DE CAMPOS VAZIOS / STRINGS INVÁLIDAS
// ============================================================

/**
 * @class ExcecaoCampoVazio
 * @brief Lançada quando um campo obrigatório está vazio
 */
class ExcecaoCampoVazio : public ExcecaoDadosInvalidos {
public:
    explicit ExcecaoCampoVazio(const string& nomeCampo);
};

/**
 * @class ExcecaoNomeInvalido
 * @brief Lançada quando nome está vazio, muito curto ou sem sobrenome
 */
class ExcecaoNomeInvalido : public ExcecaoCampoVazio {
public:
    explicit ExcecaoNomeInvalido();
};

/**
 * @class ExcecaoTelefoneInvalido
 * @brief Lançada quando telefone está vazio ou mal formatado
 */
class ExcecaoTelefoneInvalido : public ExcecaoCampoVazio {
public:
    explicit ExcecaoTelefoneInvalido(const string& telefone = "");
};

/**
 * @class ExcecaoEmailInvalido
 * @brief Lançada quando email está vazio ou mal formatado
 */
class ExcecaoEmailInvalido : public ExcecaoCampoVazio {
public:
    explicit ExcecaoEmailInvalido(const string& email = "");
};

/**
 * @class ExcecaoEnderecoInvalido
 * @brief Lançada quando dados de endereço estão inválidos
 */
class ExcecaoEnderecoInvalido : public ExcecaoCampoVazio {
public:
    explicit ExcecaoEnderecoInvalido(const string& campo);
};

// ============================================================
// EXCEÇÕES DE DADOS DUPLICADOS
// ============================================================

/**
 * @class ExcecaoDadosDuplicados
 * @brief Lançada quando um campo tem valor duplicado (CPF, telefone, email)
 */
class ExcecaoDadosDuplicados : public ExcecaoDadosInvalidos {
public:
    explicit ExcecaoDadosDuplicados(const string& campo, const string& valor);
};

/**
 * @class ExcecaoCPFDuplicado
 * @brief Lançada quando CPF já existe na base de dados
 */
class ExcecaoCPFDuplicado : public ExcecaoDadosDuplicados {
public:
    explicit ExcecaoCPFDuplicado(const string& cpf);
};

/**
 * @class ExcecaoTelefoneDuplicado
 * @brief Lançada quando telefone já existe na base de dados
 */
class ExcecaoTelefoneDuplicado : public ExcecaoDadosDuplicados {
public:
    explicit ExcecaoTelefoneDuplicado(const string& telefone);
};

/**
 * @class ExcecaoEmailDuplicado
 * @brief Lançada quando email já existe na base de dados
 */
class ExcecaoEmailDuplicado : public ExcecaoDadosDuplicados {
public:
    explicit ExcecaoEmailDuplicado(const string& email);
};

/**
 * @class ExcecaoPlacaDuplicada
 * @brief Lançada quando placa de carro já existe no estoque
 */
class ExcecaoPlacaDuplicada : public ExcecaoDadosDuplicados {
public:
    explicit ExcecaoPlacaDuplicada(const string& placa);
};

#endif