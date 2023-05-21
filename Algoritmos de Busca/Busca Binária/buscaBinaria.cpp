#include <iostream>
#include <cstdio>
#include <ctime>

using namespace std;


int binarySearch(int *v, int n, int chave) {
    int p, inicio, final, meio;
    inicio = 0;
    final = n + 1;


    while (inicio <= final){
        meio = (inicio + final)/2;

        if(chave == v[meio]){
            return meio;
        }
        if(chave < v[meio]) {
            final = meio - 1;
        }
        else{
            inicio = meio + 1;
        }
        return -1;
    }
    


}


int main() {
    clock_t start;
    double duration;

    start = clock();

    duration = (clock() - start) / (double) CLOCKS_PER_SEC;

    cout << "Durou: " << duration << endl;


    return 0;
}