#include <iostream>
#include "Cinema.hpp"
#include "Filme.hpp"
#include "Localizacao.hpp"
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

void tratarBaseCinema(stringstream &baseCinema, vector<Cinema>& cinemas);

int main()
{
    // Lendo base de dados de Cinemas
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
    tratarBaseCinema(baseCinema, cinemas);

    for(Cinema cinema : cinemas){
        cout << cinema;
    }

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