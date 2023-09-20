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
        T* elements;
        int count;

        MaxHeap(int dim){
            maxSize = dim;
            currentSize = 0;
            elements = new T [dim];
            count=0;
        }        

        int getParent(int i){
            return (i-1)/2;
        }

        int getSx(int i){
            return i*2 +1;
        }

        int getDx(int i){
            return i*2 +2;
        }

        void insert(T val){
            if(currentSize < maxSize){
                elements[currentSize] = val;
                currentSize++;
            }    
        }

        void swap(int x, int y){
            T temp = elements[x];
            elements[x] = elements[y];
            elements[y] = temp;
        }

        void heapifyForBuild(int i){
            if(currentSize == 0){
                return;
            }

            int max = i;
            if(getSx(i) < currentSize && elements[getSx(i)] > elements[max]){
                max = getSx(i);
            }

            if(getDx(i) < currentSize && elements[getDx(i)] > elements[max]){
                max = getDx(i);
            }

            if(max != i){
                swap(i,max);
                heapifyForBuild(max);
            }
        }

        void heapify(int i){
            if(currentSize == 0){
                return;
            }

            count++;
            int max = i;
            if(getSx(i) < currentSize && elements[getSx(i)] > elements[max]){
                max = getSx(i);
            }

            if(getDx(i) < currentSize && elements[getDx(i)] > elements[max]){
                max = getDx(i);
            }

            if(max != i){
                swap(i,max);
                heapify(max);
            }
        }

        void buildMaxHeap(){
            for(int i=round(currentSize/2)-1;i>=0;i--){
                heapify(i);
            }
        }

        void extractMax(){
            if(currentSize>0){
                swap(0,currentSize-1);
                currentSize--;
                heapify(0);
            }
        }

        void heapSort(){
            //checkMaxHeap();
            buildMaxHeap();
            //checkMaxHeap();
            for(int i=0;i<maxSize;i++){
                extractMax();
                //checkMaxHeap();
            }
            printHeapSort();
        }

        void checkMaxHeap(){
            for(int i=0;i<maxSize;i++){
                cout<<elements[i]<<" ";
            }
            cout<<endl;
        }

        void printHeapSort(){
            out<<count<<" ";
            for(int i=0;i<maxSize;i++){
                out<<elements[i]<<" ";
            }
            out<<endl;
        }
};


int main(){
    in.open("input.txt");
    out.open("output.txt");

    for(int task=0;task<100;task++){
        string type;
        int dim;
        in>>type;
        in>>dim;

        if(type == "int"){
            MaxHeap <int> maxHeap(dim);
            for(int i=0;i<dim;i++){
                int val;
                in>>val;
                maxHeap.insert(val);
            }
            maxHeap.heapSort();
        }

        else if(type == "double"){
            MaxHeap <double> maxHeap(dim);
            for(int i=0;i<dim;i++){
                double val;
                in>>val;
                maxHeap.insert(val);
            }
            maxHeap.heapSort();
        }

        else if(type == "char"){
            MaxHeap <char> maxHeap(dim);
            for(int i=0;i<dim;i++){
                char val;
                in>>val;
                maxHeap.insert(val);
            }
            maxHeap.heapSort();
        }

        else if(type == "bool"){
            MaxHeap <bool> maxHeap(dim);
            for(int i=0;i<dim;i++){
                bool val;
                in>>val;
                maxHeap.insert(val);
            }
            maxHeap.heapSort();
        }
    }
}