#include "Cinema.hpp"
#include <string>
#include <sstream>
#include <vector>
using namespace std;

void Cinema::setId(unsigned int id)
{
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
    return Localizacao();
}

void Cinema::setPreco(float preco)
{
    this->preco = preco;
}

float Cinema::getPreco() const
{
    return preco;
}

void Cinema::setIdFilmes(unsigned int idFilme)
{
    this->idFilmes.push_back(idFilme);
}

vector<unsigned int> Cinema::getIdFilmes() const
{
    return idFilmes;
}

std::ostream& operator<<(std::ostream& outputStream, Cinema& cinema){
    outputStream << "ID: " << cinema.id << endl
    <<"Nome: " << cinema.nome << endl
    <<"Coordenada X: " << cinema.localizacao.getCoordenadaX() << endl
    <<"Coordenada Y: " << cinema.localizacao.getCoordenadaY() << endl
    <<"Preco: " << cinema.preco << endl
    <<"Filmes: ";
    for(unsigned int idFilme : cinema.idFilmes){
        outputStream << idFilme << "; ";
    }
    outputStream << endl;
    return outputStream;
}

std::istream& operator>>(std::istream &inputStream, Cinema &cinema)
{
    string linha;

    // Analisando linha por linha
    if (getline(inputStream, linha))
    {
        stringstream isLinha(linha);

        // Tratando todos os dados mais simples
        string idCompletoCinema;
        string strCoordX, strCoordY, strPreco;
        getline(isLinha, idCompletoCinema, ',');
        isLinha.ignore();        
        getline(isLinha, cinema.nome, ',');
        isLinha.ignore();        
        getline(isLinha, strCoordX, ',');
        isLinha.ignore();        
        getline(isLinha, strCoordY, ',');
        isLinha.ignore();        
        getline(isLinha, strPreco, ',');
        isLinha.ignore();        

        // Convertendo as strings em dados especificos
        string idNumericoCinema = idCompletoCinema.substr(2);
        cinema.id = stoul(idNumericoCinema);

        cinema.localizacao.setCoordenadaX(stoul(strCoordX));
        cinema.localizacao.setCoordenadaY(stoul(strCoordY));
        cinema.preco = stof(strPreco);

        // Tratando os dados dos ids dos filmes
        string idCompletoFilme;
        string idNumericoFilme;
        while (getline(isLinha, idCompletoFilme, ','))
        {
            idNumericoFilme = idCompletoFilme.substr(2);
            cinema.idFilmes.push_back(stoul(idNumericoFilme));
            isLinha.ignore();
        }
    }


    return inputStream;
}