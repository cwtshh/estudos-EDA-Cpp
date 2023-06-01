#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <time.h>
#include <vector>

using namespace std;

struct Data {

    public:
    void showData() {
        cout << "IBGE ID: " << ibgeId << endl;
        cout << "Estado: " << estado << endl;
        cout << "UF: " << uf << endl;
        cout << "Regiao: " << regiao << endl;
        cout << "Quantidade de municipios: " << qtd_municipios << endl;
        cout << "Sintaxe: " << sintaxe << endl;
    }


    int ibgeId;
    string estado;
    string uf;
    string regiao;
    int qtd_municipios;
    string sintaxe;
    string tempString;
};


int sequencialSearch(int *v, int n, int chave) {
    for(int i = 0; i < n; i++) {
        if(v[i] == chave) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int *v, int n, int chave) {
    int p, inicio, final, meio;
    inicio = 0;
    final = n - 1;

    while(inicio <= final) {
        meio = (inicio + final) / 2;

        if(chave == v[meio]) {
            return meio;
        } else if(chave < v[meio]) {
            final = meio - 1;
        } else {
            inicio = meio + 1;
        }
    }

    return -1;
}




int main() {

    ifstream file;
    file.open("D:\\Lista_Estados_Brasil_Versao_CSV1.csv");
    string line = "";

    Data *dataCollection = new Data[28];
    int *ibgeIds = new int[28];
    int i = 0;
    
    while(getline(file, line)) {

        int ibge;
        string estados;
        string ufs;
        string regioes;
        int qtd_municipio;
        string sintaxes;

        string tempString;

        stringstream inputString(line);

        /* RECEBE O INTEIRO*/
        getline(inputString, tempString, ';');
        ibge = atoi(tempString.c_str());
        dataCollection[i].ibgeId = ibge;
        ibgeIds[i] = ibge;

        /* RECEBE AS STRINGS*/
        getline(inputString, estados, ';');
        dataCollection[i].estado = estados;

        getline(inputString, ufs, ';');
        dataCollection[i].uf = ufs;

        getline(inputString, regioes, ';');
        dataCollection[i].regiao = regioes;


        tempString = "";
        getline(inputString, tempString, ';');
        qtd_municipio = atoi(tempString.c_str());
        dataCollection[i].qtd_municipios = qtd_municipio;

        getline(inputString, sintaxes, ';');
        i++;
    }

    cout << "Lista de ids: " << endl;

    for(int j = 1; j < 5; j++) {
        dataCollection[j].showData();
        cout << endl;
    }



    cout << "\n";

    clock_t tStart = clock();
    int pos = sequencialSearch(ibgeIds, 28, 52);
    printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    cout << "Posicao 1: " << pos << endl;

    cout << "\n";

    clock_t tStart2 = clock();
    int pos2 = binarySearch(ibgeIds, 28, 52);
    printf("Time taken: %.2fs\n", (double)(clock() - tStart2)/CLOCKS_PER_SEC);
    cout << "Posicao 2: " << pos2 << endl;

    cout << "\n";
    cout << "\n";


    cout << "1 - Estado encontrado: " << dataCollection[pos].estado << endl;
    cout << "2 - Estado encontrado: " << dataCollection[pos2].estado << endl;

    file.close();


    delete[] dataCollection;
    delete[] ibgeIds;


    return 0;
}