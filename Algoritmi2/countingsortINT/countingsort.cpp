#include <iostream>
#include <fstream>
#include <string>
using namespace std;
ifstream in;
ofstream out;

int getMax(int* a, int n){
    int max = a[0];
    for(int i=1;i<n;i++){
        if (max < a[i]){
            max = a[i];
        }
    }
    return max;
}

int getMin(int* a, int n){
    int min = a[0];
    for(int i=1;i<n;i++){
        if (min > a[i]){
            min = a[i];
        }
    }
    return min;
}

void printVector(int*a, int n){
    for(int i=0;i<n;i++){
        out<<a[i]<<" ";
    }
}

void countingSort(int *vett, int n){
    int max =getMax(vett,n);
    int min =getMin(vett,n);
    int C[(max-min)+1] = {0};

    for(int i=0;i<n;i++){
        C[vett[i]-min]++;
    }


    for(int i=1;i<(max-min)+1;i++){
        C[i] += C[i-1];
    }

    int B[n];

    for(int i=n-1;i>=0;i--){
        B[C[vett[i]-min]-1] = vett[i];
        C[vett[i]-min]--;
    }

    for(int i=0;i<n;i++){
        vett[i] = B[i];
    }

    printVector(C,(max-min)+1);
    printVector(vett,n);
}



int main(){
    in.open("input.txt");
    out.open("output.txt");

    for(int task=0;task<100;task++){
        int n;
        in>>n;
        int vett [n];
        for(int i=0;i<n;i++){
            int val;
            in>>val;
            vett[i] = val;
        }
        countingSort(vett,n);
        out<<endl;
    }

}