#ifndef LISTAFILMESORDENADA_HPP
#define LISTAFILMESORDENADA_HPP
#include <vector>
#include <string>
#include "Filme.hpp"
#include "CriterioComparacao.hpp"
class ListaFilmesOrdenada
{
public:
    std::vector<Filme *> lista;
    ListaFilmesOrdenada();
    ListaFilmesOrdenada(unsigned int tamanho);

    void inserir(Filme *filme);
    void ordenar(CriterioComparacao criterio);
};

#endif