#include <iostream>
#include <string>


using namespace std;


class No {
    string caracter;
    No* proximo;
};

bool isNumeric(string const &str)
{
    auto it = str.begin();
    while (it != str.end() && std::isdigit(*it)) {
        it++;
    }
    return !str.empty() && it == str.end();
}



int main() {

    string expressao;
    cout << "Digite a expressão: " << "\n";

    cin >> expressao;

    for(int i = 0; i < expressao.length(); i++) {
        if(isNumeric(expressao[i])) {
            cout << "dado numerico" << "\n";
        }
    }




    return 0;
}