#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <time.h>


using namespace std;

class CsvLine{
    public:
        int time;
        int length;
        int delay;

        CsvLine(){};

        CsvLine(int time, int length, int delay) {
            this->time = time;
            this->length = length;
            this->delay = delay;
        };

        void showLine() {
            cout << "Time: " << time << endl;
            cout << "Length: " << length << endl;
            cout << "Delay: " << delay << endl;
        };

        string toString() {
            string line = to_string(time)+ "," + to_string(length) + "," + to_string(delay);
            return line;
        };
};

int smallerIndex(CsvLine v[], int tam, int ini) {
    int min = ini, j;
    for(j = ini + 1; j < tam; j++) {
        if(v[j].time < v[min].time) {
            min = j;
        }
    }
}

void selectionSort(CsvLine v[], int tam) {
    int i, min, aux;

    for(i = 0; i < tam; i++) {
        min = smallerIndex(v, tam, i);
        aux = v[i].time;
        v[min].time = aux;
    }
}


int main() {

    ifstream file;
    file.open("D:\\Airlines.csv");

    if(!file){
        cout << "Erro ao abrir o arquivo" << endl;
        return 1;
    }

    cout << sizeof(char) << "\n";
    cout << sizeof(int) << "\n";

    CsvLine *data = new CsvLine[539384];



    string line = "";
    int i = 0;

    while(getline(file, line)) {


        string id;
        string airline;
        string flight;
        string airportFrom;
        string airportTo;
        string dayOfWeek;
        int time;
        int length;
        int delay;

        string tempString;

        stringstream inputString(line);


        getline(inputString, id, ',');
        getline(inputString, airline, ',');
        getline(inputString, tempString, ',');
        getline(inputString, airportFrom, ',');
        getline(inputString, airportTo, ',');
        getline(inputString, dayOfWeek, ',');


        tempString = "";
        getline(inputString, tempString, ',');
        time = atoi(tempString.c_str());

        tempString = "";
        getline(inputString, tempString, ',');
        length = atoi(tempString.c_str());

        tempString = "";
        getline(inputString, tempString, ',');
        delay = atoi(tempString.c_str());
        
        CsvLine newLine = CsvLine(time, length, delay);

        data[i] = newLine;

        i++;
    }

    for(int i = 0; i < 5; i++) {
        data[i].showLine();
    }


    cout << "Ordenando o vetor..." << endl;
    clock_t tStart = clock();
    selectionSort(data, 539384);
    printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);


    file.close();
/*     delete[] timeV; */
    delete [] data;

    return 0;
}