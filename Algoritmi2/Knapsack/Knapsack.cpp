#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
ifstream in;
ofstream out;
void swap (int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}

void sort(int* vett, int dim){
    for(int i=0;i<dim;i++){
        int max = i;
        for(int j=i;j<dim;j++){
            if(vett[i]<vett[j]){
                swap(vett[i],vett[j]);
            }
        }
    }
}

int greedyPack(int *vett,int size){
    int sum =0;
    for(int i=0;i<size;i++){
        sum += vett[i];
    }
    return sum;
}

int main(){
    in.open("input.txt");
    out.open("output.txt");
    for(int task=0;task<100;task++){
        int dim;
        int size;
        in>>dim;
        in>>size;
        int vett[dim];
        for(int i=0;i<dim;i++){
            int val;
            in>>val;
            vett[i] = val;
        }
        sort(vett,dim);
        out<<greedyPack(vett,size)<<endl;
    }    
}