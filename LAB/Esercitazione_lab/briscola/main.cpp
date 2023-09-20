#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

int findMax(int *vect, int vectSize){
    int max = 0;

    for (int i = 0; i < vectSize; i++) {
        if(vect[i] > max){
            max = vect[i];
        }
    }

    return max;
}

void extendResult(int *vect, int vectSize, int result){

    for (int i = result; i < vectSize-1; i++) 
       vect[i+1] = vect[i]; 
}


int main(){

    for (int task = 0; task < 100; task++) {
        
        int numeroPartite, sommaPosseduta;

        in >> numeroPartite >> sommaPosseduta;
        int giorno[numeroPartite], inizio[numeroPartite], fine[numeroPartite], tassa[numeroPartite], vincita[numeroPartite];

        for (int i = 0; i < numeroPartite; i++) 
            in >> giorno[i] >> inizio[i] >> fine[i] >> tassa[i] >> vincita[i];

        int optimalVectSize = 24*(findMax(giorno, numeroPartite)+1);

        int optimal[optimalVectSize];
        for (int i = 0; i < optimalVectSize; i++)
            optimal[i] = sommaPosseduta;


        for (int actualTime = 1; actualTime < optimalVectSize; actualTime++) {
            for (int i = 0; i < numeroPartite; i++) {
                if (giorno[i] * 24 + fine[i] <= actualTime && tassa[i] <= optimal[giorno[i] * 24 + inizio[i]] && optimal[actualTime] < optimal[giorno[i] * 24 + inizio[i]] + vincita[i] - tassa[i]) {
                    optimal[giorno[i] * 24 + fine[i]] = optimal[giorno[i] * 24 + inizio[i]] + vincita[i] - tassa[i];
                    extendResult(optimal, optimalVectSize, giorno[i] * 24 + fine[i]);
                }
            }
        }

        out << optimal[optimalVectSize-1] << endl;
    }
}