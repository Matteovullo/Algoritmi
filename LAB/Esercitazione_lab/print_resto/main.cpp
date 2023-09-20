#include<iostream>
#include<fstream>
//#include<climits>
#include<algorithm>
#include<sstream>

using namespace std;

int** create_matrix(int n, int m){
    int** v=new int*[n];
    for(int i=0; i<n; i++) v[i]=new int[m]{INT_MAX};
    return v;
}

void min_coins(int* v, int n, int r, ofstream &out){
    sort(v, v+n);

    int** table=create_matrix(n+1, r+1);
    for(int i=0; i<n; i++){
        int index=i+1;

        for(int j=1; j<r+1; j++){
            table[index][j]=table[index-1][j];

            if(j<=v[i]){
                int sub=table[index][j-v[i]];

                if(sub!=INT_MAX)
                    table[index][j]=min(sub+1, table[index][j]);
            }
        }
    }
    out << table[n][r] << " ";

    string print;
    int i=n;
    int j=r;

    while(i>0 && j>0){
        int sub=j-v[i-1];

        if(table[i][j] == table[i][sub]+1 
        && sub>=0){
            j=sub;
            stringstream ss;
            ss<<v[i-1];
            string s=ss.str();
            print=s+" "+print;
        }else{
            i--;
        }
    }
    out << print << endl;
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    for(int i=0; i<100; i++){
        int n, r;
        in>>n>>r;

        int* v=new int[n];

        for(int j=0; j<n; j++){
            in>>v[j];
        }
        min_coins(v, n, r, out);
    }
}