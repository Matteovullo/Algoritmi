#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
ifstream in;
ofstream out;

template <class T> class MinHeap{
    private:
        int maxSize;
        int currentSize;
        T* elements;
    public:
        MinHeap(int x){
            maxSize=x;
            currentSize=0;
            elements = new T [x];
        }

        int getParent(int i){
            return floor((i-1)/2);
        }
        int getSx(int i){
            return floor((i*2)+1);
        }
        int getDx(int i){
            return floor((i*2)+2);
        }

        void swap(int x, int y){
            T val = elements[x];
            elements[x] = elements[y];
            elements[y] = val;
        }

        void insert(T val){
            elements[currentSize] = val;
            int i=currentSize;
            currentSize++;

            while(i>0 && val < elements[getParent(i)]){
                swap(i,getParent(i));
                i = getParent(i);
            }
        }

        void printMinHeap(){
            for(int i=0;i<currentSize;i++){
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
        int size;
        in>>type;
        in>>size;

        if(type=="int"){
            MinHeap<int> minHeap(size);
            for(int i=0;i<size;i++){
                int val;
                in>>val;
                minHeap.insert(val);
            }
            minHeap.printMinHeap();
        }

        else if(type=="bool"){
            MinHeap<bool> minHeap(size);
            for(int i=0;i<size;i++){
                bool val;
                in>>val;
                minHeap.insert(val);
            }
            minHeap.printMinHeap();
        }

        else if(type=="double"){
            MinHeap<double> minHeap(size);
            for(int i=0;i<size;i++){
                double val;
                in>>val;
                minHeap.insert(val);
            }
            minHeap.printMinHeap();
        }

        if(type=="char"){
            MinHeap<char> minHeap(size);
            for(int i=0;i<size;i++){
                char val;
                in>>val;
                minHeap.insert(val);
            }
            minHeap.printMinHeap();
        }


    }

}