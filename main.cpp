#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>

#include "Cinema.hpp"
#include "Filme.hpp"
#include "Localizacao.hpp"
#include "TabelaHashFilmesTipo.hpp"
#include "Busca.hpp"
#include "ListaFilmesOrdenada.hpp"
#include "ListaCinemasOrdenada.hpp"
#include "CriterioComparacao.hpp"
#include "variaveis-globais.hpp"

using namespace std;

void tratarBaseCinema(stringstream &baseCinema, vector<Cinema> &cinemas);
void tratarBaseFilme(stringstream &baseFilme, vector<Filme> &filmes);

int main()
{
    // Contando o tempo
    auto start = chrono::high_resolution_clock::now();
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
    if (!arquivoBaseFilme.is_open())
    {
        cout << "Erro! Nao foi possivel abrir o arquivo \"filmesCrop.txt\"";
        return 1;
    }
    stringstream baseFilme;
    baseFilme << arquivoBaseFilme.rdbuf();
    arquivoBaseFilme.close();

    vector<Filme> filmes;
    filmes.reserve(600000);
    tratarBaseFilme(baseFilme, filmes);

    // Prepara estrutura auxiliar para busca por tipo
    TabelaHashFilmesTipo tabFilmesTipo(10 * 20);
    for (unsigned int i = 0; i < filmes.size(); i++)
    {
        tabFilmesTipo.inserir(&filmes.at(i));
    }

    // Prepara estrutura auxiliar para busca por genero
    TabelaHashFilmesGenero tabFilmesGenero(10 * 30);
    for (unsigned int i = 0; i < filmes.size(); i++)
    {
        tabFilmesGenero.inserir(&filmes.at(i));
    }

    // Prepara estrutura auxiliar para busca por duracao
    ListaFilmesOrdenada filmesOrdDuracao(filmes.size());
    for (unsigned int i = 0; i < filmes.size(); i++)
    {
        filmesOrdDuracao.inserir(&filmes.at(i));
    }
    filmesOrdDuracao.ordenar(duracao);

    // Prepara estrutura auxiliar para busca por ano inicio
    ListaFilmesOrdenada filmesOrdAnoInicio(filmes.size());
    for (unsigned int i = 0; i < filmes.size(); i++)
    {
        filmesOrdAnoInicio.inserir(&filmes.at(i));
    }
    filmesOrdAnoInicio.ordenar(anoInicio);

    // Prepara estrutura auxiliar para busca por ano fim
    ListaFilmesOrdenada filmesOrdAnoFim(filmes.size());
    for (unsigned int i = 0; i < filmes.size(); i++)
    {
        filmesOrdAnoFim.inserir(&filmes.at(i));
    }
    filmesOrdAnoFim.ordenar(anoFim);

    // Prepara estrutura auxiliar para busca de cinemas por preco
    ListaCinemasOrdenada cinemasOrdPreco(cinemas.size());
    for (unsigned int i = 0; i < cinemas.size(); i++)
    {
        cinemasOrdPreco.inserir(&cinemas.at(i));
    }
    cinemasOrdPreco.ordenar(preco);

    // Prepara estrutura auxiliar para busca de cinemas por distancia
    // a minha localizacao (definida como variavel global)
    ListaCinemasOrdenada cinemasOrdDistancia(cinemas.size());
    for (unsigned int i = 0; i < cinemas.size(); i++)
    {
        cinemasOrdDistancia.inserir(&cinemas.at(i));
    }
    cinemasOrdDistancia.ordenar(distancia);

    // Fim do tempo de carregamento da base de dados
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duracaoSeg = end - start;
    cout << "Tempo de carregamento da base de dados: " << duracaoSeg.count() << endl;

    short opcao1 = 0;
    short opcao2 = 0;
    while (opcao1 >= 0 && opcao1 < 3)
    {
        cout << "+------------------------------+" << endl
             << "Buscar por" << endl
             << "1 - Cinema;" << endl
             << "2 - Filme;" << endl
             << "3 - Sair;" << endl
             << endl
             << "Insira opcao: ";
        cin >> opcao1;
        opcao2 = 0;
        if (opcao1 == 1)
        {
            while (opcao2 >= 0 && opcao2 < 8)
            {
            Busca busca;
                cout << "+------------------------------+" << endl
                     << "Filtros de busca" << endl
                     << "1 - Inserir filtro por Tipo;" << endl
                     << "2 - Inserir filtro por Genero;" << endl
                     << "3 - Inserir filtro por Duracao;" << endl
                     << "4 - Inserir filtro por Ano;" << endl
                     << "5 - Inserir filtro por Preco;" << endl
                     << "6 - Inserir filtro por distancia;" << endl
                     << "7 - Realizar busca;" << endl
                     << "8 - Voltar e reiniciar busca;" << endl
                     << endl
                     << "Insira opcao: ";
                cin >> opcao2;
                switch (opcao2)
                {
                case 1:
                {
                    busca.setIsTipo(1);
                    cout << "Insira a quantidade de tipos: ";
                    int quantTipos;
                    cin >> quantTipos;
                    string tipo;
                    for (int i = 0; i < quantTipos; i++)
                    {
                        cout << "Insira o " << i + 1 << "o tipo: ";
                        cin >> tipo;
                        busca.addTipo(tipo);
                    }
                }
                break;
                case 2:
                {
                    busca.setIsGenero(1);
                    cout << "Insira a quantidade de generos: ";
                    int quantGeneros;
                    cin >> quantGeneros;
                    string genero;
                    for (int i = 0; i < quantGeneros; i++)
                    {
                        cout << "Insira o " << i + 1 << "o genero: ";
                        cin >> genero;
                        busca.addGenero(genero);
                    }
                }
                break;
                case 3:
                {
                    busca.setIsDuracao(1);
                    cout << "Insira a duracao minima (min): ";
                    unsigned short duracaoMin, duracaoMax;
                    cin >> duracaoMin;
                    cout << "Insira a duracao maxima (min): ";
                    cin >> duracaoMax;
                    busca.setDuracaoMin(duracaoMin);
                    busca.setDuracaoMax(duracaoMax);
                }
                break;
                case 4:
                {
                    busca.setIsAno(1);
                    cout << "Insira o ano minimo: ";
                    unsigned short anoMin, anoMax;
                    cin >> anoMin;
                    cout << "Insira o ano maximo: ";
                    cin >> anoMax;
                    busca.setAnoMin(anoMin);
                    busca.setAnoMax(anoMax);
                }
                break;
                case 5:
                {
                    busca.setIsPreco(1);
                    cout << "Insira o preco maximo: ";
                    float precoMax;
                    cin >> precoMax;
                    busca.setPrecoMax(precoMax);
                }
                break;
                case 6:
                {
                    busca.setIsDistancia(1);
                    cout << "Insira a distancia maxima: ";
                    unsigned int distanciaMax;
                    cin >> distanciaMax;
                    busca.setDistanciaMax(distanciaMax);
                }
                break;
                case 7:
                {
                    list<Cinema *> listaCinemas = busca.buscaCinema(tabFilmesTipo, tabFilmesGenero,
                                                                    filmesOrdDuracao, filmesOrdAnoInicio, filmesOrdAnoFim, cinemasOrdPreco, cinemasOrdDistancia);
                    for (Cinema *cinema : listaCinemas)
                    {
                        cout << "+------------------------------+" << endl;
                        cout << *cinema;
                        if (busca.getIsDistancia() == 1)
                            cout << "A " << cinema->getLocalizacao().distancia(meuLocal)
                                 << " metros de voce" << endl;
                    }
                }
                break;
                default:
                    break;
                }
            }
        }
        else if (opcao1 == 2)
        {
            while (opcao2 >= 0 && opcao2 < 6)
            {
            Busca busca;
                cout << "+------------------------------+" << endl
                     << "Filtros de busca" << endl
                     << "1 - Inserir filtro por tipo;" << endl
                     << "2 - Inserir filtro por Genero;" << endl
                     << "3 - Inserir filtro por Duracao;" << endl
                     << "4 - Inserir filtro por Ano;" << endl
                     << "5 - Realizar busca;" << endl
                     << "6 - Voltar e reiniciar busca;" << endl
                     << endl
                     << "Insira opcao2: ";
                cin >> opcao2;
                switch (opcao2)
                {
                case 1:
                {
                    busca.setIsTipo(1);
                    cout << "Insira a quantidade de tipos: ";
                    int quantTipos;
                    cin >> quantTipos;
                    string tipo;
                    for (int i = 0; i < quantTipos; i++)
                    {
                        cout << "Insira o " << i + 1 << "o tipo: ";
                        cin >> tipo;
                        busca.addTipo(tipo);
                    }
                }
                break;
                case 2:
                {
                    busca.setIsGenero(1);
                    cout << "Insira a quantidade de generos: ";
                    int quantGeneros;
                    cin >> quantGeneros;
                    string genero;
                    for (int i = 0; i < quantGeneros; i++)
                    {
                        cout << "Insira o " << i + 1 << "o genero: ";
                        cin >> genero;
                        busca.addGenero(genero);
                    }
                }
                break;
                case 3:
                {
                    busca.setIsDuracao(1);
                    cout << "Insira a duracao minima (min): ";
                    unsigned short duracaoMin, duracaoMax;
                    cin >> duracaoMin;
                    cout << "Insira a duracao maxima (min): ";
                    cin >> duracaoMax;
                    busca.setDuracaoMin(duracaoMin);
                    busca.setDuracaoMax(duracaoMax);
                }
                break;
                case 4:
                {
                    busca.setIsAno(1);
                    cout << "Insira o ano minimo: ";
                    unsigned short anoMin, anoMax;
                    cin >> anoMin;
                    cout << "Insira o ano maximo: ";
                    cin >> anoMax;
                    busca.setAnoMin(anoMin);
                    busca.setAnoMax(anoMax);
                }
                break;
                case 5:
                {
                    list<Filme *> listaFilmes = busca.busca(tabFilmesTipo, tabFilmesGenero,
                                                            filmesOrdDuracao, filmesOrdAnoInicio, filmesOrdAnoFim);
                    for (Filme *filme : listaFilmes)
                    {
                        cout << "+------------------------------+" << endl;
                        cout << *filme;
                    }
                }
                break;

                default:
                    break;
                }
            }
        }
    }
    return 0;
}

void tratarBaseCinema(stringstream &baseCinema, vector<Cinema> &cinemas)
{
    string linhaIgnorada;
    if (getline(baseCinema, linhaIgnorada))
    {
    }

    string linha;
    while (getline(baseCinema, linha))
    {
        if (linha.empty())
        {
            continue;
        }
        stringstream ssLinhaTemporaria(linha);
        Cinema cinema;

        if (ssLinhaTemporaria >> cinema)
        {
            cinemas.push_back(cinema);
        }
    }
}

void tratarBaseFilme(stringstream &baseFilme, vector<Filme> &filmes)
{
    string linhaIgnorada;
    if (getline(baseFilme, linhaIgnorada))
    {
    }

    string linha;
    while (getline(baseFilme, linha))
    {
        if (linha.empty())
        {
            continue;
        }
        stringstream ssLinhaTemporaria(linha);
        Filme filme;

        if (ssLinhaTemporaria >> filme)
        {
            filmes.push_back(filme);
        }
    }
}