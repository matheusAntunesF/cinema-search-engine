#include <math.h>
#include "Localizacao.hpp"
using namespace std;

Localizacao::Localizacao(){

}

void Localizacao::setCoordenadaX(int coordenadaX)
{
    this->coordenadaX = coordenadaX;
}
void Localizacao::setCoordenadaY(int coordenadaY)
{
    this->coordenadaY = coordenadaY;
}
int Localizacao::getCoordenadaX()
{
    return coordenadaX;
}
int Localizacao::getCoordenadaY()
{
    return coordenadaY;
}

unsigned int Localizacao::distancia(Localizacao local2)
{
    unsigned int temp1 = pow((local2.getCoordenadaX() - this->coordenadaX), 2);
    unsigned int temp2 = pow((local2.getCoordenadaY() - this->coordenadaY), 2);

    return sqrt(temp1 + temp2);
}