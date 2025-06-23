#ifndef TABELAHASHFILMESTIPO_HPP
#define TABELAHASHFILMESTIPO_HPP
#include "Filme.hpp"
#include <vector>
#include <list>
#include <string>
#include <iostream>

class TabelaHashFilmesTipo
{
private:
    std::vector<std::list<Filme*>> tabela;

public:
    TabelaHashFilmesTipo();
    TabelaHashFilmesTipo(int tamanho);
    unsigned int calcularHash(std::string str);
    bool inserir(Filme* filme);
    std::list<Filme*> buscar(unsigned int hash);
};


#endif