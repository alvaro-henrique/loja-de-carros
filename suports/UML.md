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
