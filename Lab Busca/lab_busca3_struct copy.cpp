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
        ibgeIds[i] = ibge;

        /* RECEBE AS STRINGS*/
        getline(inputString, estados, ';');

        getline(inputString, ufs, ';');

        getline(inputString, regioes, ';');

        tempString = "";
        getline(inputString, tempString, ';');
        qtd_municipio = atoi(tempString.c_str());

        getline(inputString, sintaxes, ';');
        i++;
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

    file.close();

    ifstream file2;
    file2.open("D:\\Lista_Estados_Brasil_Versao_CSV1.csv");

    int lineNumber = 0;
    int lineCount = 5;
    string line2 = "";

    Data csvLine = Data();
    while(getline(file2, line2)) {
        lineNumber++;
        cout << "Lendo a linha: " << lineNumber << endl;

        int ibge1;
        string estados1;
        string ufs1;
        string regioes1;
        int qtd_municipio1;
        string sintaxes1;

        string tempString;

        stringstream inputString(line2);

        /* RECEBE O INTEIRO*/
        getline(inputString, tempString, ';');
        ibge1 = atoi(tempString.c_str());
        csvLine.ibgeId = ibge1;

        /* RECEBE AS STRINGS*/
        getline(inputString, estados1, ';');
        csvLine.estado = estados1;


        getline(inputString, ufs1, ';');
        csvLine.uf = ufs1;

        getline(inputString, regioes1, ';');
        csvLine.regiao = regioes1;

        tempString = "";
        getline(inputString, tempString, ';');
        qtd_municipio1 = atoi(tempString.c_str());
        csvLine.qtd_municipios = qtd_municipio1;

        getline(inputString, sintaxes1, ';');
        csvLine.sintaxe = sintaxes1;

        if(lineNumber == lineCount+1) {
            csvLine.showData();
            break;
        }
    }

    file2.close();

    delete[] ibgeIds;


    return 0;
}