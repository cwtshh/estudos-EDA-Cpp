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
        int Dados;
        NoI *Prox;

        NoI(int Dados, NoI *Prox) {
            this->Dados = Dados;
            this->Prox = Prox;
        }
};

class NoC {
    public:
        Cadastro *Dados;
        NoC *Ant;
        NoC *Prox;

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
    /* Cadastro *cadastro = new Cadastro(CNPJ, RazaoSocial, Cidade, Fone);
    NoC *noAux;
    NoC *no = new NoC(cadastro, NULL, NULL);
    noAux = Clista;

    while(noAux->Prox != NULL) {
       noAux = noAux->Prox;
    }
    noAux->Prox = no;
    return Clista; */

    if(Clista == NULL) {
        Cadastro *cadastro = new Cadastro(CNPJ, RazaoSocial, Cidade, Fone);
        NoC *no = new NoC(cadastro, no, no);
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


void carregarDados() {
     /* Abre o arquivo e dispara erro caso ocorra algum problema */
    ifstream comercio_arquivo;
    comercio_arquivo.open("comercio.txt");
    if(!comercio_arquivo) {
        cout << "Erro ao abrir o arquivo" << endl;
        return;
    }

    /* Abre o arquivo e dispara erro caso ocorra algum problema */
    ifstream industria_arquivo;
    industria_arquivo.open("industria.txt");
    if(!industria_arquivo) {
        cout << "Erro ao abrir o arquivo" << endl;
        return;
    }

    /* Abre o arquivo e dispara erro caso ocorra algum problema */
    ifstream servico_arquivo;
    servico_arquivo.open("servico.txt");
    if(!servico_arquivo) {
        cout << "Erro ao abrir o arquivo" << endl;
        return;
    }
    
    /* Cadastro dos comercios */
    string line = "";
    int count = 0;

    NoC *Clista = new NoC(NULL, NULL, NULL);

    while(getline(comercio_arquivo, line)) {
        string cnpj, razao_social, cidade, fone;

        stringstream inputString(line);


        getline(inputString, cnpj, ' ');
        getline(inputString, razao_social, ' ');
        getline(inputString, cidade, ' ');
        getline(inputString, fone, ' ');

        if(count == 0) {
            incluiCabecaComercio(Clista, cnpj, razao_social, cidade, fone);
        } else {
            incluiCaldaComercio(Clista, cnpj, razao_social, cidade, fone);
        }
        
        count = 1;

        cout << cnpj << " " << razao_social << " " << cidade << " " << fone << endl;
    }

    comercio_arquivo.close();
    industria_arquivo.close();
    servico_arquivo.close();
}

void menu() {
    cout << "|| Secretaria da Fazenda - Distrito Federal ||" << "\n";
    cout << "|| 1 - Carregar dados                      ||" << "\n";
}



int main() {

    ListaComercio *CLista = new ListaComercio(NULL);


    int option;

    while(option != 0)  {
        menu();

        cout << "Digite uma opção: ";
        cin >> option;

        switch(option){
            case 1:
                carregarDados();
                break;
        }
    }

   


}