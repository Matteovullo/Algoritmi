#include <iostream>
#include <fstream>
#include <string>
using namespace std;
ifstream in;
ofstream out;

void swap(int *vett,int i,int j){
    int temp = vett[i];
    vett[i] = vett[j];
    vett[j] = temp;
}

void sortCoins(int *vett,int size){
    for(int i=0;i<size;i++){
        int min=i;
        for(int j=i;j<size;j++){
            if(vett[j] < vett[min]){
                min = j;
            }
        }
        swap(vett,i,min);
    }
}

int getMin(int **matrix, int n, int m, int line){
    int min = 10000;
    for(int i=0;i<m;i++){
        if(matrix[line][i] < min){
            min = matrix[line][i];
        }
    }
    return min;
}


int getIndexMin(int **matrix, int n, int m, int line){
    int min = 10000;
    int pos = 0;
    for(int i=0;i<m;i++){
        //cout<<"linea: "<<line<<" confrontiamo: "<<matrix[line][i]<<" - "<<min<<" "<<endl;
        if(matrix[line][i] < min){
            min = matrix[line][i];
            pos = i;
        }
    }
    return pos;
} 
/*
void printSeq(int **matrix,int n ,int m,int*coins,int S){

    int line = n-1;
    int Vettcoins[S];
    int i=0;
    while(i < S){
        int min = getMin(matrix,n,m,line);
        Vettcoins[i] = getCoinsMin(matrix,n,m,line,coins);
        line = line - coins[i];
        if(min < 1){
            i = S;
        }
        i++;
    }    
  
    for(int i=0;i<S;i++){
        cout<<Vettcoins[i]<<" ";
    }
}
*/
void change(int r, int *coins, int numCoins){
    sortCoins(coins,numCoins);
    int n = r+1;
    int m = numCoins;
    int **matrix;
    int valCoins[n] = {10000};
    matrix = new int* [n];
    for(int i=0;i<n;i++){
        matrix[i] = new int [m];
    }
    int line=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(coins[j] > i){
                matrix[i][j] = 10000;
            }

            else if(coins[j] == i){
                matrix[i][j] = 1;
            }
            
            else if(coins[j] < i){
                line = i - coins[j];
                matrix[i][j] = getMin(matrix,n,m,line)+1;
                //cout<<getIndexMin(matrix,n,m,line)<<" "<<coins[getIndexMin(matrix,n,m,line)]<<endl;
            }
        }
        valCoins[i] = coins[getIndexMin(matrix,n,m,i)];
    }
    /*
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    */

    /*for(int i=0;i<n;i++){
        cout<<"i: "<<i<<" "<<valCoins[i]<<endl;
    }
    */
    int sCoins = getMin(matrix,n,m,n-1);
    cout<<"soluzione: "<<sCoins<<endl;
    line = n-1;
    for(int i=0;i<sCoins;i++){
        //cout<<"line: "<<line<<" ";
        //cout<<"val: "<<valCoins[line]<<" ";
        cout<<"moneta: "<<i<<" = "<<valCoins[line]<<" ";
        line = line - valCoins[line];
    }
    cout<<endl;
    
    
}


int main(){
    in.open("input.txt");
    out.open("output.txt");
    for(int task=0;task<3;task++){
        int r;
        in>>r;
        int numCoins;
        in>>numCoins;
        int coins[numCoins];
        for(int i=0;i<numCoins;i++){
            int temp;
            in>>temp;
            coins[i] = temp;
        }
        change(r,coins,numCoins);
    }
}