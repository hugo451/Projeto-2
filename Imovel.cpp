#include "Imovel.hpp"

Imovel::Imovel()
{
    
}
bool Imovel::getOferta()
{
    return venda;
}
double Imovel::getValor()
{
    return valor;
}
int Imovel::getTipoImovel()
{
    return tipoImovel;
}
string Imovel::getDescricao()
{
    return descricao;
}
string Imovel::getAnuncio()
{
    return anuncio;
}
Endereco Imovel::getEndereco()
{
    return endereco;
}
void Imovel::setOferta(bool venda)
{
    this->venda = venda;
}
void Imovel::setValor(double valor)
{
    this->valor = valor;
}
void Imovel::setTipoImovel(int tipoImovel)
{
    this->tipoImovel = tipoImovel;
}
void Imovel::setDescricao(string descricao)
{
    this->descricao = descricao;
}
void Imovel::setAnuncio(string anuncio)
{
    this->anuncio = anuncio;
}
void Imovel::setEndereco(Endereco endereco)
{
    this->endereco = endereco;
}
void Imovel::caracteristicas()
{

}