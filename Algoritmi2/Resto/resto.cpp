#include <iostream>
#include <fstream>
#include <string>
using namespace std;
ifstream in;
ofstream out;

int minimo(int **matrix,int n,int m, int r){
    int min = matrix[r][0];
    for(int i=1;i<m;i++){
        if(matrix[r][i] < min){
            min = matrix[r][i];
        }
    }
    return min;
}


int Resto(int *tagli, int numT, int resto){
    int **matrix;
    int r = resto+1;
    matrix = new int*[r];
    for(int i=0;i<r;i++){
        matrix[i] = new int [numT];
    }

    for(int i=0;i<r;i++){
        for(int j=0;j<numT;j++){

            //cout<<"confrontiamo: "<<i<<" - "<<tagli[j]<<" risultato: ";
            if(tagli[j]>i){
                matrix[i][j] = 2000;
                //cout<<2000<<endl;
            }

            else if(tagli[j] == i){
                matrix[i][j] = 1;
                //cout<<1<<endl;
            }

            else if(tagli[j]<i){
                int temp = i - tagli[j];
                int S = minimo(matrix,r,numT,temp)+1;
                matrix[i][j] = S;
                //cout<<S<<endl;
            }
        }
    }

    return minimo(matrix,r,numT,r-1);
}

int main(){
    in.open("input.txt");
    out.open("output.txt");

    for(int task=0;task<100;task++){
        int r;
        in>>r;
        int numT;
        in>>numT;
        int *tagli=new int[numT];
        for(int i=0;i<numT;i++){
            int temp;
            in>>temp;
            tagli[i] = temp;
        }

        out<<Resto(tagli,numT,r)<<endl;
        
    }
}