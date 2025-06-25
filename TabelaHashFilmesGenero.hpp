#ifndef TABELAHASHFILMESGENERO_HPP
#define TABELAHASHFILMESGENERO_HPP
#include <vector>
#include <list>
#include <string>
#include <iostream>
#include "Filme.hpp"

class TabelaHashFilmesGenero
{
private:
    std::vector<std::list<Filme*>> tabela;

public:
    TabelaHashFilmesGenero();
    TabelaHashFilmesGenero(int tamanho);
    unsigned int calcularHash(std::string str);
    bool inserir(Filme* filme);
    std::list<Filme*> buscar(unsigned int hash);
};


#endif