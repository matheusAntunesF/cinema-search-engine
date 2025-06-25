#include "ListaFilmesOrdenada.hpp"
#include <string>
#include <algorithm>
#include "utilidades.hpp"
#include "CriterioComparacao.hpp"
#include "Filme.hpp"
using namespace std;
ListaFilmesOrdenada::ListaFilmesOrdenada()
{
}
ListaFilmesOrdenada::ListaFilmesOrdenada(unsigned int tamanho)
{
    lista.reserve(tamanho);
}

void ListaFilmesOrdenada::inserir(Filme *filme)
{
    lista.push_back(filme);
}

void ListaFilmesOrdenada::ordenar(CriterioComparacao criterio)
{
    quickSortFilmes(lista, 0, lista.size() - 1, criterio);
}
