#include <iostream>

using namespace std;


int linearSearch(int *v, int num, int tam) {

    for(int i = 0; i < tam; i++) {
        if(v[i] == num) {
            return i;
        }
    }

    return -1;

}


int main() {

    int randomVector[10] = {2, 4, 3, 1, 6, 5, 7, 8, 9};

    cout << linearSearch(randomVector, 20, 10) << endl;

    return 0;
}