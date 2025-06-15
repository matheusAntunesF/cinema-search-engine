#ifndef FILME_HPP
#define FILME_HPP
#include <string>
#include <vector>

class Filme
{
private:
    unsigned int id;
    std::string tipo;
    std::string tituloPrimario;
    std::string tituloOriginal;
    bool isAdult;
    unsigned short anoInicio;
    unsigned short anoFim;
    unsigned short duracao;
    std::vector <std::string> genero;
public:
    void setId(unsigned int id);
    unsigned int getId() const;
    void setTipo(std::string tipo);
    std::string getTipo() const;
    void setTituloPrimario(std::string tituloPrimario);
    std::string getTituloPrimario() const;
    void setTituloOriginal(std::string tituloOriginal);
    std::string getTituloOriginal() const;
    void setIsAdult(bool isAdult);
    bool getIsAdult() const;
    void setAnoInicio(unsigned short anoInicio);
    unsigned short getAnoInicio() const;
    void setAnoFim(unsigned short anoFim);
    unsigned short getAnoFim() const;
    void setDuracao(unsigned short duracao);
    unsigned short getDuracao() const;
    void setGenero(std::vector <std::string> genero);
    std::vector <std::string> getGenero() const;
};
#endif