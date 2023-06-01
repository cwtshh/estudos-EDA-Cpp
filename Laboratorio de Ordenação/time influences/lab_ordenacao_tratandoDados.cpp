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

void checkPercentage(int delayCount, int totalCount) {
    float percentage = (float)delayCount / (float)totalCount;
    cout << "Percentage of delayed flights: " << percentage * 100 << "%" << endl;
}

void isRelated(CsvLine v[]) {
    int baseLenght = 30;
    int mediumLenght = 60;
    int maxLenght = 430;

    int baseCount = 0;
    int mediumCount = 0;
    int maxCount = 0;


    for(int i = 1; i <= 539384; i++) {
        if(v[i].delay == 1 && v[i].length < baseLenght) {
            baseCount++;
        }
        if(v[i].delay == 1 && v[i].length > baseLenght && v[i].length < mediumLenght) {
            mediumCount++;
        }
        if(v[i].delay == 1 && v[i].length > mediumLenght && v[i].length < maxLenght) {
            maxCount++;
        }
    }

    if(baseCount > mediumCount && baseCount > maxCount) {
        cout << "Short flights are more proun to delays" << endl;
    }
    if(mediumCount > baseCount && mediumCount > maxCount) {
        cout << "Medium flights are more proun to delays" << endl;
    }
    if(maxCount > baseCount && maxCount > mediumCount) {
        cout << "Long flights are more proun to delays" << endl;
    }
}


int main() {

    ifstream file;
    file.open("D:\\AirlinesSortedByTime.csv");

    if(!file){
        cout << "Erro ao abrir o arquivo" << endl;
        return 1;
    }

    CsvLine *data = new CsvLine[539384];

    string line = "";
    int i = 0;

    while(getline(file, line)) {
        int time;
        int length;
        int delay;

        string tempString;

        stringstream inputString(line);

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

    int delayCount = 0;
    int totalDelay = 0;
    for(int i = 0; i < 5; i++) {
        totalDelay++;
        if(data[i].delay == 1) {
            delayCount++;
        }
    }


    cout << "Checking percentages" << endl;
    clock_t t = clock();
    checkPercentage(delayCount, totalDelay);
    printf("Tempo de execucao: %lf \n", (clock() - t) / (double)CLOCKS_PER_SEC);

    cout << "Cheking relations between flight lenght and delays" << endl;
    clock_t t2 = clock();
    isRelated(data);
    printf("Tempo de execucao: %lf \n", (clock() - t2) / (double)CLOCKS_PER_SEC);

   /*  ofstream outfile;
    outfile.open("D:\\AirlinesAnalysis.csv");

    outfile << "Time,Length,Delay" << endl;
    for(int i = 0; i < 539384; i++) {
        outfile << data[i].toString() << endl;
    } */

    file.close();
    delete [] data;

    return 0;
}