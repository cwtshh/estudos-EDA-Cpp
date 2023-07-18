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

// SERVICOS
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

        Descritor(){}
        
        Descritor(NoS *Inicio, int Tamanho, NoS *Fim) {
            this->Inicio = Inicio;
            this->Tamanho = Tamanho;
            this->Fim = Fim;
        }
};

// METODOS DE SERVICO
void incluiCaldaServico(NoS *sLista, Descritor *descritor, string cnpj, string razaoSocial, string cidade, string fone) {
    NoS *pNovoNoS, *pAux;

    Cadastro *cadastro = new Cadastro(cnpj, razaoSocial, cidade, fone);

    if(sLista == NULL) {
        pNovoNoS->Dados = cadastro;
        pNovoNoS->Ant = NULL;
        pNovoNoS->Prox = NULL;

        sLista = pNovoNoS;

        descritor->Inicio = sLista;
        descritor->Tamanho = 1;
        descritor->Fim = sLista;
        
    } else {
        pAux = sLista;
        while(pAux->Prox != NULL) {
            pAux = pAux->Prox;
        }
        pNovoNoS->Dados = cadastro;
        pNovoNoS->Ant = pAux;
        pNovoNoS->Prox = NULL;

        pAux->Prox = pNovoNoS;

        descritor->Inicio = sLista;
        descritor->Fim = pNovoNoS;
        descritor->Tamanho++;
    }
}

void carregarDadosServicos(NoS *sLista, Descritor *descritor) {
    ifstream servicos_arquivo;
    servicos_arquivo.open("servicos.txt");
    if(!servicos_arquivo) {
        cout << "Erro ao abrir o arquivo" << endl;
        return;
    }

    string line = "";

    while(getline(servicos_arquivo, line)) {
        string cnpj, razaoSocial, cidade, fone;

        stringstream inputString(line);

        getline(inputString, cnpj, ' ');
        getline(inputString, razaoSocial, ' ');
        getline(inputString, cidade, ' ');
        getline(inputString, fone, ' ');

        incluiCaldaServico(sLista, descritor, cnpj, razaoSocial, cidade, fone);
    }
}





// INDUSTRIA
NoI *incluiCaldaIndustria(NoI *iLista, string cnpj, string razaoSocial, string cidade, string fone) {
    NoI *pNovoNoI, *pAux;

    Cadastro *cadastro = new Cadastro(cnpj, razaoSocial, cidade, fone);
    pNovoNoI = new NoI(cadastro, nullptr);

    if(iLista == NULL) {
        iLista = pNovoNoI;
        return iLista;
    } else {
        pAux = iLista;
        while(pAux->Prox != NULL) {
            pAux = pAux->Prox;
        }
        pAux->Prox = pNovoNoI;
        return iLista;
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

    NoI *iLista = NULL;

    while(getline(industria_arquivo, line)) {
        string cnpj, razaoSocial, cidade, fone;

        stringstream inputString(line);

        getline(inputString, cnpj, ' ');
        getline(inputString, razaoSocial, ' ');
        getline(inputString, cidade, ' ');
        getline(inputString, fone, ' ');

        iLista = incluiCaldaIndustria(iLista, cnpj, razaoSocial, cidade, fone);
        
    }

    industria_arquivo.close();
    return iLista;
}

// COMERCIO

NoC *incluiCaldaComercio(NoC *cLista, string cnpj, string razaoSocial, string cidade, string fone) {
    NoC *pAux;
    Cadastro *cadastro = new Cadastro(cnpj, razaoSocial, cidade, fone);

    if(cLista == NULL) {   
        NoC *pNovoNoC = new NoC(cadastro, NULL, NULL);
        pNovoNoC->Ant = pNovoNoC;
        pNovoNoC->Prox = pNovoNoC;

        cLista = pNovoNoC;
        return cLista;
    }

    pAux = cLista;
    while(pAux->Prox != cLista) {
        /* cout << pAux->Dados->CNPJ << endl; */
        pAux = pAux->Prox;
    }
    NoC *pNovoNoC = new NoC(cadastro, NULL, NULL);
    pAux->Prox = pNovoNoC;
    pNovoNoC->Ant = pAux;
    pNovoNoC->Prox = cLista;
    
    return cLista;
}

NoC *carregarDadosComercio() {
    ifstream comercio_arquivo;
    comercio_arquivo.open("comercio.txt");
    if(!comercio_arquivo) {
        cout << "Erro ao abrir o arquivo" << endl;
        return NULL;
    }

    string line = "";
    NoC *cLista = NULL;

    while(getline(comercio_arquivo, line)) {
        string cnpj, razaoSocial, cidade, fone;

        stringstream inputString(line);

        getline(inputString, cnpj, ' ');
        getline(inputString, razaoSocial, ' ');
        getline(inputString, cidade, ' ');
        getline(inputString, fone, ' ');

        cLista = incluiCaldaComercio(cLista, cnpj, razaoSocial, cidade, fone);
    }

    comercio_arquivo.close();
    return cLista;
}



void menu() {
    cout << "|| - Secretaria da Fazenda - Distrito Federal - ||" << "\n";
    cout << "|| 1 - Carregar dados                           ||" << "\n";
    cout << "|| 2 - Gerar Lista Unificada                    ||" << "\n";
    cout << "|| 3 - Relatorio - Industrias                   ||" << "\n";
    cout << "|| 4 - Relatorio - Comercios                    ||" << "\n";
    cout << "|| 5 - Relatorio - Servicos                     ||" << "\n";
    cout << "|| 10 - Apagar Listas                           ||" << "\n";
    cout << "|| 0 - Sair                                     ||" << "\n";
}

void printIndustrias(NoI *iLista) {
    NoI *pAux;
    pAux = iLista;
    
    while(pAux->Prox != NULL) {
        cout << "CNPJ: " << pAux->Dados->CNPJ << "\n";
        cout << "Razao Social: " << pAux->Dados->RazaoSocial << "\n";
        cout << "Cidade: " << pAux->Dados->Cidade << "\n";
        cout << "Telefone: " << pAux->Dados->Fone << "\n";
        cout << "\n";

        pAux = pAux->Prox;
    }

}

void printComercios(NoC *cLista) {
    NoC *pAuxC;
    pAuxC = cLista;

    while(pAuxC->Prox != cLista) {
        cout << "CNPJ: " << pAuxC->Dados->CNPJ << "\n";
        cout << "Razao Social: " << pAuxC->Dados->RazaoSocial << "\n";
        cout << "Cidade: " << pAuxC->Dados->Cidade << "\n";
        cout << "Telefone: " << pAuxC->Dados->Fone << "\n";
        cout << "\n";

        pAuxC = pAuxC->Prox;
    }

}

void printServicos(NoS *sLista) {
    NoS *pAuxS;
    pAuxS = sLista;

    while(pAuxS->Prox != NULL) {
        cout << "CNPJ: " << pAuxS->Dados->CNPJ << "\n";
        cout << "Razao Social: " << pAuxS->Dados->RazaoSocial << "\n";
        cout << "Cidade: " << pAuxS->Dados->Cidade << "\n";
        cout << "Telefone: " << pAuxS->Dados->Fone << "\n";
        cout << "\n";

        pAuxS = pAuxS->Prox;
    }
}


NoI *deletarIndustrias(NoI *iLista) {
    NoI *pAuxiProx = iLista;
    NoI *pAuxAtual = NULL;
    while(pAuxiProx->Prox != NULL) {
        pAuxAtual = pAuxiProx;
        pAuxiProx = pAuxiProx->Prox;
        delete[] pAuxAtual;
    }
    iLista = NULL;
    return iLista;
}

NoC *deletarComercio(NoC *cLista) {
    NoC *pAuxcProx = cLista;
    NoC *pAuxcAtual = NULL;
    while(pAuxcProx->Prox != cLista) {
        pAuxcAtual = pAuxcProx;
        pAuxcProx = pAuxcProx->Prox;
        delete[] pAuxcAtual;
        pAuxcAtual = NULL;
    }

    cLista = NULL;
    return cLista;
}



int main() {


    NoI *iLista = NULL;
    NoC *cLista = NULL;
    NoS *sLista = NULL;
    Descritor *descritor = new Descritor(NULL, 0, NULL);

    int option;
    while( option != 0 ) {
        menu();
        cout << "Digite a opcao desejada: " << "\n";
        cin >> option;
        

        switch(option) {
            case 1:
                cout << "Carregando dados..." << "\n";
                iLista = carregarDadosIndustria();
                cLista = carregarDadosComercio();
                carregarDadosServicos(sLista, descritor);

                break;

            case 3:
                cout << "Relatorio - Industrias" << "\n";

                if(iLista == NULL) {
                    cout << "Nâo ha industrias cadastradas" << "\n";
                    cout << "Carregue os dados ou reinicie o programa" << "\n";
                    break;
                }

                printIndustrias(iLista);
                break;

            case 4:
               cout << "Relatorio - Comercio" << "\n";

               if(cLista == NULL) {
                    cout << "Nao ha comercios cadastrados" << "\n";
                    cout << "Carregue os dados ou reinicie o programa" << "\n";
                    break;
                }
                printComercios(cLista);
                break;

            case 5:
                cout << "Relatorio - Servicos" << "\n";

                if(descritor->Inicio == NULL && descritor->Fim == NULL) {
                    cout << "Nao ha sercivos cadastrados" << "\n";
                    cout << "Carregue os dados ou reinicie o programa" << "\n";
                    break;
                }
                printServicos(sLista);
                break;

            case 10:
                cout << "Apagando listas..." << "\n";

                if(iLista == NULL || cLista == NULL) {
                    cout << "Nao ha listas para apagar" << "\n";
                    break;
                }

                iLista = deletarIndustrias(iLista);
                cLista = deletarComercio(cLista);
                break;


            case 0:
                cout << "Saindo..." << "\n";
                break;
        }

    }


    return 0;
}