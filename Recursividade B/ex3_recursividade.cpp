#include <iostream>

using namespace std;

int pot(int a, int b) {
    int prevValue = a;
    if(b == 0){
        return 1;
    }
    if(b == 1){
        return a;
    }
    while(b != 1){
        a = a * prevValue;
        b--;
    }
    return a;
}

int potRec(int a, int b){
    if(b == 0){
        return 1;
    }
    if(b == 1){
        return a;
    }
    return a * potRec(a, b - 1);
    
}

int main() {

    cout << pot(3, 2) << "\n";
    cout << potRec(3, 2);

    return 0;
}