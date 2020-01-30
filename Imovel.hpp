#ifndef IMOVEL_HPP
#define IMOVEL_HPP
#include <iostream>
#include "Endereco.hpp"

using namespace std;

class Imovel
{
protected:
    
    bool venda;
    double valor;
    int tipoImovel;
    string descricao;
    string anuncio;
    Endereco endereco;

public:

    Imovel();

    bool getOferta();
    double getValor();
    int getTipoImovel();
    string getDescricao();
    string getAnuncio();
    Endereco getEndereco();
    void setOferta(bool venda);
    void setValor(double valor);
    void setTipoImovel(int tipoImovel);
    void setDescricao(string descricao);
    void setAnuncio(string anuncio);
    void setEndereco(Endereco endereco);
    virtual void caracteristicas();
};

#endif