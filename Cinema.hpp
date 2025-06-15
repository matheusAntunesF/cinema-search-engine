#ifndef CINEMA_HPP
#define CINEMA_HPP

#include <string>
#include <vector>
#include "Localizacao.hpp"
#include "Filme.hpp"

class Cinema
{
private:
    unsigned int id;
    std::string nome;
    Localizacao localizacao;
    float preco;
    std::vector<Filme> filmes;

public:
    void setId(unsigned int);
    unsigned int getId() const;
    void setNome(std::string nome);
    std::string getNome() const;
    void setLocalizacao(Localizacao localizacao);
    Localizacao getLocalizacao() const;
    void setPreco(float preco);
    float getPreco() const;
    void setFilme(std::vector<Filme> filmes);
    std::vector<Filme> getFilme() const;
};

#endif