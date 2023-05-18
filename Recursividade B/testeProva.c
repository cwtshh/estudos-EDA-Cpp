#include <stdio.h>

float media(float *pV, int pn) {
    float pM = 0;
    int pInd;
    for(pInd = 0; i < pn; i++){
        pM += pV[pInd];
    }
    return (pM/pn);
}

float media2(float *pV, int pn){
    float *pVaux = pV, pM = 0;
    int pInd;
    for(pInd = 0; pInd < pn; pInd++) {
        pM += *pVaux;
        pVaux++;
    }
    return (pM/pn);
}

int main(){

    int tamanho = 4;

    int *pvalores;

    pvalores = (int*) malloc(sizeof(int) * tamanho);
    pvalores[0] = 3;
    pvalores[1] = 3;
    pvalores[2] = 4;
    pvalores[3] = 3;

    printf("%d \n",media(pvalores, tamanho));
    printf("%d \n", media2(pvalores, tamanho));

    int pvalores1[] = {3,3,4,3};

    printf("%d \n", media(pvalores1, tamanho));
    printf("%d \n", media2(pvalores1, tamanho));





    return 0;
}