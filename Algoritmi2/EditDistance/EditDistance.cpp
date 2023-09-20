#include <iostream>
#include <fstream>
#include <string>
using namespace std;
ifstream in;
ofstream out;

int min(int a, int b, int c){
    int min = a;
    if(b < min){
        min = b;
    }

    if(c < min){
        min = c;
    }

    return min;
}


int editDistance(string A,int dimA, string B, int dimB){
    int n = dimA+1;
    int m = dimB+1;
    int **matrix;
    matrix = new int* [n];
    for(int i=0;i<n;i++){
        matrix[i] = new int [m];
    }

    for(int i=0;i<n;i++){matrix[i][0] = i;}
    for(int i=0;i<m;i++){matrix[0][i] = i;}

    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(A[i-1] == B[j-1]){
                matrix[i][j] = matrix[i-1][j-1];
            }
            else{
                matrix[i][j] = min(matrix[i-1][j],matrix[i][j-1],matrix[i-1][j-1])+1;
            }
        }
    }

    return matrix[n-1][m-1];
}

int main(){
    in.open("input.txt");
    out.open("output.txt");

    for(int task=0;task<100;task++){
        int dimA;
        int dimB;
        string A;
        string B;
        in>>dimA;
        in>>dimB;
        in>>A;
        in>>B;
        out<<editDistance(A,dimA,B,dimB)<<endl;
    }
    
}