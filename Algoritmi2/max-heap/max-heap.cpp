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
        T * elements;
        int count;


        MaxHeap(int n){
            maxSize = n;
            currentSize = 0;
            elements = new T [n];
            count = 0;
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
            T val = elements[x];
            elements[x] = elements[y];
            elements[y] = val;
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

                if(max!=i){
                    swap(max,i);
                    heapify(max);
                }
            
        }

        void insert(T val){
            elements[currentSize] = val;
            int p = currentSize;
            currentSize++;
            while(p>0 && elements[p] > elements[getParent(p)]){
                swap(p,getParent(p));
                p=getParent(p);
            }
        }

        void extract_max(){
            if(currentSize>0){
            swap(0,currentSize-1);
            currentSize--;
            heapify(0);
            }
        }

        void printMaxHeap(){
            out<<count<<" ";
            for(int i=0;i<currentSize;i++){
                out<<elements[i]<<" ";
            }
            out<<endl;
        }

        void testprint(){
            for(int i=0;i<currentSize;i++){
                cout<<elements[i]<<" ";
            }
            cout<<endl;
        }
};

int main(){
    in.open("input.txt");
    out.open("output.txt");
    for(int task = 0;task<3;task++){
        string type;
        int numOp;
        in>>type;
        in>>numOp;
        
        if(type=="int"){
            MaxHeap<int> maxHeap(numOp);
            for(int i=0;i<numOp;i++){
                string operation;
                in>>operation;
                
                if(operation.substr(0,2) == "e:"){
                    operation = operation.substr(2,operation.length()-2);
                    int val = atoi(operation.c_str());
                    maxHeap.insert(val);
                    maxHeap.testprint();
                }

                else if(operation.substr(0,2) == "ex"){
                    maxHeap.extract_max();
                    maxHeap.testprint();
                }
            }
            maxHeap.printMaxHeap();
        }

        else if(type=="double"){
            MaxHeap<double> maxHeap(numOp);
            for(int i=0;i<numOp;i++){
                string operation;
                in>>operation;
                
                if(operation.substr(0,2) == "e:"){
                    operation = operation.substr(2,operation.length()-2);
                    double val = atof(operation.c_str());
                    maxHeap.insert(val);
                }

                else if(operation.substr(0,2) == "ex"){
                    maxHeap.extract_max();
                }
            }
            maxHeap.printMaxHeap();
        }

        else if(type=="bool"){
            MaxHeap<int> maxHeap(numOp);
            for(int i=0;i<numOp;i++){
                string operation;
                in>>operation;
                
                if(operation.substr(0,2) == "e:"){
                    operation = operation.substr(2,operation.length()-2);
                    int val = atoi(operation.c_str());
                    maxHeap.insert(val);
                }

                else if(operation.substr(0,2) == "ex"){
                    maxHeap.extract_max();
                }
            }
            maxHeap.printMaxHeap();
        }

        else if(type=="char"){
            MaxHeap<char> maxHeap(numOp);
            for(int i=0;i<numOp;i++){
                string operation;
                in>>operation;
                
                if(operation.substr(0,2) == "e:"){
                    char val = operation[2];
                    maxHeap.insert(val);
                }

                else if(operation.substr(0,2) == "ex"){
                    maxHeap.extract_max();
                }
            }
            maxHeap.printMaxHeap();
        }
    }
}

