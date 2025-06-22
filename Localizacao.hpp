#ifndef LOCALIZACAO_HPP
#define LOCALIZACAO_HPP

class Localizacao
{
private:
    int coordenadaX;
    int coordenadaY;

public:
    Localizacao();

    void setCoordenadaX(int coordenadaX);
    void setCoordenadaY(int coordenadaY);
    int getCoordenadaX();
    int getCoordenadaY();

    unsigned int distancia(Localizacao local2);
};
#endif