#ifndef CINEMA_HPP
#define CINEMA_HPP

#include <string>
#include <vector>
#include "Localizacao.hpp"
#include "Filme.hpp"
#include <sstream>

class Cinema
{
private:
    unsigned int id;
    std::string nome;
    Localizacao localizacao;
    float preco;
    std::vector<unsigned int> idFilmes;

public:
    void setId(unsigned int);
    unsigned int getId() const;
    void setNome(std::string nome);
    std::string getNome() const;
    void setLocalizacao(Localizacao localizacao);
    Localizacao getLocalizacao() const;
    void setPreco(float preco);
    float getPreco() const;
    void setIdFilmes(unsigned int idFilme);
    std::vector<unsigned int> getIdFilmes() const;

    friend std::istream& operator>>(std::istream& inputStream, Cinema& cinema);
    friend std::ostream& operator<<(std::ostream& outputStream, Cinema& cinema);
};

#endif