#include "TabelaHashFilmesTipo.hpp"
#include <vector>
#include <list>
#include <string>
#include <iostream>
using namespace std;
TabelaHashFilmesTipo::TabelaHashFilmesTipo(){

}

TabelaHashFilmesTipo::TabelaHashFilmesTipo(int tamanho){
    tabela.resize(tamanho);
}

unsigned int TabelaHashFilmesTipo::calcularHash(std::string str){
    unsigned int hash = 0;
    for(char c : str){
        hash += c;
    }
    return hash % tabela.size();
}

bool TabelaHashFilmesTipo::inserir(Filme* filme){
    unsigned int hash = calcularHash(filme->getTipo());
    
    // Confere se a hash e valida
    if(hash >= 0 && (hash < tabela.size())){
        tabela[hash].push_back(filme);
        return true;
    }
    cout << "Erro: Hash " << hash << "esta fora dos limites da tabela" << endl;
    return false;
}

std::list<Filme*> TabelaHashFilmesTipo::buscar(unsigned int hash)
{
    return tabela.at(hash);
}