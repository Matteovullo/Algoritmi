#include <iostream>
#include <fstream>
#include <string>
using namespace std;
ifstream in;
ofstream out;
template <class T> class Heap{
    public:
        T *elements;
        int size;
        int currentSize;
        int count;
        Heap(int size){
            this->size = size;
            currentSize = 0;
            count = 0;
            elements = new T [size];
        }

        int getP(int i){
            return (i-1)/2;
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
        void insert(T val){
            if(currentSize<size){
                elements[currentSize] = val;
                currentSize++;
                int i = currentSize-1;
                while(i > 0 && elements[getP(i)] > elements[i]){
                    swap(getP(i),i);
                    i = getP(i);
                }
            }
        }

        void heapify(int i){
            if(currentSize==0){
                return;
            }
            count++;
            int max = i;
            if(getSx(i) < currentSize && elements[getSx(i)] < elements[max]){
                max = getSx(i);
            }

            if(getDx(i) < currentSize && elements[getDx(i)] < elements[max]){
                max = getDx(i);
            }

            if(max!=i){
                swap(i,max);
                heapify(max);
            }
        }

        void extract(){
            if(currentSize > 0){
                swap(0,currentSize-1);
                currentSize--;
                heapify(0);
            }
        }

        void printHeap(){
            out<<count<<" ";
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
       in>>type;
       int size;
       in>>size;
       if(type == "int"){
           Heap <int> heap(size);
           for(int i=0;i<size;i++){
               string s;
               in>>s;
               if(s[1] == ':'){
                   string val = s.substr(2,s.length()-2);
                   heap.insert(atoi(val.c_str())); 
               }
               else{
                   heap.extract();
               }
           }
           heap.printHeap();
       }

       else if(type == "double"){
           Heap <double> heap(size);
           for(int i=0;i<size;i++){
               string s;
               in>>s;
               if(s[1] == ':'){
                   string val = s.substr(2,s.length()-2);
                   heap.insert(atof(val.c_str())); 
               }
               else{
                   heap.extract();
               }
           }
           heap.printHeap();
       }

       if(type == "bool"){
           Heap <int> heap(size);
           for(int i=0;i<size;i++){
               string s;
               in>>s;
               if(s[1] == ':'){
                   string val = s.substr(2,s.length()-2);
                   heap.insert(atoi(val.c_str())); 
               }
               else{
                   heap.extract();
               }
           }
           heap.printHeap();
       }

       if(type == "char"){
           Heap <char> heap(size);
           for(int i=0;i<size;i++){
               string s;
               in>>s;
               if(s[1] == ':'){
                   string val = s.substr(2,s.length()-2);
                   heap.insert(val[0]); 
               }
               else{
                   heap.extract();
               }
           }
           heap.printHeap();
       }
   }
}