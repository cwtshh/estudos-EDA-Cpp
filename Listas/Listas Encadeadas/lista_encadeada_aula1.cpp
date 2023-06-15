#include <iostream>

using namespace std;

struct TNo {
    int numero;
    TNo *prox;
};

TNo *incluiCabeça(TNo *l, int n) {
    TNo *novo;
    novo = new TNo();
    novo->numero = n;
    novo->prox = l;
    return novo;
}

int main() {

    TNo *plista;

    return 0;
}