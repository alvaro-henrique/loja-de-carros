#ifndef FORMATACAO_H
#define FORMATACAO_H

#include <string>
#include <sstream>  
#include <iomanip>  

using namespace std;

// --- FUNÇÃO AUXILIAR PARA FORMATAR MOEDA (VERSÃO CORRIGIDA) ---
inline string formatarReal(float valor) {
    stringstream ss;
    ss << fixed << setprecision(2) << valor;
    string s = ss.str();

    // 1. Encontrar o ponto decimal
    size_t posDecimal = s.find('.');
    if (posDecimal == string::npos) { 
        return "R$ " + s;
    }

    // 2. Substituir o ponto decimal por vírgula (FAZER ISSO PRIMEIRO)
    s.replace(posDecimal, 1, ",");

    // 3. Adicionar separadores de milhar (o '.')
    //    (Começa 3 posições antes da vírgula)
    int posMilhar = posDecimal - 3;
    while (posMilhar > 0) {
        s.insert(posMilhar, ".");
        posMilhar -= 3;
    }

    return "R$ " + s;
}

#endif