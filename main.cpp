#include <iostream>
#include "Cinema.hpp"
#include "Filme.hpp"
#include "Localizacao.hpp"
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

void tratarBaseCinema(stringstream& baseCinema, vector<Cinema>& cinemas);
void tratarBaseFilme(stringstream& baseFilme, vector<Filme>& filmes);

int main()
{
    // Lendo base de dados de cinemas
    ifstream arquivoBaseCinema("base-de-dados/cinemas(1).txt");
    if (!arquivoBaseCinema.is_open())
    {
        cout << "Erro! Nao foi possivel abrir o arquivo \"cinemas(1).txt\"";
        return 1;
    }
    stringstream baseCinema;
    baseCinema << arquivoBaseCinema.rdbuf();
    // Base de dados na memoria, arquivo nao e mais necessario
    arquivoBaseCinema.close();
    vector<Cinema> cinemas;
    cinemas.reserve(400);
    tratarBaseCinema(baseCinema, cinemas);

    // Lendo base de dados de filmes
    ifstream arquivoBaseFilme("base-de-dados/filmesCrop.txt");
    if(!arquivoBaseFilme.is_open()){
        cout << "Erro! Nao foi possivel abrir o arquivo \"filmesCrop.txt\"";
        return 1;
    }
    stringstream baseFilme;
    baseFilme << arquivoBaseFilme.rdbuf();
    arquivoBaseFilme.close();

    vector<Filme> filmes;
    filmes.reserve(1300000);
    tratarBaseFilme(baseFilme, filmes);

    return 0;
}

void tratarBaseCinema(stringstream &baseCinema, vector<Cinema>& cinemas)
{
    string linhaIgnorada;
    if (getline(baseCinema, linhaIgnorada))
    {
    }

    string linha;
    while(getline(baseCinema, linha)){
        if(linha.empty()){
            continue;
        }
        stringstream ssLinhaTemporaria(linha);
        Cinema cinema;

        if(ssLinhaTemporaria >> cinema){
            cinemas.push_back(cinema);
        }
    }
}

void tratarBaseFilme(stringstream& baseFilme, vector<Filme>& filmes){
    string linhaIgnorada;
    if (getline(baseFilme, linhaIgnorada))
    {
    }

    string linha;
    while(getline(baseFilme, linha)){
        if(linha.empty()){
            continue;
        }
        stringstream ssLinhaTemporaria(linha);
        Filme filme;

        if(ssLinhaTemporaria >> filme){
            filmes.push_back(filme);
        }
    }
}