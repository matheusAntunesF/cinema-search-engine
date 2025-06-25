#include "ListaCinemasOrdenada.hpp"
#include <string>
#include <algorithm>
#include "utilidades.hpp"
#include "CriterioComparacao.hpp"
#include "Cinema.hpp"
using namespace std;
ListaCinemasOrdenada::ListaCinemasOrdenada()
{
}
ListaCinemasOrdenada::ListaCinemasOrdenada(unsigned int tamanho)
{
    lista.reserve(tamanho);
}

void ListaCinemasOrdenada::inserir(Cinema *cinema)
{
    lista.push_back(cinema);
}

void ListaCinemasOrdenada::ordenar(CriterioComparacao criterio)
{
    quickSortCinemas(lista, 0, lista.size() - 1, criterio);
}
