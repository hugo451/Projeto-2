#include "Endereco.hpp"

Endereco::Endereco()
{
    this->logradouro = "";
    this->bairro = "";
    this->cidade = "";
    this->cep = "";
    this->numero = 0;
}
Endereco::Endereco(string logradouro, string bairro, string cidade, string cep, int numero)
{
    this->logradouro = logradouro;
    this->bairro = bairro;
    this->cidade = cidade;
    this->cep = cep;
    this->numero = numero;
}
string Endereco::getLogradouro()
{
    return logradouro;
}
string Endereco::getBairro()
{
    return bairro;
}
string Endereco::getCidade()
{
    return cidade;
}
string Endereco::getCep()
{
    return cep;
}
int Endereco::getNumero()
{
    return numero;
}
void Endereco::setLogradouro(string logradouro)
{
    this->logradouro = logradouro;
}
void Endereco::setBairro(string bairro)
{
    this->bairro = bairro;
}
void Endereco::Endereco::setCidade(string cidade)
{
    this->cidade = cidade;
}
void Endereco::setCep(string cep)
{
    this->cep = cep;
}
void Endereco::setNumero(int numero)
{
    this->numero = numero;
}