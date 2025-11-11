#include "cliente.h"
#include <vector>

using namespace std;

Cliente::Cliente(string CPF, string nome, int idade, string telefone, string email, Endereco* endereco)
    : Pessoa(CPF, nome, idade, telefone, email, endereco) {}

vector<Venda*> Cliente::getHistoricoCompras() { 
    return historicoCompras; 
}

void Cliente::adicionarVenda(Venda* venda) {
    historicoCompras.push_back(venda);
}

int Cliente::getTotalCompras() {
    return historicoCompras.size();
}

void Cliente::exibirInformacoes(){
    Pessoa::exibirInformacoes();
    cout << "\nTotal de Compras: " << getTotalCompras();
}
