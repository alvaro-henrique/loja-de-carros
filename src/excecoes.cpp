#ifndef EXCECOES_H
#define EXCECOES_H

#include <stdexcept>
#include <string>

using namespace std;

class ExcecaoCustomizada : public runtime_error {
public:
    ExcecaoCustomizada(const string& mensagem) : runtime_error(mensagem) {}
};

#endif