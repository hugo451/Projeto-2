#include "Apartamento.hpp"

Apartamento::Apartamento()
{
    this->tipoImovel = 1;
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