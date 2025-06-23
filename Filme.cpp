#include "Filme.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "utilidades_string.hpp"
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

vector<string> Filme::getGenero() const
{
    return genero;
}

ostream &operator<<(std::ostream &outputStream, Filme &filme)
{
    outputStream << "ID: " << filme.getId() << endl
                 << "Tipo: " << filme.getTipo() << endl
                 << "Titulo Primario: " << filme.getTituloPrimario() << endl
                 << "Titulo Original: " << filme.getTituloOriginal() << endl
                 << "E adulto: " << filme.getIsAdult() << endl
                 << "Ano Inicio: " << filme.getAnoInicio() << endl
                 << "Ano Fim: " << filme.getAnoFim() << endl
                 << "Duracao: " << filme.getDuracao() << endl;

    cout << "Generos: ";
    for (string genero : filme.getGenero())
    {
        outputStream << genero << "; ";
    }
    outputStream << endl;
    return outputStream;
}

istream &operator>>(istream &inputStream, Filme &filme)
{
    string linha;

    // Analisando linha por linha
    if (getline(inputStream, linha))
    {
        stringstream isLinha(linha);

        // Tratando todos os dados mais simples
        string idCompletoFilme;
        string tempTipo, tempTituloPrimario, tempTituloOriginal, tempIsAdult, tempAnoInicio, tempAnoFim, tempDuracao;

        getline(isLinha, idCompletoFilme, '\t');
        getline(isLinha, tempTipo, '\t');
        getline(isLinha, tempTituloPrimario, '\t');
        getline(isLinha, tempTituloOriginal, '\t');
        getline(isLinha, tempIsAdult, '\t');
        getline(isLinha, tempAnoInicio, '\t');
        getline(isLinha, tempAnoFim, '\t');
        getline(isLinha, tempDuracao, '\t');

        filme.tipo = limpaString(tempTipo);
        filme.tituloPrimario = limpaString(tempTituloPrimario);
        filme.tituloOriginal = limpaString(tempTituloOriginal);
        filme.isAdult = stoul(limpaString(tempIsAdult));
        tempAnoInicio = limpaString(tempAnoInicio);
        if(tempAnoInicio == "\\N"){
            filme.anoInicio = 0;
        } else{
            filme.anoInicio = stoul(tempAnoInicio);
        }
        tempAnoFim = limpaString(tempAnoFim);
        if(tempAnoFim == "\\N"){
            filme.anoFim = 0;
        } else{
            filme.anoFim = stoul(tempAnoFim);
        }
        tempDuracao = limpaString(tempDuracao);
        if(tempDuracao == "\\N"){
            filme.duracao = 0;
        } else{
            filme.duracao = stoul(tempDuracao);
        }

        string idNumericoFilme = idCompletoFilme.substr(2);
        filme.id = stoul(idNumericoFilme);
        
        // Tratando os dados dos generos dos filmes
        string generoFilme;
        while (getline(isLinha, generoFilme, ','))
        {
            filme.genero.push_back(generoFilme);
        }
    }

    return inputStream;
}