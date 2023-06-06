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

void intercala(int p, int q, int r, CsvLine v[]) {
    int *w;
    w = new int[r - p];
    int i = p, j = q;
    int k = 0;

    while(i < q && j < r) {
        if(v[i].time <= v[j].time) {
            w[k++] = v[i++].time;
        } else {
            w[k++] = v[j++].time;
        }
    }

    while(i < q) {
        w[k++] = v[i++].time;
    }
    while(j < r) {
        w[k++] = v[j++].time;
    }
    for(i = p; i < r; i++) {
        v[i].time = w[i - p];
    }
    delete[] w;
}

void mergeSort(int p, int r, CsvLine v[]) {
    if(p < r - 1) {
        int q = (p + r) / 2;
        mergeSort(p, q, v);
        mergeSort(q, r, v);
        intercala(p, q, r, v);
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
    mergeSort(0, 539384, data);
    printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);


    ofstream outputFile;
    outputFile.open("D:\\Airlines_mergeSort.csv");
    for(int j = 0; i < 539384; i++) {
        outputFile << data[i].toString() << endl;
    }

    file.close();
    outputFile.close();
/*     delete[] timeV; */
    delete [] data;

    return 0;
}