#ifndef CASA_HPP
#define CASA_HPP
#include "Imovel.hpp"

using namespace std;

class Casa : public Imovel
{
private:

    int numPavimentos;
    int numQuartos;
    double areaTerreno;
    double areaConstruida;

public:
    Casa();
    int getnumPavimentos();
    int getnumQuartos();
    double getareaTerreno();
    double getareaConstruida();
    void setnumPavimentos(int numPavimentos);
    void setnumQuartos(int numQuartos);
    void setareaTerreno(double areaTerreno);
    void setareaConstruida(double areaConstruida);
};

#endif