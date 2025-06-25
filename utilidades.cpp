#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include "utilidades.hpp"
#include "Filme.hpp"
#include "CriterioComparacao.hpp"

using namespace std;

string limpaString(const string &str)
{
    const unsigned int primPos = str.find_first_not_of(" \t\n\r");
    if (string::npos == primPos)
    {
        return str;
    }
    const unsigned int ultimaPos = str.find_last_not_of(" \t\n\r");
    return str.substr(primPos, (ultimaPos - primPos + 1));
}

bool comparadorFilmes(Filme* filme1, Filme* filme2, CriterioComparacao criterio){
    if(criterio == duracao)
        return filme1->getDuracao() < filme2->getDuracao();
    else if(criterio == anoInicio)
        return filme1->getAnoInicio() < filme2->getAnoInicio();
    //criterio == anoFim
    else 
        return filme1->getAnoFim() < filme2->getAnoFim();
}

// A função swapFilmes continua a mesma.
void swapFilmes(Filme *&filme1, Filme *&filme2)
{
    Filme *temp = filme1;
    filme1 = filme2;
    filme2 = temp;
}

int partitionFilmes(std::vector<Filme *> &listaFilmes, int esquerda, int direita, CriterioComparacao criterio)
{
    // Escolher o pivô do meio ajuda a evitar o pior caso.
    Filme *pivo = listaFilmes[esquerda + (direita - esquerda) / 2];

    int i = esquerda - 1;
    int j = direita + 1;

    while (true)
    {
        // Encontra, na esquerda, um elemento que deveria estar na direita.
        do
        {
            i++;
        } while (comparadorFilmes(listaFilmes[i], pivo, criterio));

        // Encontra, na direita, um elemento que deveria estar na esquerda.
        do
        {
            j--;
        } while (comparadorFilmes(pivo, listaFilmes[j], criterio));

        // Se os ponteiros se cruzaram, a partição está pronta.
        if (i >= j)
        {
            return j; // 'j' é o ponto de divisão.
        }

        // Troca os elementos que estão no lado errado.
        swapFilmes(listaFilmes[i], listaFilmes[j]);
    }
}

void quickSortFilmes(std::vector<Filme *> &listaFilmes, int esquerda, int direita, CriterioComparacao criterio)
{
    if (esquerda < direita)
    {
        // 'pIndex' é o ponto onde a lista é dividida em duas.
        int pIndex = partitionFilmes(listaFilmes, esquerda, direita, criterio);

        // Recursão para a primeira metade
        quickSortFilmes(listaFilmes, esquerda, pIndex, criterio);

        // Recursão para a segunda metade.
        quickSortFilmes(listaFilmes, pIndex + 1, direita, criterio);
    }
}

void mergeListFilmes(list<Filme *> &resultado, list<Filme *> &esquerda, list<Filme *> &direita)
{
    resultado.clear();

    while (!esquerda.empty() && !direita.empty())
    {
        if (esquerda.front() < direita.front())
        {
            resultado.splice(resultado.end(), esquerda, esquerda.begin());
        }
        else
        {
            resultado.splice(resultado.end(), direita, direita.begin());
        }
    }

    if (!esquerda.empty())
    {
        resultado.splice(resultado.end(), esquerda);
    }
    if (!direita.empty())
    {
        resultado.splice(resultado.end(), direita);
    }
}

// Função MergeSort recursiva para list
void mergeSortListFilmes(std::list<Filme *> &lista)
{
    if (lista.size() <= 1)
    {
        return;
    }

    std::list<Filme *> esquerda, direita;
    auto meio = lista.begin();
    std::advance(meio, lista.size() / 2);

    esquerda.splice(esquerda.begin(), lista, lista.begin(), meio);
    direita.splice(direita.begin(), lista);

    mergeSortListFilmes(esquerda);
    mergeSortListFilmes(direita);

    mergeListFilmes(lista, esquerda, direita);
}

list<Filme*> unirListasFilmes(list<Filme *> &lista1, list<Filme *> &lista2)
{
    list<Filme *> listaFinal(lista2);
    listaFinal.splice(listaFinal.end(), lista1);
    mergeSortListFilmes(listaFinal);
    listaFinal.unique();
    return listaFinal;
}

list<Filme *> intersecionarListasFilmes(list<Filme *> lista1, list<Filme *> lista2)
{
    mergeSortListFilmes(lista1);
    mergeSortListFilmes(lista2);
    list<Filme*> resultado;
    list<Filme *>::const_iterator it1 = lista1.begin();
    list<Filme *>::const_iterator it2 = lista2.begin();
    while (it1 != lista1.end() && it2 != lista2.end())
    {

        if (*it1 < *it2)
        {
            ++it1;
        }
        else if (*it2 < *it1)
        {
            ++it2;
        }
        else
        {
            resultado.push_back(*it1); 

            ++it1;
            ++it2;
        }
    }

    return resultado;
}

bool comparadorCinemas(Filme* filme1, Filme* filme2, CriterioComparacao criterio){
    if(criterio == duracao)
        return filme1->getDuracao() < filme2->getDuracao();
    else if(criterio == anoInicio)
        return filme1->getAnoInicio() < filme2->getAnoInicio();
    //criterio == anoFim
    else 
        return filme1->getAnoFim() < filme2->getAnoFim();
}

// A função swapFilmes continua a mesma.
void swapCinemas(Filme *&filme1, Filme *&filme2)
{
    Filme *temp = filme1;
    filme1 = filme2;
    filme2 = temp;
}

int partitionFilmes(std::vector<Filme *> &listaFilmes, int esquerda, int direita, CriterioComparacao criterio)
{
    // Escolher o pivô do meio ajuda a evitar o pior caso.
    Filme *pivo = listaFilmes[esquerda + (direita - esquerda) / 2];

    int i = esquerda - 1;
    int j = direita + 1;

    while (true)
    {
        // Encontra, na esquerda, um elemento que deveria estar na direita.
        do
        {
            i++;
        } while (comparadorFilmes(listaFilmes[i], pivo, criterio));

        // Encontra, na direita, um elemento que deveria estar na esquerda.
        do
        {
            j--;
        } while (comparadorFilmes(pivo, listaFilmes[j], criterio));

        // Se os ponteiros se cruzaram, a partição está pronta.
        if (i >= j)
        {
            return j; // 'j' é o ponto de divisão.
        }

        // Troca os elementos que estão no lado errado.
        swapFilmes(listaFilmes[i], listaFilmes[j]);
    }
}

void quickSortFilmes(std::vector<Filme *> &listaFilmes, int esquerda, int direita, CriterioComparacao criterio)
{
    if (esquerda < direita)
    {
        // 'pIndex' é o ponto onde a lista é dividida em duas.
        int pIndex = partitionFilmes(listaFilmes, esquerda, direita, criterio);

        // Recursão para a primeira metade
        quickSortFilmes(listaFilmes, esquerda, pIndex, criterio);

        // Recursão para a segunda metade.
        quickSortFilmes(listaFilmes, pIndex + 1, direita, criterio);
    }
}

void mergeListFilmes(list<Filme *> &resultado, list<Filme *> &esquerda, list<Filme *> &direita)
{
    resultado.clear();

    while (!esquerda.empty() && !direita.empty())
    {
        if (esquerda.front() < direita.front())
        {
            resultado.splice(resultado.end(), esquerda, esquerda.begin());
        }
        else
        {
            resultado.splice(resultado.end(), direita, direita.begin());
        }
    }

    if (!esquerda.empty())
    {
        resultado.splice(resultado.end(), esquerda);
    }
    if (!direita.empty())
    {
        resultado.splice(resultado.end(), direita);
    }
}

// Função MergeSort recursiva para list
void mergeSortListFilmes(std::list<Filme *> &lista)
{
    if (lista.size() <= 1)
    {
        return;
    }

    std::list<Filme *> esquerda, direita;
    auto meio = lista.begin();
    std::advance(meio, lista.size() / 2);

    esquerda.splice(esquerda.begin(), lista, lista.begin(), meio);
    direita.splice(direita.begin(), lista);

    mergeSortListFilmes(esquerda);
    mergeSortListFilmes(direita);

    mergeListFilmes(lista, esquerda, direita);
}

list<Filme*> unirListasFilmes(list<Filme *> &lista1, list<Filme *> &lista2)
{
    list<Filme *> listaFinal(lista2);
    listaFinal.splice(listaFinal.end(), lista1);
    mergeSortListFilmes(listaFinal);
    listaFinal.unique();
    return listaFinal;
}

list<Filme *> intersecionarListasFilmes(list<Filme *> lista1, list<Filme *> lista2)
{
    mergeSortListFilmes(lista1);
    mergeSortListFilmes(lista2);
    list<Filme*> resultado;
    list<Filme *>::const_iterator it1 = lista1.begin();
    list<Filme *>::const_iterator it2 = lista2.begin();
    while (it1 != lista1.end() && it2 != lista2.end())
    {

        if (*it1 < *it2)
        {
            ++it1;
        }
        else if (*it2 < *it1)
        {
            ++it2;
        }
        else
        {
            resultado.push_back(*it1); 

            ++it1;
            ++it2;
        }
    }

    return resultado;
}