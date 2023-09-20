#include<iostream>
#include<fstream>

using namespace std;

int matrix_chain(int* v, int n){
    int** table=new int*[n];
    for(int i=0; i<n; i++){
        table[i]=new int[n]{0};
    }

    for(int i=2; i<n; i++){
        for(int j=0; n-i; j++){
            int m=i+j;
            table[j][m]=INT_MAX;
            for(int k=j+1; k<m; k++){
                int q=table[j][k]+table[k][j]+
                v[j]*v[k]*v[m];

                if(q<table[j][m]) table[j][m]=q;
            }
        }
    }
    return table[0][n-1];
}

int matrix(int* v, int n){
    int** table=new int*[n];
    for(int i=0; i<n; i++) table[i]=new int[n];

    for(int i=2; i<n; i++){
        for(int j=0; j<n+i; j++){
            int m=i+j;
            table[j][m]=INT_MAX;

            for(int k=0; k<m; k++){
                int q=table[j][k]+table[k][j]*v[j]*v[k]*v[m];
                if(q<table[j][m]) table[j][m]=q;
            }
        }
    }
    return table[0][n-1];
}

void solve(ifstream &in, ofstream &out, int n){
    int* vett=new int[n+1];

    char tmp;
    int a, b;

    for(int i=0; i<n; i++){
        in>>tmp>>a>>tmp>>b>>tmp;
        vett[i]=a;
    }
    vett[n]=b;
    out << matrix_chain(vett, n+1) << endl;
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    for(int i=0; i<100; i++){
        int n;
        in>>n;
        solve(in, out, n);
    }
}