#include <iostream>

using namespace std;

int produto(int a, int b){
    int prevValue = a;
    while (b != 1)
    {
        a = a + prevValue;
        b--;
    }
    

    return a;
    
}

int produtoRec(int a, int b){
    if(b == 0){
        return 0;
    } else if(b == 1){
        return a;
    } else {
        return a + produtoRec(a, b - 1);
    }

}


int main() {

   cout << produto(2, 3) << "\n";
   cout << produtoRec(2, 3);

}