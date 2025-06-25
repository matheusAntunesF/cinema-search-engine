#ifndef LISTACINEMASORDENADA_HPP
#define LISTACINEMASORDENADA_HPP
#include <vector>
#include <string>
#include "Cinema.hpp"
#include "CriterioComparacao.hpp"
class ListaCinemasOrdenada
{
public:
    std::vector<Cinema *> lista;
    ListaCinemasOrdenada();
    ListaCinemasOrdenada(unsigned int tamanho);

    void inserir(Cinema *cinema);
    void ordenar(CriterioComparacao criterio);
};

#endif