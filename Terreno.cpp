#include "Terreno.hpp"

Terreno::Terreno()
{
    this->setTipoImovel(3);
}
double Terreno::getArea()
{
    return area;
}
void Terreno::setArea(double area)
{
    this->area = area;
}
void Terreno::caracteristicas()
{
    cout << "Valor(R$): " << valor << endl;
    cout << "Descrição: " << descricao << endl;
    cout << "Anúncio: " << anuncio << endl;
    cout << "Logradouro: " << endereco.getLogradouro() << endl;
    cout << "Numero: " << endereco.getNumero() << endl;
    cout << "Bairro: " << endereco.getBairro() << endl;
    cout << "Cidade: " << endereco.getCidade() << endl;
    cout << "CEP: " << endereco.getCep() << endl;
    cout << "Área do terreno: " << area << endl;
}