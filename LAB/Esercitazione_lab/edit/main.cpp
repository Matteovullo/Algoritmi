#include<iostream>
#include<fstream>

using namespace std;

int** create_matrix(int n, int m){
    int** array=new int*[n];
    for(int i=0; i<n; i++){
        array[i]=new int[m] {0};
    }
    return array;
}

int edit(string x, int n, string y, int m){
    int** v=create_matrix(n+1, m+1);

    for(int i=0; i<n+1; i++){
        v[i][0]=i;
    }

    for(int j=0; j<m+1; j++){
        v[0][j]=j;
    }

    for(int i=1; i<n+1; i++){
        for(int j=1; j<m+1; j++){
            x[i-1]==y[j-1] ? v[i][j]=v[i-1][j-1] :
            v[i][j]=min(min(v[i-1][j], v[i][j-1]), v[i-1][j-1]) +1;
        }
    }
    return v[n][m];
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    for(int i=0; i<100; i++){
        string x, y;
        int n,m;
        in >> n >> m >> x >> y;
        out << edit(x, n, y, m);
        out << endl;
    }
}