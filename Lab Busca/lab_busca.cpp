#include <fstream>
#include <iostream>

using namespace std;


typedef struct {
    int ibge;
    char estado[100];
    char uf[50];
    char regiao[100];
    int qtd_municipios;
    char sintaxe[100];
} CsvLine;


int main() {
    FILE *file;
    file = fopen("D:\\Lista_Estados_Brasil_Versao_CSV.csv", "r");

    if(!file) {
        cout << "Erro ao abrir o arquivo" << endl;
        exit(1);
    }
    
    cout << "Arquivo aberto com sucesso" << endl;


    CsvLine csvLine[100];

    int read = 0;
    int records = 0;

    do {
        read = fscanf(file, "%d,%100[^;],%50[^;],%100[^;],%d,%100[^\n]\n", &csvLine[records].ibge, csvLine[records].estado, csvLine[records].uf, csvLine[records].regiao, &csvLine[records].qtd_municipios, csvLine[records].sintaxe);
        if(read == 6) {
            records++;
            cout << "Registro lido com sucesso" << endl;
        }
        if(read == EOF) {
            break;
        }

    }while (read != EOF);

    fclose(file);

    cout << "Total de registros: " << records << endl;

    for(int i = 0; i < records; i++) {
        cout << "Estado: " << csvLine[i].estado << endl;
        cout << "UF: " << csvLine[i].uf << endl;
        cout << "Regiao: " << csvLine[i].regiao << endl;
        cout << "Quantidade de municipios: " << csvLine[i].qtd_municipios << endl;
        cout << "Sintaxe: " << csvLine[i].sintaxe << endl;
        cout << "------------------------" << endl;
    }
    




}



