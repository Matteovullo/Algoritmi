#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ifstream in;
ofstream out;

int max(int x, int y){
    if(x>=y) return x;
    else return y;
}
/*
int LCS(string a, int x, string b, int y){
    int n = x+1;
    int m = y+1;
    int matrix[n][m];
    for(int i=0;i<n;i++) matrix[i][0] = 0;
    for(int i=0;i<m;i++) matrix[0][i] = 0;

    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(a[i-1] == b[j-1]){
                matrix[i][j] = matrix[i-1][j-1]+1;
            }
            else{
                matrix[i][j] = max(matrix[i-1][j],matrix[i][j-1]);
            }
        }
    }

    return matrix[n-1][m-1];
}   
*/
int lcs(string s1, string s2, int n, int m ){
    int n1 = n+1;
    int m1 = m+1;
    int **C;
    C = new int *[n1];
    for(int i=0;i<n1;i++){
        
        C[i] = new int [m1];
    }
    for(int i = 0; i<n1; i++) C[i][0] = 0;
    for(int i = 0; i< m1; i++) C[0][i] = 0;
    for(int i = 1;i<n1;i++){
        for(int j = 1;j<m1;j++){
            if(s1[i-1] == s2[j-1]) C[i][j] = C[i-1][j-1]+1;
            else C[i][j] = max(C[i-1][j],C[i][j-1]);
        }
    }
    return C[n][m];
}



int main(){
    in.open("input.txt");
    out.open("output.txt");

    for(int task =0; task<100;task++){
        int x;
        int y;
        string a;
        string b;
        in>>x;
        in>>y;
        in>>a;
        in>>b;
        //out<<LCS(a,x,b,y)<<endl;
        out<<lcs(a,b,x,y)<<endl;
    }
}