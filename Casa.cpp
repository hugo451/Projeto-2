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