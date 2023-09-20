#include <iostream>
#include <fstream>
#include <string>
using namespace std;
ifstream in;
ofstream out;

/*
template <class T> T maxElement(T *vett,int size){
    T max = vett[0];
    for(int i=1;i<size;i++){
        if(vett[i] > max){
            max = vett[i];
        }
    }
    return max;
}

template <class T> T minElement(T *vett,int size){
    T min = vett[0];
    for(int i=1;i<size;i++){
        if(vett[i] < min){
            min = vett[i];
        }
    }
    return min;
}



template <class T> void countingSort(T * vett, int size,string type){
    T max = maxElement(vett,size);
    T min = minElement(vett,size);
    

    
    int C[n] = {0};
    for(int i=0;i<size;i++){
        C[int(vett[i]) - int(min)]++;
    
    
    
    for(int i=1;i<n;i++){
        C[i] += C[i-1];
    }
    
    T B[size];

    for(int i=size-1;i>=0;i--){
        B[C[int(vett[i])-int(min)]-1] = vett[i];
        C[int(vett[i])-int(min)]--;
    }

    for(int i=0;i<n;i++){
        out<<C[i]<<" ";
    }

    for(int i=0;i<size;i++){
        out<<B[i]<<" ";
    }
    
    out<<endl;
    }
}
/*
template <class T> void countingSortDouble(double * vett, int size){
    double max = maxElement(vett,size);
    double min = minElement(vett,size);
    double n = (max - min)+1;
    n = n *10;
    int C[int(n)] = {0};
    for(int i=0;i<size;i++){
        C[int(vett[i]*10 - min*10)]++;
    }
    
    
    for(int i=1;i<n;i++){
        C[i] += C[i-1];
    }
    
    T B[size];

    for(int i=size-1;i>=0;i--){
        B[C[int(vett[i]*10-min*10)]-1] = vett[i];
        C[int (vett[i]*10-min*10)]--;
    }

    for(int i=0;i<n;i++){
        out<<C[i]<<" ";
    }

    for(int i=0;i<size;i++){
        out<<B[i]<<" ";
    }
    
    out<<endl;
}
*/

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

int* countingSort(int *vett, int n){
    int max =getMax(vett,n);
    int min =getMin(vett,n);
    int C[(max-min)+1] = {0};

    for(int i=0;i<n;i++){
        C[vett[i]-min]++;
    }


    for(int i=1;i<(max-min)+1;i++){
        C[i] += C[i-1];
    }
    
    
    int *B;
    B = new int [n];

    for(int i=n-1;i>=0;i--){
        B[C[vett[i]-min]-1] = vett[i];
        C[vett[i]-min]--;
    }

    for(int i=0;i<n;i++){
        vett[i] = B[i];
    }

    
    printVector(C,(max-min)+1);
    return B;
}
int main(){
    in.open("input.txt");
    out.open("output.txt");

    for(int task=0;task<100;task++){
        string type;
        in>>type;
        int size;
        in>>size;
        int elements[size];
        if(type == "int"){
            for(int i=0;i<size;i++){
                int temp;
                in>>temp;
                elements[i] = temp;
            }
            int *B = countingSort (elements,size);
            for(int i=0;i<size;i++){
                out<<B[i]<<" ";
            }
            out<<endl;
        }

        else if(type == "double"){
           
            for(int i=0;i<size;i++){
                double temp;
                in>>temp;
                temp = temp*10;
                elements[i] = int(temp);
            }
            for(int i=0;i<size;i++){
                cout<<elements[i]<<" ";
            }
            
            int *B =countingSort (elements,size);
            for(int i=0;i<size;i++){
                out<<double(B[i]) /10<<" ";
            }
            out<<endl;
        }

        else if(type == "bool"){
            
            for(int i=0;i<size;i++){
                int temp;
                in>>temp;
                elements[i] = temp;
            }
            int *B = countingSort (elements,size);
            for(int i=0;i<size;i++){
                out<<B[i]<<" ";
            }
            out<<endl;
        }

        else if(type == "char"){
          
            for(int i=0;i<size;i++){
                char temp;
                in>>temp;
                int cv = int(temp);
                elements[i] = cv;
            }
            int *B= countingSort(elements,size);
            for(int i=0;i<size;i++){
                out<<char(B[i])<<" ";
            }
            out<<endl;
        }
    }    
}