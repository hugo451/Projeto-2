#include "Apartamento.hpp"

Apartamento::Apartamento()
{
    this->setTipoImovel(1);
}
string Apartamento::getposicao()
{
    return posicao;
}
int Apartamento::getnumQuartos()
{
    return numQuartos;
}
double Apartamento::getvalorCondomino()
{
    return valorCondomino;
}
int Apartamento::getvagasGaragem()
{
    return vagasGaragem;
}
double Apartamento::getarea()
{
    return area;
}
void Apartamento::setposicao(string posicao)
{
    this->posicao = posicao;
}
void Apartamento::setnumQuartos(int numQuartos)
{
    this->numQuartos = numQuartos;
}
void Apartamento::setvalorCondomino(double valorCondomino)
{
    this->valorCondomino = valorCondomino;
}
void Apartamento::setvagasGaragem(int vagasGaragem)
{
    this->vagasGaragem = vagasGaragem;
}
void Apartamento::setarea(double area)
{
    this->area = area;
}
void Apartamento::caracteristicas()
{
    cout << "Valor(R$): " << valor << endl;
    cout << "Descrição: " << descricao << endl;
    cout << "Anúncio: " << anuncio << endl;
    cout << "Logradouro: " << endereco.getLogradouro() << endl;
    cout << "Numero: " << endereco.getNumero() << endl;
    cout << "Bairro: " << endereco.getBairro() << endl;
    cout << "Cidade: " << endereco.getCidade() << endl;
    cout << "CEP: " << endereco.getCep() << endl;
    cout << "Posição: " << posicao << endl;
    cout << "Número de quartos: " << numQuartos << endl;
    cout << "Vagas de garagem: " << vagasGaragem << endl;
    cout << "Valor do condomínio: " << valorCondomino << endl;
    cout << "Area do imóvel: " << area << endl;
}