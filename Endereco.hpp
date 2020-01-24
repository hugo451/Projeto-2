#ifndef ENDERECO_HPP
#define ENDERECO_HPP
#include <iostream>

using namespace std;

class Endereco
{
private:

    string logradouro;
    string bairro;
    string cidade;
    string cep;
    int numero;

public:

    Endereco();
    Endereco(string logradouro, string bairro, string cidade, string cep, int numero);

    string getLogradouro();
    string getBairro();
    string getCidade();
    string getCep();
    int getNumero();
    void setLogradouro(string logradouro);
    void setBairro(string bairro);
    void setCidade(string cidade);
    void setCep(string cep);
    void setNumero(int numero);

};
#endif