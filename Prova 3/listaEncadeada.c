#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *proximo;
};

void inserirNoCauda(struct Node** lista, int novaIdade) {
    struct Node* novoNo = (struct Node*) malloc(sizeof(struct Node));
    struct Node* atual;
    novoNo->data = novaIdade;
    novoNo->proximo = NULL;
    
    if(*lista == NULL) {
        *lista = novoNo;
    } else {
        atual = *lista;
        
        while(atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novoNo;
    }

}

void imprimirLista(struct Node* lista) {
    struct Node* atual = lista;
    
    while(atual != NULL) {
        printf("%d ", atual->data);
        atual = atual->proximo;
    }
}

int main() {
    struct Node* lista = NULL;
    inserirNoCauda(&lista, 25);
    inserirNoCauda(&lista, 30);
    inserirNoCauda(&lista, 35);
    imprimirLista(lista);

    return 0;
}