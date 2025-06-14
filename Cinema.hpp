#ifndef CINEMA_HPP
#define CINEMA_HPP

#include <string>
#include "Localizacao.hpp"
#include "Filme.hpp"

class Cinema
{
private:
    unsigned int id;
    std::string nome;
    Localizacao localizacao;
    float preco;
    Filme filmes[];    
};

#endif