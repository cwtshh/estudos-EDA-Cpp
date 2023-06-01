#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <time.h>
#include <vector>


using namespace std;

int separa(int v[], int p, int r) {
    int c = v[r];
    int t, j = p;
    for(int k = p; k < r; k++) {
        if(v[k] <= c) {
            t = v[j], v[j] = v[k], v[k] = t;
            j++;
        }

    }
    t = v[j], v[j] = v[r], v[r] = t;
    return j;
}

void quickSort(int v[], int p, int r) {
    if(p < r) {
        int j = separa(v, p, r);
        quickSort(v, p, j - 1);
        quickSort(v, j + 1, r);
    }
}

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
};

int main() {

    ifstream file;
    file.open("D:\\Airlines.csv");

    string firtstline = "id,Airline,Flight,AirportFrom,AirportTo,DayOfWeek,Time,Length,Delay";

    cout << sizeof("id,Airline,Flight,AirportFrom,AirportTo,DayOfWeek,Time,Length,Delay") << endl;

    cout << sizeof("539383,US,1442,LAX,PHL,5") << endl;

    cout << "Tamanho do 300:" <<sizeof("300") << endl;


   /*  char *TimeBuffer = new char[100]; */
    char firstLine[68];
    char time[4];

    /* 5, 2, 4, 3, 3, 1, 4, 3, 1 */

    /* 25 bytes para pular */

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


    cout << "Ordenando o vetor..." << endl;
    clock_t tStart = clock();
    quickSort(data->time, 0, 539384 - 1);
    printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    ofstream outfile;
    outfile.open("D:\\AirlinesSorted.csv");

    for(int i = 0; i < 539384; i++) {
        outfile << timeV[i] << endl;
    }


    file.close();
    delete[] timeV;
    delete [] data;



    




    return 0;
}