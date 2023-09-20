#include<iostream>
#include<fstream>

using namespace std;

int* create_matrix(int n){
    int* array=new int[n];
    for(int i=0; i<n; i++){ array[i]=0;}
    return array;
}

void countingsort(ofstream &out, int* v, int n){
    int min=v[0];
    int max=v[0];

    for(int i=0; i<n; i++){
        if(v[i] > max) max=v[i];
        if(v[i] < min) min=v[i];
    }

    int range=(max-min)+1;
    int* c=create_matrix(range);

    for(int i=0; i<n; i++){
        c[v[i]-min]++;
    }

    for(int i=1; i<range; i++){
        c[i]=c[i-1]+c[i];
    }

    int *s=create_matrix(n);

    for(int i=0; i<n; i++){
        s[--c[v[i]-min]]=v[i];
    }

    for(int i=0; i<range; i++) out << c[i] << " ";
    for(int i=0; i<n; i++) out << s[i] << " ";

    out << endl;
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    for(int i=0; i<100; i++){
        int n;
        in>>n;
        int* array=new int[n];

    for(int i=0; i<n; i++){
        in>>array[i];
    }
        countingsort(out, array, n);
    }


}