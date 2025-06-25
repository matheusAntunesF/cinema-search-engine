#ifndef LISTAFILMESORDENADA_HPP
#define LISTAFILMESORDENADA_HPP
#include <vector>
#include <string>
#include "Filme.hpp"
class ListaFilmesOrdenada
{
public:
    std::vector<Filme *> lista;
    ListaFilmesOrdenada();
    ListaFilmesOrdenada(unsigned int tamanho);

    void inserir(Filme* filme);
    void ordenar();
};

#endif