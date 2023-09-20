#include <iostream>
#include <fstream>
#include <string>
using namespace std;
ifstream in;
ofstream out;


class Triple{
    public:
        double Vx;
        double Vy;
        double Vz;
        int x;
        int y;
        int z;
        Triple(){}

        void setValue(double val1,double val2,double val3){
            Vx = val1;
            Vy = val2;
            Vz = val3;
            double a = val1*10;
            x = int(a);
            double b = val2*10;
            y = int(b);
            double c = val3*10;
            z = int(c);

            //cout<<Vx<<" "<<x<<endl;
            //cout<<Vy<<" "<<y<<endl;
            //cout<<Vz<<" "<<z<<endl;
        }

};

int getMax(Triple **vett,int size){
    int max = 0;
    for(int i=0;i<size;i++){
        if(vett[i]->x > max){
            max = vett[i]->x;
        }
    }
    return max;
}

int getMin(Triple **vett,int size){
    int min = 1000000;
    for(int i=0;i<size;i++){
        if(vett[i]->x < min){
            min = vett[i]->x;
        }
    }
    return min;
}

void CountingSort(Triple **vett,int size){
    int max = getMax(vett,size);
    int min = getMin(vett,size);
    int n = (max-min)+1;
    //cout<<max<<" "<<min<<" "<<n<<endl;
    int C[n]={0};
    for(int i=0;i<size;i++){
        C[vett[i]->x-min] ++;
    }
    for(int i=1;i<n;i++){
        C[i] += C[i-1];
    }

    Triple **B;
    B = new Triple*[size];
    for(int i=0;i<size;i++){
        B[i] = new Triple ();
    }

    for(int i=size-1;i>=0;i--){
        B[C[vett[i]->x-min]-1] = vett[i];
        C[vett[i]->x-min]--;
    }
    //B[C[A[i]-min]-1];
    for(int i=0;i<n;i++){
        out<<C[i]<<" ";
    }

    for(int i=0;i<size;i++){
        out<<"("<<B[i]->Vx<<" "<<B[i]->Vy<<" "<<B[i]->Vz<<") ";
    }
    out<<endl;
}

int main(){
    in.open("input.txt");
    out.open("output.txt");
    
    for(int task=0;task<100;task++){
        int size;
        in>>size;
        Triple **vett;
        vett = new Triple * [size];
        for(int i=0;i<size;i++){
            vett[i] = new Triple ();
        }
        for(int i=0;i<size;i++){
            string num1;
            in>>num1;
            string n1= num1.substr(1,num1.length()-1);
            string num2;
            in>>num2;
            string n2= num2;
            string num3;
            in>>num3;
            string n3= num3.substr(0,num3.length()-1);
            vett[i]->setValue(atof(n1.c_str()),atof(n2.c_str()),atof(n3.c_str()));
        }
        CountingSort(vett,size);
    }
}