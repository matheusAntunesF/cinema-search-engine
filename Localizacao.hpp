#ifndef LOCALIZACAO_HPP
#define LOCALIZACAO_HPP

class Localizacao
{
private:
    long long int coordenadaX;
    long long int coordenadaY;

public:
    Localizacao();
    Localizacao(long long int coordenadaX, long long int coordenadaY);

    void setCoordenadaX(long long int coordenadaX);
    void setCoordenadaY(long long int coordenadaY);
    long long int getCoordenadaX();
    long long int getCoordenadaY();

    long long int distancia(Localizacao& local2);
};
#endif