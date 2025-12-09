# Diagrama UML - Sistema de Loja de Carros

## Diagrama de Classes

```mermaid
classDiagram
    %% Classes principais
    class Pessoa {
        <<abstract>>
        #string CPF
        #string nome
        #int idade
        #string telefone
        #string email
        #Endereco* endereco
        #bool validarCPF(string cpf)
        +Pessoa(string CPF, string nome, int idade, string telefone, string email, Endereco* endereco)
        +~Pessoa()
        +string getCPF()
        +string getNome()
        +int getIdade()
        +string getTelefone()
        +string getEmail()
        +Endereco* getEndereco()
        +void setCPF(string CPF)
        +void setNome(string nome)
        +void setIdade(int idade)
        +void setTelefone(string telefone)
        +void setEmail(string email)
        +void setEndereco(Endereco* endereco)
        +void exibirInformacoes()*
    }

    class Cliente {
        -vector~Venda*~ historicoCompras
        +Cliente(string CPF, string nome, int idade, string telefone, string email, Endereco* endereco)
        +vector~Venda*~ getHistoricoCompras()
        +int getTotalCompras()
        +void adicionarVenda(Venda* venda)
        +void exibirInformacoes()
    }

    class Funcionario {
        #int codigo
        #string dataContratacao
        #float salario
        #string tema
        #string nomeExibicao
        +Funcionario(string CPF, string nome, int idade, string telefone, string email, Endereco* endereco, int codigo, float salario, string tema, string nomeExibicao)
        +int getCodigo()
        +string getDataContratacao()
        +float getSalario()
        +string getTema()
        +string getNomeExibicao()
        +void setCodigo(int codigo)
        +void setSalario(float salario)
        +void setTema(string tema)
        +void setNomeExibicao(string nomeExibicao)
        +float calcularSalario()*
        +void exibirInformacoes()
    }

    class Vendedor {
        -float comissao
        +Vendedor(string CPF, string nome, int idade, string telefone, string email, Endereco* endereco, int codigo, float salario, float comissao, string tema, string nomeExibicao)
        +float getComissao()
        +void setComissao(float comissao)
        +float calcularComissao(float valorVenda)
        +void exibirInformacoes()
    }

    class Endereco {
        -string rua
        -int numero
        -string bairro
        -string cidade
        -string estado
        +Endereco(string rua, int numero, string bairro, string cidade, string estado)
        +string getRua()
        +int getNumero()
        +string getBairro()
        +string getCidade()
        +string getEstado()
        +void setRua(string rua)
        +void setNumero(int numero)
        +void setBairro(string bairro)
        +void setCidade(string cidade)
        +void setEstado(string estado)
        +void exibirEndereco()
    }

    class Carro {
        -string placa
        -string modelo
        -string cor
        -string marca
        -int ano
        -float precoCompra
        -float precoVenda
        -string status
        +Carro(string placa, string modelo, string cor, string marca, int ano, float precoCompra, float precoVenda, string status)
        +string getPlaca()
        +string getModelo()
        +string getCor()
        +string getMarca()
        +int getAno()
        +float getPrecoCompra()
        +float getPrecoVenda()
        +string getStatus()
        +void setPlaca(string placa)
        +void setModelo(string modelo)
        +void setCor(string cor)
        +void setMarca(string marca)
        +void setAno(int ano)
        +void setPrecoCompra(float precoCompra)
        +void setPrecoVenda(float precoVenda)
        +void setStatus(string status)
        +bool estaDisponivel()
        +void vender()
        +void comprar()
        +float calcularLucro()
        +void exibirCarro()
    }

    class Venda {
        -int id
        -Cliente* cliente
        -Vendedor* vendedor
        -vector~Carro*~ carros
        -string metodoPagamento
        -string data
        -float valorTotal
        -int proximoId$
        +Venda(Cliente* cliente, Vendedor* vendedor, vector~Carro*~ carros, string metodoPagamento)
        +int getId()
        +string getData()
        +float getValorTotal()
        +string getMetodoPagamento()
        +Cliente* getCliente()
        +Vendedor* getVendedor()
        +vector~Carro*~ getCarros()
        +void setMetodoPagamento(string metodoPagamento)
        +void calcularValorTotal()
        +void finalizarVenda()
        +void exibirVenda()
    }

    class Concessionaria {
        -string nome
        -string cnpj
        -float caixa
        -CRUD~Carro~ estoque
        +Concessionaria(string nome, string cnpj, float caixaInicial)
        +string getNome()
        +string getCNPJ()
        +float getCaixa()
        +void comprarCarro(Carro* carro)
        +void venderCarro(int indexEstoque)
        +Carro* getCarroEstoque(int index)
        +int getTamanhoEstoque()
        +void exibirEstoque()
        +void exibirBalanco()
    }

    class CRUD~T~ {
        <<template>>
        -vector~T*~ registros
        +~CRUD()
        +void criar(T* registro)
        +T* ler(int index)
        +vector~T*~ lerTodos()
        +void atualizar(int index, T* registro)
        +void remover(int index)
        +int tamanho()
    }

    class ExcecaoCustomizada {
        <<exception>>
        +ExcecaoCustomizada(string mensagem)
    }

    class ExportarDataBase {
        <<utility>>
        +string CAMINHO_DATABASE$
        +string CAMINHO_FUNCIONARIOS$
        +string CAMINHO_CONCESSIONARIA$
        +bool verificarPastaDatabase()$
        +bool exportarFuncionariosCSV(CRUD~Funcionario~& crudFuncionarios)$
        +bool exportarConcessionariaCSV(Concessionaria* concessionaria)$
        +bool importarFuncionariosCSV(CRUD~Funcionario~& crudFuncionarios)$
        +bool importarConcessionariaCSV(Concessionaria*& concessionaria, CRUD~Funcionario~& crudFuncionarios)$
        +vector~string~ splitCSV(string linha, char delimitador)$
    }

    %% Relacionamentos de Herança
    Pessoa <|-- Cliente : herda
    Pessoa <|-- Funcionario : herda
    Funcionario <|-- Vendedor : herda

    %% Relacionamentos de Composição/Agregação
    Pessoa *-- Endereco : possui
    Cliente o-- Venda : histórico
    Venda *-- Cliente : referencia
    Venda *-- Vendedor : referencia
    Venda o-- Carro : contém
    Concessionaria *-- CRUD~Carro~ : gerencia

    %% Relacionamentos de Dependência
    Carro ..> ExcecaoCustomizada : usa
    Pessoa ..> ExcecaoCustomizada : usa
    CRUD ..> ExcecaoCustomizada : usa
    Concessionaria ..> ExcecaoCustomizada : usa
    ExportarDataBase ..> Concessionaria : exporta/importa
    ExportarDataBase ..> CRUD : usa
    ExportarDataBase ..> Funcionario : usa
```

## Descrição das Classes

### Classes de Domínio

#### **Pessoa** (Abstrata)
Classe base para representar pessoas no sistema. Contém atributos e métodos comuns a clientes e funcionários.

#### **Cliente**
Herda de Pessoa. Representa os clientes da concessionária e mantém histórico de compras.

#### **Funcionario**
Herda de Pessoa. Representa funcionários da concessionária com informações de contratação e salário.

#### **Vendedor**
Herda de Funcionario. Especialização de funcionário com sistema de comissões sobre vendas.

#### **Endereco**
Representa o endereço completo de uma pessoa (rua, número, bairro, cidade, estado).

#### **Carro**
Representa os veículos comercializados pela concessionária, com informações de placa, modelo, preços e status.

#### **Venda**
Registra as transações de venda, relacionando cliente, vendedor e carros vendidos, além de armazenar data e método de pagamento.

#### **Concessionaria**
Gerencia o negócio: estoque de carros, caixa financeiro, compra e venda de veículos.

### Classes Utilitárias

#### **CRUD\<T\>** (Template)
Classe genérica para operações CRUD (Create, Read, Update, Delete) sobre qualquer tipo de objeto.

#### **ExcecaoCustomizada**
Classe de exceção personalizada para tratamento de erros específicos do sistema.

#### **ExportarDataBase**
Classe utilitária para persistência de dados em arquivos CSV (funcionários e concessionária).

## Padrões de Projeto Utilizados

1. **Template Method**: Classe CRUD genérica
2. **Inheritance/Polymorphism**: Hierarquia Pessoa → Cliente/Funcionario → Vendedor
3. **Singleton Pattern**: Uso de atributo estático proximoId em Venda
4. **Repository Pattern**: CRUD como repositório genérico

## Relacionamentos Principais

- **Herança**: Cliente e Funcionario herdam de Pessoa; Vendedor herda de Funcionario
- **Composição**: Pessoa possui Endereco (composição forte)
- **Agregação**: Cliente tem histórico de Vendas; Venda referencia Cliente, Vendedor e Carros
- **Uso**: Concessionaria gerencia CRUD de Carros
- **Dependência**: Classes lançam ExcecaoCustomizada quando necessário
