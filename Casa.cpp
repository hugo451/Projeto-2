#include "Casa.hpp"

Casa::Casa()
{
    this->tipoImovel = 2;
}
int Casa::getnumPavimentos()
{
    return numPavimentos;
}
int Casa::getnumQuartos()
{
    return numQuartos;
}
double Casa::getareaTerreno()
{
    return areaTerreno;
}
double Casa::getareaConstruida()
{
    return areaConstruida;
}
void Casa::setnumPavimentos(int numPavimentos)
{
    this->numPavimentos = numPavimentos;
}
void Casa::setnumQuartos(int numQuartos)
{
    this->numQuartos = numQuartos;
}
void Casa::setareaTerreno(double areaTerreno)
{
    this->areaTerreno = areaTerreno;
}
void Casa::setareaConstruida(double areaConstruida)
{
    this->areaConstruida = areaConstruida;
}
void Casa::caracteristicas()
{
    cout << "Valor(R$): " << valor << endl;
    cout << "Descrição: " << descricao << endl;
    cout << "Anúncio: " << anuncio << endl;
    cout << "Logradouro: " << endereco.getLogradouro() << endl;
    cout << "Numero: " << endereco.getNumero() << endl;
    cout << "Bairro: " << endereco.getBairro() << endl;
    cout << "Cidade: " << endereco.getCidade() << endl;
    cout << "CEP: " << endereco.getCep() << endl;
    cout << "Número de quartos: " << numQuartos << endl;
    cout << "Número de pavimentos: " << numPavimentos << endl;
    cout << "Área do terreno:" << areaTerreno << endl;
    cout << "Área construida: " << areaConstruida << endl;
}