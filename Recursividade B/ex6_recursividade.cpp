#include <iostream>

using namespace std;


int maiorElemento(int *a, int b){
    
    if(b == 0){
        return a[b];
    } 
    if()
    else {
        maiorElemento(a, b - 1);
    }


}

int main() {

    int qtd = 4;

    int *vetor = new int[4];

    vetor[0] = 1;
    vetor[1] = 5;
    vetor[2] = 3;
    vetor[4] = 4;

    cout << maiorElemento(vetor, qtd);

    delete[] vetor;
    return 0;
}