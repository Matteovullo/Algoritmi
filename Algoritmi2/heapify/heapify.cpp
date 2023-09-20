#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;
ifstream in;
ofstream out;

template <class T> class MaxHeap{
    public:
        int maxSize;
        int currentSize;
        T *elements;
        int count;
        MaxHeap(int dim){
            maxSize = dim;
            currentSize = 0;
            elements = new T [dim];
            count = 0;
        }

        int getParent(int i){
            return ((i-1)/2);
        }

        int getSx(int i){
            return (i*2) +1;
        }

        int getDx(int i){
            return (i*2) +2;
        }

        void swap(int x,int y){
            T temp = elements[x];
            elements[x] = elements[y];
            elements[y] = temp;
        }

        void heapify(int i){
            
            if(currentSize == 0){
                return;
            }
            
            count++;
            int max = i;
            if(getSx(i) < currentSize && elements[getSx(i)]>elements[max]){
                max = getSx(i);
            }
            if(getDx(i) < currentSize && elements[getDx(i)]>elements[max]){
                max = getDx(i);
            }

            if(max!=i){
                swap(max,i);
                heapify(max);
            }
        }

        void insert(T val){
            if(currentSize<maxSize){
                elements[currentSize] = val;
                currentSize++;
            }    
        }

        void buildMaxHeap(){
            for(int i=round(currentSize/2)-1;i>=0;i--){
                heapify(i);
            }
        }

        void extractMax(){
            swap(0,currentSize-1);
            currentSize--;
            heapify(0);
        }

        void printCountMaxHeap(){
            out<<count<<endl;
        }

};


int main(){
    in.open("input.txt");
    out.open("output.txt");

    for(int task=0;task<100;task++){
        string type;
        int n;
        in>>type;
        in>>n;
        
        if(type == "int"){
            MaxHeap<int> maxHeap(n);
            for(int i=0;i<n;i++){
                int val;
                in>>val;
                maxHeap.insert(val);
                
            }
            maxHeap.buildMaxHeap();

            for(int i=0;i<n;i++){
                maxHeap.extractMax();
            }
            
            maxHeap.printCountMaxHeap();
            
        }

        else if(type == "double"){
            MaxHeap<double> maxHeap(n);
            for(int i=0;i<n;i++){
                double val;
                in>>val;
                maxHeap.insert(val);
            }
            maxHeap.buildMaxHeap();

            for(int i=0;i<n;i++){
                maxHeap.extractMax();
            }
            maxHeap.printCountMaxHeap();
        }

        else if(type == "bool"){
            MaxHeap<bool> maxHeap(n);
            for(int i=0;i<n;i++){
                bool val;
                in>>val;
                maxHeap.insert(val);
            }
            maxHeap.buildMaxHeap();
            for(int i=0;i<n;i++){
                maxHeap.extractMax();
            }
            maxHeap.printCountMaxHeap();
        }

        else if(type == "char"){
            MaxHeap<char> maxHeap(n);
            for(int i=0;i<n;i++){
                char val;
                in>>val;
                maxHeap.insert(val);
            }
            maxHeap.buildMaxHeap();
            for(int i=0;i<n;i++){
                maxHeap.extractMax();
            }
            maxHeap.printCountMaxHeap();
        }
    }
}