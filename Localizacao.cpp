#include <math.h>
#include "Localizacao.hpp"
using namespace std;

Localizacao::Localizacao()
{
}

Localizacao::Localizacao(long long int coordenadaX, long long int coordenadaY)
{
    setCoordenadaX(coordenadaX);
    setCoordenadaY(coordenadaY);
}

void Localizacao::setCoordenadaX(long long int coordenadaX)
{
    this->coordenadaX = coordenadaX;
}
void Localizacao::setCoordenadaY(long long int coordenadaY)
{
    this->coordenadaY = coordenadaY;
}
long long int Localizacao::getCoordenadaX()
{
    return coordenadaX;
}
long long int Localizacao::getCoordenadaY()
{
    return coordenadaY;
}

long long int Localizacao::distancia(Localizacao& local2)
{
    long long int temp1 = local2.getCoordenadaX() - this->coordenadaX;
    temp1 = temp1 * temp1;
    long long int temp2 = local2.getCoordenadaY() - this->coordenadaY;
    temp2 = temp2*temp2;

    return sqrt(temp1 + temp2);
}