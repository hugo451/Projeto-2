#ifndef TERRENO_HPP
#define TERRENO_HPP
#include "Imovel.hpp"

class Terreno : public Imovel
{
private:
    double area;
public:
    Terreno();
    double getArea();
    void setArea(double area);
};

#endif