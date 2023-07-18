#include <stdio.h>
#include <stdlib.h>

struct Node {
    int chave;
    struct Node* esquerda;
    struct Node* direita;
};

struct Node* criarNo(int chave) {
    struct Node* novoNo = (struct Node*) malloc(sizeof(struct Node));
    novoNo->chave = chave;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;

    return novoNo;
}

struct Node* inserir(struct Node* raiz, int chave) {
    if(raiz == NULL) {
        return criarNo(chave);
    }

    if(raiz->chave > chave) {
        raiz->esquerda = inserir(raiz->esquerda, chave);
    } else if(raiz->chave < chave) {
        raiz->direita = inserir(raiz->direita, chave);
    }

    return raiz;
}

struct Node* buscar(struct Node* raiz, int chave) {
    if(raiz == NULL || raiz->chave == chave) {
        return raiz;
    }

    if(chave < raiz->chave) {
        return buscar(raiz->esquerda, chave);
    } else {
        return buscar(raiz->direita, chave);
    }
}

int main() {

    struct Node* raiz = NULL;
    int valor, chaveBuscada = 100;
    for(valor = 100; valor <= 200; valor += 10) {
        raiz = inserir(raiz, valor);
    }
    struct Node* resultado = buscar(raiz, chaveBuscada);
    if(resultado != NULL) {
        printf("Chave %d encontrada!\n", chaveBuscada);
    } else {
        printf("Chave %d nao encontrada!\n", chaveBuscada);
    }

    return 0;
}