#include <iostream>

using namespace std;


struct TNo {
    int num;
    TNo *prox;
};

bool Vazia(TNo *pLista) {
    if(pLista == NULL) {
        return true;
    } else {
        return false;
    }
}

/* Adiciona um elemento ao inicio da lista */
TNo *incluiCabeca(TNo *pLista, int pValor) {

    if(Vazia(pLista) == true) {
        return NULL;
    }

    /* Cria um novo ponteiro para a posicao */
    TNo *pNovoNo;
    /* Aloca memória para este ponteiro */
    pNovoNo = new TNo();
    /* Atribui o valor ao ponteiro */
    pNovoNo->num = pValor;
    pNovoNo->prox = pLista;
    /* Atribui o valor do ponteiro antigo ao novo */
    pLista = pNovoNo;

    /* Retorna a nova primeira posicao */
    return pLista;
}

TNo *incluiCalda(TNo *pLista, int pValor) {

    if(Vazia(pLista) == true) {
        return NULL;
    }
    /* Cria um novo ponteiro para a posicao */
    TNo *pNovoNo, *pAux;
    /* Aloca memoria para esse ponteiro */
    pNovoNo = new TNo();

    /* Associa novos valores ao ultimo elemento */
    pNovoNo->num = pValor;
    /* 
        !!IMPORTANTE!! o ponteiro para a proxima posicao deve ser null,
        pois nao existe um proxumo elemento
     */
    pNovoNo->prox = NULL;
    pAux = pLista;
    pAux->prox = pNovoNo;

    /* O poneiro auxiliar se torna a lista */
    pAux = pLista;

    /* procura o elemento q tem a proxima posicao como NULL */
    while(pAux->prox != NULL) {
        pAux = pAux->prox;
    }

    /* Associa o novo elemento a ultima posicao */
    pAux->prox = pNovoNo;

    return pLista;

}

TNo *incluiAntes(TNo *pLista, int pChave, int pValor) {

    if(Vazia(pLista) == true) {
        return NULL;
    }

    TNo *pNovoNo, *pAux;
    pNovoNo = new TNo();

    /* Associa os valores ao novo ponteiro */
    pNovoNo->num = pValor;
    pAux = pLista;

    /* procura uma posicao vazia */
    while(pAux->prox->num != pChave) {
        pAux = pAux->prox;
    }

    /* Associa o novo elemento a posicao anterior a chave */
    pNovoNo->prox = pAux->prox;
    pAux->prox = pNovoNo;

    /* Retorna o novo ponteiro */
    return pLista;
}


int main() {



    return 0;
}