#ifndef LISTAS_H
#define LISTAS_H

#include <stdio.h>
#include <string>

using namespace std;


//Dados de cadastros das empresas:
class TCadastro {
    public: 
        string CNPJ;
        string RazaoSocial;
        string Cidade;
        string Fone;

        TCadastro(string CNPJ, string RazaoSocial, string Cidade, string Fone) {
            this->CNPJ = CNPJ;
            this->RazaoSocial = RazaoSocial;
            this->Cidade = Cidade;
            this->Fone = Fone;
        }
};


//Nó da lista simplesmente encadeada (Indústria):
class TNoI {
    public:
        TCadastro *Dados;
        TNoI *Prox;

        TNoI(TCadastro *Dados, TNoI *Prox) {
            this->Dados = Dados;
            this->Prox = Prox;
        }
};

//Nó da lista duplamente encadeada circular (Comércio):

class TNoC {
    public: 
        TCadastro *Dados;
        TNoC *Ant;
        TNoC *Prox;
        
        TNoC(TCadastro *Dados, TNoC *Ant, TNoC *Prox) {
            this->Dados = Dados;
            this->Ant = Ant;
            this->Prox = Prox;
        }
};

//Nó da lista duplamente encadeada com descritor (Empresas de Serviços):

class TNos {
    public:
        TCadastro *Dados;
        TNoS *Ant;
        TNoS *Prox;

        TNos(TCadastro *Dados, TNoS *Ant, TNoS *Prox) {
            this->Dados = Dados;
            this->Ant = Ant;
            this->Prox = Prox;
        }
};

class TDescritorSs {
    public:
        TNoS *Inicio;
        int Tamanho;
        TNoS *Fim;

        TDescritorSs(TNoS *Inicio, int Tamanho, TNoS *Fim) {
            this->Inicio = Inicio;
            this->Tamanho = Tamanho;
            this->Fim = Fim;
        }
};



/* Dados de cadastro para a lista */

class TCadastroU {
    public:
        string CNPJ;
        string RazaoSocial;
        string Cidade;
        string Fone;
        char Tipo;

        TCadastroU(string CNPJ, string RazaoSocial, string Cidade, string Fone, char Tipo) {
            this->CNPJ = CNPJ;
            this->RazaoSocial = RazaoSocial;
            this->Cidade = Cidade;
            this->Fone = Fone;
            this->Tipo = Tipo;
        }
};

class TNoU {
    public:
        TCadastroU *Dados;
        TNoU *Ant;
        TNoU *Prox;

        TNoU(TCadastroU *Dados, TNoU *Ant, TNoU *Prox) {
            this->Dados = Dados;
            this->Ant = Ant;
            this->Prox = Prox;
        }
};

class TDescritorU {
    public:
        TNoU *Inicio;
        int Tamanho;
        TNoU *Fim;

        TDescritorU(TNoU *Inicio, int Tamanho, TNoU *Fim) {
            this->Inicio = Inicio;
            this->Tamanho = Tamanho;
            this->Fim = Fim;
        }
};

#endif
