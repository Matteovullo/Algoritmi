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
        MaxHeap(int maxSize){
            this->maxSize = maxSize;
            currentSize = 0;
            elements = new T [maxSize];
            count=0;
        }
        int getParent(int i){
            return floor((i-1)/2);
        }
        int getSx(int i){
            return (i*2)+1;
        }
        int getDx(int i){
            return (i*2)+2;
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
                if(getSx(i) < currentSize && elements[getSx(i)] > elements[max]){
                    max = getSx(i);
                }
                if(getDx(i) < currentSize && elements[getDx(i)] > elements[max]){
                    max = getDx(i);
                }
                if(max != i){
                    swap(max,i);
                    heapify(max);
                }
        
        }

        void buildMaxHeap(){
            for(int i=round(currentSize/2)-1;i>=0;i--){
                heapify(i);
            }
        }

        void insert(T element){
            if(currentSize < maxSize){
                elements[currentSize] = element;
                currentSize++;

                int i=currentSize-1;
                while(i>0 && elements[getParent(i)] < elements[i]){
                    swap(i,getParent(i));
                    i = getParent(i);
                }
            }
        }

        void printMaxHeap(){
            out<<count<<" ";
            for(int i=0;i<currentSize;i++){
                out<<elements[i]<<" ";
            }
            out<<endl;
        }

        void extract(){
            if(currentSize > 0){
            swap(0,currentSize-1);
            currentSize--;
            heapify(0);
            }
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
        //cout<<size<<endl;
        //cout<<type<<endl;
        
        if(type=="int"){
            MaxHeap <int> heap(size);
            for(int i=0;i<size;i++){
                string s;
                in>>s;
                if(s[1]==':'){
                    string val = s.substr(2,s.length()-2);
                    heap.insert(atoi(val.c_str()));
                }

                else{
                    heap.extract();
                }
            }
            heap.printMaxHeap();
        }

        else if(type=="bool"){
            MaxHeap <bool> heap(size);
            for(int i=0;i<size;i++){
                string s;
                in>>s;
                if(s[1]==':'){
                    string val = s.substr(2,s.length()-2);
                    heap.insert(atoi(val.c_str()));
                }

                else{
                    heap.extract();
                }
            }
            heap.printMaxHeap();
        }

        else if(type=="double"){
            MaxHeap <double> heap(size);
            for(int i=0;i<size;i++){
                string s;
                in>>s;
                if(s[1]==':'){
                    string val = s.substr(2,s.length()-2);
                    heap.insert(atof(val.c_str()));
                }

                else{
                    heap.extract();
                }
            }
            heap.printMaxHeap();
        }

        else if(type=="char"){
            MaxHeap <char> heap(size);
            for(int i=0;i<size;i++){
                string s;
                in>>s;
                if(s[1]==':'){
                    string val = s.substr(2,s.length()-2);
                    heap.insert(val[0]);
                }

                else{
                    heap.extract();
                }
            }
            heap.printMaxHeap();
        }

        
       
    }
}