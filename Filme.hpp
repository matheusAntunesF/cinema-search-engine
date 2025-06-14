#ifndef FILME_HPP
#define FILME_HPP
#include <string>

class Filme
{
private:
    unsigned int id;
    std::string tipo;
    std::string tituloPrimario;
    std::string tituloOriginal;
    bool isAdult;
    unsigned short anoInicio;
    unsigned short anoFim;
    unsigned short duracao;
    std::string genero[];
};
#endif