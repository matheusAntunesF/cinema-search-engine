#ifndef UTILIDADES_HPP
#define UTILIDADES_HPP
#include <string>
#include <vector>
#include <string>
#include <list>
#include "Filme.hpp"

std::string limpaString(const std::string& str);
void quickSort(std::vector<Filme*>& listaFilmes, int esquerda, int direita);
int partition(std::vector<Filme*>& listaFilmes, int esquerda, int direita);
void swap(Filme*& filme1, Filme*& filme2);
void unirListas(std::list<Filme*> &listaAuxiliar, std::list<Filme*> &listaFinal);
std::list<Filme *> intersecionarListas(std::list<Filme *> lista1, std::list<Filme *> lista2);

#endif