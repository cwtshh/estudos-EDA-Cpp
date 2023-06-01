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


int buscaLinear(int *v, int n, int chave) {
    for(int i = 0; i < n; i++) {
        if(chave == v[i]) {
            return i;
        }
    }
    return -1;
}

int buscaBinaria(int *v, int n, int chave) {
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
    file.open("D:\\Lista_Estados_Brasil_Versao_CSV.csv");
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

    file.close();

    /* for(int j = 0; j < 28; j++) {
        cout << ibgeIds[j] << endl;
    } */

    ifstream file2;
    file.open("D:\\Lista_Estados_Brasil_Versao_CSV.csv");

    int lineNumber = 3;
    int lineCount = 0;
    string linha = "";

    Data csvLine = Data();

    while(getline(file2, linha)) {
        lineCount++;
        cout << "Lendo a linha: " << endl;

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
        csvLine.ibgeId = ibge;
        

        /* RECEBE AS STRINGS*/
        getline(inputString, estados, ';');
        csvLine.estado = estados;
        
        getline(inputString, ufs, ';');
        csvLine.uf = ufs;

        getline(inputString, regioes, ';');
        csvLine.regiao = regioes;


        tempString = "";
        getline(inputString, tempString, ';');
        qtd_municipio = atoi(tempString.c_str());
        csvLine.qtd_municipios = qtd_municipio;

        getline(inputString, sintaxes, ';');
        csvLine.sintaxe = sintaxes;

        if(lineCount == lineNumber) {
            break;
        }
    }

    csvLine.showData();


    delete[] ibgeIds;
    file.close();



    return 0;
}