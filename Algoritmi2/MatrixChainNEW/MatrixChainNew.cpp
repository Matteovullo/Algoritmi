#include <iostream>
#include <fstream>
#include <string>
using namespace std;
ifstream in;
ofstream out;


void MatrixChainOrder(int *P, int sizeP){
    int n = sizeP-1;
    int **matrix;
    matrix = new int *[n];
    for(int i=0;i<n;i++){
        matrix[i] = new int [n];
    }

    for(int i=0;i<n;i++){
        matrix[i][i] = 0;
    }
    
    for(int offset=1; offset < n;offset++){
        for(int i=0;i<n-offset;i++){
            int j=offset+i;
            matrix[i][j] = 100000;
            for(int k=i;k<j;k++){
                int min = matrix[i][k] + matrix[k+1][j] + (P[i] * P[k+1] * P[j+1]);
                if(min < matrix[i][j]){
                    matrix[i][j] = min;
                }
            }
        }
    }

    
    out<<matrix[0][n-1]<<endl;
}

int main(){
    in.open("input.txt");
    out.open("output.txt");
    for(int task=0;task<3;task++){
        int size;
        in>>size;
        size++;
        int *P;
        P = new int [size];
        string temp;
        for(int i=0;i<size-1;i++){
            in>>temp;
            int pos = temp.find('x');
            string f = temp.substr(1,pos-1);
            P[i] = atoi(f.c_str());
        }
        int pos = temp.find('x');
        string f = temp.substr(pos+1,temp.length()-pos-1);
        P[size-1] = atoi(f.c_str());
        for(int i=0;i<size;i++){
            cout<<P[i]<<" ";
        }   
        cout<<endl;
        MatrixChainOrder(P,size);
    }
}