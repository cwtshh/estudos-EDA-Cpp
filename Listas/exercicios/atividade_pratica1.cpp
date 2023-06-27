#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class Cadastro {
    public:
        string CNPJ;
        string RazaoSocial;
        string Cidade;
        string Fone;

        Cadastro(string CNPJ, string RazaoSocial, string Cidade, string Fone) {
            this->CNPJ = CNPJ;
            this->RazaoSocial = RazaoSocial;
            this->Cidade = Cidade;
            this->Fone = Fone;
        }

};


class NoI {
    public:
        Cadastro *Dados;
        NoI *Prox;

        NoI(){}

        NoI(Cadastro *Dados, NoI *Prox) {
            this->Dados = Dados;
            this->Prox = Prox;
        }
};

class NoC {
    public:
        Cadastro *Dados;
        NoC *Ant;
        NoC *Prox;

        NoC(){};

        NoC(Cadastro *Dados, NoC *Prox, NoC *Ant) {
            this->Dados = Dados;
            this->Prox = Prox;
            this->Ant = Ant;
        }
};

class ListaComercio{

    public:
        NoC *Inicio;

        ListaComercio(NoC *Inicio) {
            this->Inicio = Inicio;
        }
};

class NoS {
    public:
        Cadastro *Dados;
        NoS *Ant;
        NoS *Prox;

        NoS(Cadastro *Dados, NoS *Ant, NoS *Prox) {
            this->Dados = Dados;
            this->Ant = Ant;
            this->Prox = Prox;
        }
};

class Descritor {
    public:
        NoS *Inicio;
        int Tamanho;
        NoS *Fim;
        
        Descritor(NoS *Inicio, int Tamanho, NoS *Fim) {
            this->Inicio = Inicio;
            this->Tamanho = Tamanho;
            this->Fim = Fim;
        }
};

void incluiCabecaComercio(NoC *Clista, string CNPJ, string RazaoSocial, string Cidade, string Fone) {
    Cadastro *cadastro = new Cadastro(CNPJ, RazaoSocial, Cidade, Fone);
    NoC *no = new NoC(cadastro, NULL, NULL);

    if(Clista->Ant == NULL) {
        Clista->Prox = no;
    } else {
        no->Prox = Clista->Ant;
        Clista->Ant = no;
    }
}

NoC *incluiCaldaComercio(NoC *Clista, string CNPJ, string RazaoSocial, string Cidade, string Fone) {
    if(Clista == NULL) {
        Cadastro *cadastro = new Cadastro(CNPJ, RazaoSocial, Cidade, Fone);
        NoC *no = new NoC(cadastro, no, no);
        Clista = no;
        return Clista;
    } else {
        NoC *noAux = Clista;
        while(noAux->Prox != NULL) {
            noAux = noAux->Prox;
        }
        Cadastro *cadastro = new Cadastro(CNPJ, RazaoSocial, Cidade, Fone);
        NoC *noNovo = new NoC(cadastro, NULL, NULL);
        noAux->Prox = noNovo;
        return Clista;
    }
}


// INDUSTRIAS

NoI *incluiCaldaIndustria(NoI *Llista, string cnpj, string razao_social, string cidade, string fone) {
    if(Llista == NULL) {
        Cadastro *cadastro = new Cadastro(cnpj, razao_social, cidade, fone);
        NoI *no = new NoI(cadastro, NULL);
        Llista = no;
        return Llista;
    } else {
        NoI *noAux = Llista;
        while(noAux->Prox != NULL) {
            noAux = noAux->Prox;
        }
        Cadastro *cadastro = new Cadastro(cnpj, razao_social, cidade, fone);
        NoI *noNovo = new NoI(cadastro, NULL);
        noAux->Prox = noNovo;
        return Llista;
    }
}

NoI *carregarDadosIndustria() {
    ifstream industria_arquivo;
    industria_arquivo.open("industria.txt");
    if(!industria_arquivo) {
        cout << "Erro ao abrir o arquivo" << endl;
        return NULL;
    }

    string line = "";

    NoI *Llista = new NoI(NULL, NULL);
    
    while(getline(industria_arquivo, line)) {
        string cnpj, razao_social, cidade, fone;

        stringstream inputString(line);

        getline(inputString, cnpj, ' ');
        getline(inputString, razao_social, ' ');
        getline(inputString, cidade, ' ');
        getline(inputString, fone, ' ');

        incluiCaldaIndustria(Llista, cnpj, razao_social, cidade, fone);
    }

    return Llista;
}


NoC *carregarDadosComercio() {
     /* Abre o arquivo e dispara erro caso ocorra algum problema */
    ifstream comercio_arquivo;
    comercio_arquivo.open("comercio.txt");
    if(!comercio_arquivo) {
        cout << "Erro ao abrir o arquivo" << endl;
        return NULL;
    }
    
    /* Cadastro dos comercios */
    string line = "";

    NoC *Clista = new NoC(NULL, NULL, NULL);

    while(getline(comercio_arquivo, line)) {
        string cnpj, razao_social, cidade, fone;

        stringstream inputString(line);


        getline(inputString, cnpj, ' ');
        getline(inputString, razao_social, ' ');
        getline(inputString, cidade, ' ');
        getline(inputString, fone, ' ');

        incluiCaldaComercio(Clista, cnpj, razao_social, cidade, fone);
    }

    comercio_arquivo.close();

    return Clista;
}

void menu() {
    cout << "|| - Secretaria da Fazenda - Distrito Federal - ||" << "\n";
    cout << "|| 1 - Carregar dados                           ||" << "\n";
    cout << "|| 2 - Relatorio - Industrias                   ||" << "\n";
}



int main() {

    NoC *Clista;
    NoI *Llista;


    int option;

    while(option != 0)  {
        menu();

        cout << "Digite uma opção: ";
        cin >> option;

        switch(option){
            case 1:
                Clista = carregarDadosComercio();
                Llista = carregarDadosIndustria();

                cout << Llista->Dados->CNPJ << endl;
                cout << Llista->Prox->Dados->CNPJ << endl;
                cout << Llista->Prox->Prox->Dados->CNPJ << endl;
                
                break;

            case 2:
                cout << "Funcao nao implementada" << "\n";
                
        }
    }

   


}