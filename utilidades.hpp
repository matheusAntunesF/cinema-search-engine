#ifndef UTILIDADES_HPP
#define UTILIDADES_HPP
#include <string>
#include <vector>
#include <string>
#include <list>
#include "Filme.hpp"
#include "Cinema.hpp"
#include "CriterioComparacao.hpp"

std::string limpaString(const std::string &str);
void quickSortFilmes(std::vector<Filme *> &listaFilmes, int esquerda, int direita, CriterioComparacao criterio);
int partitionFilmes(std::vector<Filme *> &listaFilmes, int esquerda, int direita, CriterioComparacao criterio);
void swapFilmes(Filme *&filme1, Filme *&filme2);
void mergeListFilmes(std::list<Filme *> &resultado, std::list<Filme *> &esquerda, std::list<Filme *> &direita);
void mergeSortListFilmes(std::list<Filme *> &lista);
std::list<Filme *> unirListasFilmes(std::list<Filme *> &listaAuxiliar, std::list<Filme *> &listaFinal);
std::list<Filme *> intersecionarListasFilmes(std::list<Filme *> lista1, std::list<Filme *> lista2);
bool comparadorFilmes(Filme *filme1, Filme *filme2, CriterioComparacao criterio);

void quickSortCinemas(std::vector<Cinema *> &listaCinemas, int esquerda, int direita, CriterioComparacao criterio);
int partitionCinemas(std::vector<Cinema *> &listaCinemas, int esquerda, int direita, CriterioComparacao criterio);
void swapCinemas(Cinema *&filme1, Cinema *&filme2);
void mergeListCinemas(std::list<Cinema *> &resultado, std::list<Cinema *> &esquerda, std::list<Cinema *> &direita);
void mergeSortListCinemas(std::list<Cinema *> &lista);
std::list<Cinema *> unirListasCinemas(std::list<Cinema *> &listaAuxiliar, std::list<Cinema *> &listaFinal);
std::list<Cinema *> intersecionarListasCinemas(std::list<Cinema *> lista1, std::list<Cinema *> lista2);
bool comparadorCinemas(Cinema *filme1, Cinema *filme2, CriterioComparacao criterio);

#endif