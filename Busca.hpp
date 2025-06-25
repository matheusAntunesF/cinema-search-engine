#ifndef BUSCA_HPP
#define BUSCA_HPP
#include <vector>
#include <string>
#include <list>
#include "Filme.hpp"
#include "TabelaHashFilmesTipo.hpp"
#include "TabelaHashFilmesGenero.hpp"
#include "ListaFilmesOrdenada.hpp"

class Busca
{
private:
    bool isTipo;
    std::vector<std::string> tipos;
    bool isGenero;
    std::vector<std::string> generos;
    bool isDuracao;
    unsigned short duracaoMin;
    unsigned short duracaoMax;
    bool isAno;
    unsigned short anoMin;
    unsigned short anoMax;

public:
    Busca();
    Busca(
        bool IsTipo,
        bool IsGenero,
        bool IsDuracao,
        bool IsAno);

    // Getters
    bool getIsTipo() const;
    std::vector<std::string> getTipos() const;
    bool getIsGenero() const;
    std::vector<std::string> getGeneros() const;
    bool getIsDuracao() const;
    unsigned short getDuracaoMin() const;
    unsigned short getDuracaoMax() const;
    bool getIsAno() const;
    unsigned short getAnoMin() const;
    unsigned short getAnoMax() const;

    // Setters
    void setIsTipo(bool isTipo);
    void setTipos(const std::vector<std::string> &tipos);
    void setIsGenero(bool isGenero);
    void setGeneros(const std::vector<std::string> &generos);
    void setIsDuracao(bool isDuracao);
    void setDuracaoMin(unsigned short duracaoMin);
    void setDuracaoMax(unsigned short duracaoMax);
    void setIsAno(bool isAno);
    void setAnoMin(unsigned short anoInicio);
    void setAnoMax(unsigned short anoFim);

    // -- Métodos de conveniência ---
    void addTipo(const std::string &tipo);
    void addGenero(const std::string &genero);

    // Métodos de buscas
    std::list<Filme *> buscaTipo(TabelaHashFilmesTipo &tabFilmesTipo);
    std::list<Filme *> buscaGenero(TabelaHashFilmesGenero &tabFilmesGenero);
    std::list<Filme *> buscaDuracao(ListaFilmesOrdenada &filmesOrdDuracao);
    std::list<Filme *> buscaAnoInicio(ListaFilmesOrdenada &filmesOrdAnoInicio);
    std::list<Filme *> buscaAnoFim(ListaFilmesOrdenada &filmesOrdDuracao);

    std::list<Filme *> busca(TabelaHashFilmesTipo &tabFilmesTipo,
                             TabelaHashFilmesGenero &tabFilmesGenero, ListaFilmesOrdenada &filmesOrdDuracao,
                            ListaFilmesOrdenada& filmesOrdAnoInicio, ListaFilmesOrdenada& filmesOrdAnoFim);
};

#endif