#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <time.h>

using namespace std;


int buscaLinear(int *v, int n, int chave) {
    for(int i = 0; i < n; i++) {
        if(chave == v[i]){
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

    int *ibgeId = new int[100];

    int i = 0;

    while(getline(file, line)) {


        int ibge;
        string estado;
        string uf;
        string regiao;
        int qtd_municipios;
        string sintaxe;
        string tempString;

        stringstream inputSting(line);

        getline(inputSting, tempString, ',');
        ibge = atoi(tempString.c_str());
        ibgeId[i] = ibge;

        i++;

        getline(inputSting, estado, ',');
        getline(inputSting, uf, ',');
        getline(inputSting, regiao, ',');


        tempString = "";
        getline(inputSting, tempString, ',');
        qtd_municipios = atoi(tempString.c_str());

        getline(inputSting, sintaxe, ',');
        
        line = "";

    }



    


    for (int j = 1; j < 20; j++) {
        cout << ibgeId[j] << endl;
        
    }

    cout << "\n" << "\n";


    clock_t tStart = clock();
    int pos = buscaLinear(ibgeId, 100, 52);
    printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    cout << "Posicao: " << pos << endl;

    clock_t tStart2 = clock();
    int pos2 = buscaBinaria(ibgeId, 100, 52);
    printf("Time taken: %.2fs\n", (double)(clock() - tStart2)/CLOCKS_PER_SEC);

    cout << "Posicao: " << pos2 << endl;

    file.close();


    delete[] ibgeId;


    return 0;
}