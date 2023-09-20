#include <iostream>
#include <fstream>
#include <string>
using namespace std;
ifstream in;
ofstream out;
class couples{
    public:
        int intX;
        int intY;
        double x;
        double y;
        couples(){
        }
};

int maxElement(couples *vett,int size){
    int max = vett[0].intX;
    for(int i=1;i<size;i++){
        if(vett[i].intX > max){
            max = vett[i].intX;
        }
    }
    return max;
}

int minElement(couples *vett,int size){
    int min = vett[0].intX;
    for(int i=1;i<size;i++){
        if(vett[i].intX < min){
            min = vett[i].intX;
        }
    }
    return min;
}

void printVector(couples *vett, int size){
    for(int i=0;i<size;i++){
        out<<"("<<vett[i].x<<" "<<vett[i].y<<") ";
    }
}

void CountingSort(couples *vett,int size){
    int max = maxElement(vett,size);
    int min = minElement(vett,size);
    cout<<max<<" "<<min<<endl;
    int n = (max-min)+1;
    int C[n] = {0};

    for(int i=0;i<size;i++){
        C[vett[i].intX-min]++;
    }

    for(int i=1;i<n;i++){
        C[i] += C[i-1];
    }

    couples B[size];
    for(int i=size-1;i>=0;i--){
        B[C[vett[i].intX-min]-1].x = vett[i].x;
        B[C[vett[i].intX-min]-1].y = vett[i].y;
        C[vett[i].intX-min]--;
    }

    for(int i=0;i<n;i++){
        out<<C[i]<<" ";
    }

    printVector(B,size);

    out<<endl;
}


int main(){
    in.open("input.txt");
    out.open("output.txt");

    for(int task=0;task<100;task++){
        int size;
        in>>size;
        couples vett[size];
        for(int i=0;i<size;i++){
            string val1;
            in>>val1;
            string val2;
            in>>val2;
            string xS = val1.substr(1,val1.length()-1);
            string yS = val2.substr(0,val2.length()-1);
            double x = atof(xS.c_str());
            double y = atof(yS.c_str());
            double f = x*10;
            vett[i].x = x;
            vett[i].y = y;
            vett[i].intX = int(f);
            cout<<vett[i].x<<endl;
            cout<<vett[i].intX<<endl;
            vett[i].intY = y*10;
           }

        CountingSort(vett,size);
    }
}