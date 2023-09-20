#include <iostream>
#include <fstream>
#include <string>
using namespace std;
ifstream in;
ofstream out;

int maxElement(int a,int b){
    if(a>= b) return a;
    else return b;
}


void printLCS(int **matrix,int n,int m, int s,string a,string b){
  
    char vett[s];
    int i=n-1;
    int j=m-1;
    int counter=s-1;
    while(i!=0 && j!=0){
        //cout<<a[i-1]<<" "<<b[j-1]<<" "<<endl;
        if(a[i-1] != b[j-1]){
            if(matrix[i][j-1] >= matrix[i-1][j]){
                j--;
            }
            else{
                i--;
            }
        }

        else{
            vett[counter] = a[i-1];
            counter--;
            i--;
            j--;
        }
    }

    for(int i=0;i<s;i++){
        out<<vett[i];
    }
    out<<endl;
}

void LCS(string a,int sizeA,string b,int sizeB){
    int n=sizeA+1;
    int m=sizeB+1;
    int **matrix;
    matrix = new int*[n];
    for(int i=0;i<n;i++){
        matrix[i] = new int [m];
    }

    for(int i=0;i<n;i++){
        matrix[i][0] = 0;
    }
    for(int i=0;i<m;i++){
        matrix[0][i] = 0;
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(a[i-1] == b[j-1]){
                matrix[i][j] = matrix[i-1][j-1]+1;
            }

            else{
                matrix[i][j]=maxElement(matrix[i-1][j],matrix[i][j-1]);
            }
        }
    }
    int s = matrix[n-1][m-1];

    //cout<<"soluzione: "<<s<<endl;
    printLCS(matrix,n,m,s,a,b);
}

int main(){
    in.open("input.txt");
    out.open("output.txt");
    for(int task=0;task<100;task++){
        int size1;
        int size2;
        in>>size1;
        in>>size2;
        string a;
        string b;
        in>>a;
        in>>b;
        LCS(a,size1,b,size2);
    }

}