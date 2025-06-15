#include "Cinema.hpp"
#include <string>
using namespace std;

void Cinema::setId(unsigned int id){
   this->id = id; 
}

unsigned int Cinema::getId() const
{
    return id;
}

void Cinema::setNome(string nome)
{
    this->nome = nome;
}

std::string Cinema::getNome() const
{
    return nome;
}

void Cinema::setLocalizacao(Localizacao localizacao)
{
    this->localizacao = localizacao;
}

Localizacao Cinema::getLocalizacao() const
{
    return localizacao;
}

void Cinema::setPreco(float preco)
{
    this->preco = preco;
}

float Cinema::getPreco() const
{
    return preco;
}

void Cinema::setFilme(vector <Filme> filmes)
{
    this->filmes = filmes;
}

vector <Filme> Cinema::getFilme() const
{
    return filmes;
}
