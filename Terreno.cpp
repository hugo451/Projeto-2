#include "Terreno.hpp"

Terreno::Terreno()
{
    this->tipoImovel = 3;
}
double Terreno::getArea()
{
    return area;
}
void Terreno::setArea(double area)
{
    this->area = area;
}