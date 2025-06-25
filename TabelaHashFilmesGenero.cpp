#include "TabelaHashFilmesGenero.hpp"
#include "Filme.hpp"
#include <vector>
#include <list>
#include <string>
#include <iostream>
using namespace std;
TabelaHashFilmesGenero::TabelaHashFilmesGenero()
{
}

TabelaHashFilmesGenero::TabelaHashFilmesGenero(int tamanho)
{
    tabela.resize(tamanho);
}

unsigned int TabelaHashFilmesGenero::calcularHash(std::string str)
{
    unsigned int hash = 0;
    for (char c : str)
    {
        hash += c;
    }
    return hash % tabela.size();
}

bool TabelaHashFilmesGenero::inserir(Filme *filme)
{
    bool check = false;
    for (string genero : filme->getGenero())
    {
        unsigned int hash = calcularHash(genero);
        // Confere se a hash e valida
        if (hash >= 0 && (hash < tabela.size()))
        {
            tabela[hash].push_back(filme);
            check = true;
        }
        else
        {
            cout << "Erro: Hash " << hash << "esta fora dos limites da tabela" << endl;
        }
    }

    return check;
}

std::list<Filme *> TabelaHashFilmesGenero::buscar(unsigned int hash)
{
    return tabela.at(hash);
}