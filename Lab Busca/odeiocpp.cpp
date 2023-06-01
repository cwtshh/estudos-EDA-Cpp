#include <iostream>

using namespace std;

void desenhaPau(int n) {
    cout << "8";
    for(int i = 0; i <= n; i++) {
        cout << "=";
    }
    cout << "D";
}

int main() {
    desenhaPau(100);
}
