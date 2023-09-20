#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
using namespace std;
ifstream in;
ofstream out;

template <class T> class MinHeap{
    public:
        int maxSize;
        int currentSize;
        T* elements;
        int count;
        MinHeap(int size){
            maxSize=size;
            currentSize = 0;
            elements = new T [size];
            count = 0;
        }

        int getParent(int i){
            return (i-1)/2;
        }

        int getSx(int i){
            return (i*2)+1;
        }

        int getDx(int i){
            return (i*2)+2;
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

        void heapify(int i){
            if(currentSize == 0){
                return;
            }

            count++;
            int min = i;
            if(getSx(i) < currentSize && elements[getSx(i)] < elements[min]){
                min = getSx(i);
            }

            if(getDx(i) < currentSize && elements[getDx(i)] < elements[min]){
                min = getDx(i);
            }

            if(min != i){
                swap(i,min);
                heapify(min);
            }
        }

        void buildMinHeap(){
            for(int i=round(currentSize/2)-1;i>=0;i--){
                heapify(i);
            }
        }

        void extractMin(){
            if(currentSize>0){
                swap(0,currentSize-1);
                currentSize--;
                heapify(0);
            }
        }

        void heapSort(){
            buildMinHeap();
            for(int i=0;i<maxSize;i++){
                extractMin();
            }
            printMinHeap();
        }

        void printMinHeap(){
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

    for(int task = 0;task<100;task++){
        string type;
        int dim;
        in>>type;
        in>>dim;

        if(type =="int"){
            MinHeap <int> minHeap(dim);
            for(int i=0;i<dim;i++){
                int val;
                in>>val;
                minHeap.insert(val);
            }
            minHeap.heapSort();
        }

        else if(type =="double"){
            MinHeap <double> minHeap(dim);
            for(int i=0;i<dim;i++){
                double val;
                in>>val;
                minHeap.insert(val);
            }
            minHeap.heapSort();
        }

        if(type =="char"){
            MinHeap <char> minHeap(dim);
            for(int i=0;i<dim;i++){
                char val;
                in>>val;
                minHeap.insert(val);
            }
            minHeap.heapSort();
        }

        if(type =="bool"){
            MinHeap <bool> minHeap(dim);
            for(int i=0;i<dim;i++){
                bool val;
                in>>val;
                minHeap.insert(val);
            }
            minHeap.heapSort();
        }
    }


}