#include "concessionaria.h"

void Concessionaria::comprarCarro(Carro* carro) {
    if (caixa >= carro->getPrecoCompra()) {
        estoque.criar(carro);
        caixa -= carro->getPrecoCompra();
        carro->comprar();
    } else {
        throw ExcecaoCaixaInsuficiente(caixa, carro->getPrecoCompra());
    }
}

void Concessionaria::venderCarro(int indexEstoque) {
    Carro* carro = estoque.ler(indexEstoque);
    if (carro->estaDisponivel()) {
        caixa += carro->getPrecoVenda();
        carro->vender();
        cout << "Carro vendido! Lucro: " << formatarReal(carro->calcularLucro()) 
             << " | Caixa atual: " << formatarReal(caixa) << endl;
        estoque.remover(indexEstoque);
    } else {
        throw ExcecaoCarroNaoDisponivel(carro->getPlaca(), carro->getStatus());
    }
}

Carro* Concessionaria::getCarroEstoque(int index) {
    return estoque.ler(index);
}

int Concessionaria::getTamanhoEstoque() const {
    return estoque.tamanho();
}

vector<Carro*> Concessionaria::getEstoque() const {
    return estoque.lerTodos();
}

void Concessionaria::exibirEstoque() const {
    cout << "=== ESTOQUE DA CONCESSIONÁRIA ===" << endl;
    cout << "Nome: " << nome << " | CNPJ: " << cnpj << " | Caixa: " << formatarReal(caixa) << endl;
    for (int i = 0; i < estoque.tamanho(); i++) {
        cout << "[" << i << "] ";
        estoque.ler(i)->exibirCarro();
        cout << "\n---\n";
    }
}

void Concessionaria::exibirBalanco() const {
    float totalInvestido = 0;
    int carrosDisponiveis = 0;
    
    for (int i = 0; i < estoque.tamanho(); i++) {
        Carro* carro = estoque.ler(i);
        totalInvestido += carro->getPrecoCompra();
        if (carro->estaDisponivel()) {
            carrosDisponiveis++;
        }
    }
    
    float lucroTotal = caixa - totalInvestido;
    
    cout << "\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
    cout << "📊 BALANÇO FINANCEIRO - " << nome << endl;
    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
    cout << "💰 Caixa Atual: " << formatarReal(caixa) << endl;
    cout << "📦 Total Investido em Estoque: " << formatarReal(totalInvestido) << endl;
    cout << "🚗 Carros Disponíveis: " << carrosDisponiveis << " de " << estoque.tamanho() << endl;
    cout << "📈 Lucro Total: " << formatarReal(lucroTotal) << endl;
    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
}
