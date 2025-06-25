#include "ListaFilmesOrdenada.hpp"
#include <string>
#include <algorithm>
#include "utilidades.hpp"
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

void ListaFilmesOrdenada::ordenar()
{
    quickSort(lista, 0, lista.size() - 1);
    /*
    sort(lista.begin(), lista.end(), [](const Filme *a, const Filme *b)
         {
    // A lambda recebe dois ponteiros para Filme como argumentos.
    // Retorna 'true' se 'a' deve vir ANTES de 'b' na ordenação.
    return a->getDuracao() < b->getDuracao(); });
*/
}
