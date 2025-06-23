#include "Busca.hpp"
#include "Cinema.hpp"
#include "Localizacao.hpp"
#include "Filme.hpp"
#include "TabelaHashFilmesTipo.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

Busca::Busca()
{
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

list<Filme *> Busca::buscaTipo(TabelaHashFilmesTipo& tabFilmesTipo)
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