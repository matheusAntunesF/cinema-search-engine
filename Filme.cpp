#include "Filme.hpp"
#include <iostream>
using namespace std;

void Filme::setId(unsigned int id)
{
    this->id = id;
}

unsigned int Filme::getId() const
{
    return this->id;
}

void Filme::setTipo(string tipo)
{
    this->tipo = tipo;
}

string Filme::getTipo() const
{
    return this->tipo;
}

void Filme::setTituloPrimario(string tituloPrimario)
{
    this->tituloPrimario = tituloPrimario;
}

string Filme::getTituloPrimario() const
{
    return this->tituloPrimario;
}

void Filme::setTituloOriginal(std::string tituloOriginal)
{
    this->tituloOriginal = tituloOriginal;
}

std::string Filme::getTituloOriginal() const
{
    return tituloOriginal;
}

void Filme::setIsAdult(bool isAdult)
{
    this->isAdult = isAdult;
}

bool Filme::getIsAdult() const
{
    return isAdult;
}

void Filme::setAnoInicio(unsigned short anoInicio)
{
    this->anoInicio = anoInicio;
}

unsigned short Filme::getAnoInicio() const
{
    return anoInicio;
}

void Filme::setAnoFim(unsigned short anoFim)
{
    this->anoFim = anoFim;
}

unsigned short Filme::getAnoFim() const
{
    return anoFim;
}

void Filme::setDuracao(unsigned short duracao)
{
    this->duracao = duracao;
}

unsigned short Filme::getDuracao() const
{
    return duracao;
}

void Filme::setGenero(std::vector<std::string> genero)
{
    this->genero = genero;
}

std::vector<std::string> Filme::getGenero() const
{
    return genero;
}
