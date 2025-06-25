#ifndef UTILIDADES_HPP
#define UTILIDADES_HPP
#include <string>
#include <vector>
#include <string>
#include <list>
#include "Filme.hpp"
#include "CriterioComparacao.hpp"

std::string limpaString(const std::string& str);
void quickSortFilmes(std::vector<Filme*>& listaFilmes, int esquerda, int direita, CriterioComparacao criterio);
int partitionFilmes(std::vector<Filme*>& listaFilmes, int esquerda, int direita, CriterioComparacao criterio);
void swapFilmes(Filme*& filme1, Filme*& filme2);
void mergeListFilmes(list<Filme *> &resultado, list<Filme *> &esquerda, list<Filme *> &direita);
void mergeSortListFilmes(std::list<Filme *> &lista);
std::list<Filme*> unirListasFilmes(std::list<Filme*> &listaAuxiliar, std::list<Filme*> &listaFinal);
std::list<Filme *> intersecionarListasFilmes(std::list<Filme *> lista1, std::list<Filme *> lista2);
bool comparadorFilmes(Filme* filme1, Filme* filme2, CriterioComparacao criterio);

#endif