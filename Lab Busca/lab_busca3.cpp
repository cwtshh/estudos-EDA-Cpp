#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <time.h>

using namespace std;


int buscaLinear(int *v, int n, int chave) {
    for(int i = 0; i < n; i++) {
        if(chave == v[i]) {
            return i;
        }
    }
    return -1;
}


int main() {


    ifstream file;
    file.open("D:\\municipios_csv.csv");

    if(!file) {
        cout << "Erro ao abrir o arquivo" << endl;
        return 1;
    }

    string line = "";

    int *ibgeId = new int[500];

    int i = 0;

    while(getline(file, line)) {
        
        string concatUf;
        int ibge;
        int ibge7;
        string uf;
        string municipio;
        string regiao;
        string populacao;
        string porte;
        string capital;

        string tempString;

        stringstream inputSting(line);

        getline(inputSting, tempString, ',');
        ibge = atoi(tempString.c_str());
        ibgeId[i] = ibge;
        i++;

        tempString = "";
        getline(inputSting, tempString, ',');
        ibge7 = atoi(tempString.c_str());

        getline(inputSting, uf, ',');
        getline(inputSting, municipio, ',');
        getline(inputSting, regiao, ',');
        getline(inputSting, populacao, ',');
        getline(inputSting, porte, ',');
        getline(inputSting, capital, ',');

        line = "";

    }


    for(int j = 0; j < i; j++) {
        cout << ibgeId[j] << endl;
    }

    cout << "\n\n" << endl;

    clock_t tStart = clock();
    int pos = buscaLinear(ibgeId, i, 3550308);

    delete[] ibgeId;
    file.close();

    return 0;
}