#include "Busca.hpp"
#include "Cinema.hpp"
#include "Localizacao.hpp"
#include "Filme.hpp"
#include "TabelaHashFilmesTipo.hpp"
#include "ListaFilmesOrdenada.hpp"
#include "utilidades.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>
using namespace std;

Busca::Busca()
{
    isTipo = 0;
    isGenero = 0;
    isDuracao = 0;
    isAno = 0;
    duracaoMin = 0;
    duracaoMax = 0;
    anoInicio = 0;
    anoFim = 0;
}

// Construtor sobrecarregado
Busca::Busca(
    bool isTipo,
    bool isGenero,
    bool isDuracao,
    bool isAno)
{
    setIsTipo(isTipo);
    setIsGenero(isGenero);
    setIsDuracao(isDuracao);
    setIsAno(isAno);
}

// Getters

bool Busca::getIsTipo() const
{
    return this->isTipo;
}

std::vector<std::string> Busca::getTipos() const
{
    return this->tipos;
}

bool Busca::getIsGenero() const
{
    return this->isGenero;
}

std::vector<std::string> Busca::getGeneros() const
{
    return this->generos;
}

bool Busca::getIsDuracao() const
{
    return this->isDuracao;
}

unsigned short Busca::getDuracaoMin() const
{
    return this->duracaoMin;
}

unsigned short Busca::getDuracaoMax() const
{
    return this->duracaoMax;
}

bool Busca::getIsAno() const
{
    return this->isAno;
}

unsigned short Busca::getAnoInicio() const
{
    return this->anoInicio;
}

unsigned short Busca::getAnoFim() const
{
    return this->anoFim;
}

// Setters

void Busca::setIsTipo(bool isTipo)
{
    this->isTipo = isTipo;
}

void Busca::setTipos(const std::vector<std::string> &tipos)
{
    this->tipos = tipos;
}

void Busca::setIsGenero(bool isGenero)
{
    this->isGenero = isGenero;
}

void Busca::setGeneros(const std::vector<std::string> &generos)
{
    this->generos = generos;
}

void Busca::setIsDuracao(bool isDuracao)
{
    this->isDuracao = isDuracao;
}

void Busca::setDuracaoMin(unsigned short duracaoMin)
{
    this->duracaoMin = duracaoMin;
}

void Busca::setDuracaoMax(unsigned short duracaoMax)
{
    this->duracaoMax = duracaoMax;
}

void Busca::setIsAno(bool isAno)
{
    this->isAno = isAno;
}

void Busca::setAnoInicio(unsigned short anoInicio)
{
    this->anoInicio = anoInicio;
}

void Busca::setAnoFim(unsigned short anoFim)
{
    this->anoFim = anoFim;
}

// --- Métodos de Conveniência ---

void Busca::addTipo(const string &tipo)
{
    tipos.push_back(tipo);
}

void Busca::addGenero(const string &genero)
{
    generos.push_back(genero);
}

// Métodos de buscas

list<Filme *> Busca::buscaTipo(TabelaHashFilmesTipo &tabFilmesTipo)
{
    list<Filme *> filmesTipo, listaAuxiliar;
    for (string tipo : tipos)
    {
        unsigned int hash = tabFilmesTipo.calcularHash(tipo);
        listaAuxiliar = tabFilmesTipo.buscar(hash);
        filmesTipo.splice(filmesTipo.end(), listaAuxiliar);
    }
    return filmesTipo;
}

list<Filme *> Busca::buscaGenero(TabelaHashFilmesGenero &tabFilmesGenero)
{
    list<Filme *> filmesGenero;
    list<Filme *> listaAuxiliar;
    for (unsigned int pos = 0; pos < generos.size(); pos++)
    {
        unsigned int hash = tabFilmesGenero.calcularHash(generos.at(pos));
        listaAuxiliar = tabFilmesGenero.buscar(hash);
        if (pos == 0)
        {
            filmesGenero.splice(filmesGenero.end(), listaAuxiliar);
        }
        else
        {
            unirListas(listaAuxiliar, filmesGenero);
        }
    }
    return filmesGenero;
}

list<Filme *> Busca::buscaDuracao(ListaFilmesOrdenada &filmesOrdDuracao)
{
    int esquerda = 0;
    int direita = filmesOrdDuracao.lista.size() - 1;
    int iLimiteSuperior = -1;

    while (esquerda <= direita)
    {
        int meio = esquerda + (direita - esquerda) / 2;
        if (filmesOrdDuracao.lista.at(meio)->getDuracao() <= duracaoMax)
        {
            iLimiteSuperior = meio;
            esquerda = meio + 1;
        }
        else
        {
            direita = meio - 1;
        }
    }
    int iLimiteInferior = -1;
    esquerda = 0;
    if(iLimiteSuperior == -1){
        return {};
    }
    direita = iLimiteSuperior;
    while (esquerda <= direita)
    {
        int meio = esquerda + (direita - esquerda) / 2;
        if (filmesOrdDuracao.lista.at(meio)->getDuracao() >= duracaoMin)
        {
            iLimiteInferior = meio;
            direita = meio - 1;
        }
        else
        {
            esquerda = meio + 1;
        }
    }
    if (iLimiteInferior != -1 && iLimiteInferior <= iLimiteSuperior)
    {
        return list<Filme *>(filmesOrdDuracao.lista.begin() + iLimiteInferior,
                             filmesOrdDuracao.lista.begin() + iLimiteSuperior + 1);
    }
    return {};
}

list<Filme *> Busca::busca(TabelaHashFilmesTipo &tabFilmesTipo,
                           TabelaHashFilmesGenero &tabFilmesGenero, ListaFilmesOrdenada& filmesOrdDuracao)
{
    list<Filme *> listaFilmes, listaAuxiliar;
    bool primeiroFiltroProcessado = false;
    if (isTipo)
    {
        if(!primeiroFiltroProcessado){
            listaFilmes = buscaTipo(tabFilmesTipo);
            primeiroFiltroProcessado = true;
        }
        else{
            listaAuxiliar = buscaTipo(tabFilmesTipo);
            listaFilmes = intersecionarListas(listaFilmes, listaAuxiliar);
            listaAuxiliar.clear();
        }
    }
    if (isGenero)
    {
        if(!primeiroFiltroProcessado){
            listaFilmes = buscaGenero(tabFilmesGenero);
            primeiroFiltroProcessado = true;
        }
        else{
            listaAuxiliar = buscaGenero(tabFilmesGenero);
            listaFilmes = intersecionarListas(listaFilmes, listaAuxiliar);
            listaAuxiliar.clear();
        }
    }
    if (isDuracao)
    {
        if(!primeiroFiltroProcessado){
            listaFilmes = buscaDuracao(filmesOrdDuracao);
            primeiroFiltroProcessado = true;
        }
        else{
            listaAuxiliar = buscaDuracao(filmesOrdDuracao);
            listaFilmes = intersecionarListas(listaFilmes, listaAuxiliar);
            listaAuxiliar.clear();
        }
    }

    return listaFilmes;
}