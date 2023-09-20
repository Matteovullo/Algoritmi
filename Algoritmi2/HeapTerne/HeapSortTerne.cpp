#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;
ifstream in;
ofstream out;

template <class T> class Triple{
    public:
        T x;
        T y;
        T z;
        Triple(){}
};

template <class T> class Heap{
    public:
        Triple  <T> **elements;
        int size;
        int currentSize;
        int count;

        Heap(int size){
            this->size = size;
            currentSize = 0;
            elements = new Triple <T> *[size];
            for(int i=0;i<size;i++){
                elements[i] = new Triple <T> ();
            }
            count =0;
        }

        int getP(int i){
            return (i-1)/2;
        }

        int getSx(int i){
            return i*2 +1;
        }

        int getDx(int i){
            return i*2 +2;
        }

        void insert (T x, T y, T z){
            Triple <T> *a = new Triple <T> ();
            a->x = x;
            a->y = y;
            a->z =z;
            elements[currentSize] = a;
            currentSize++;
        }

        void printHeap(){
            out<<count<<" ";
            for(int i=0;i<size;i++){
                out<<"("<<elements[i]->x<<" "<<elements[i]->y<<" "<<elements[i]->z<<") ";
            }
            out<<endl;
        }

        bool compare(Triple <T> *a, Triple<T> *b){
            if(a->x > b->x){
                return true;
            }
            if(a->x == b->x && a->y > b->y){
                return true;
            }
            if(a->x == b->x && a->y == b->y && a->z > b->z){
                return true;
            }

            return false;
        }

        void swap(Triple <T> *x, Triple<T>* y){
            Triple <T> * temp = new Triple <T>();
            temp->x = x->x;
            temp->y = x->y;
            temp->z = x->z;
            x->x = y->x;
            x->y = y->y;
            x->z = y->z;
            y->x = temp->x;
            y->y = temp->y;
            y->z = temp->z;

        }
        void heapify(int i){
            if(currentSize == 0){
                return;
            }
            count++;
            int max = i;
            /*

            cout<<"x: "<<elements[max]->x<<" ";
            cout<<"y: "<<elements[max]->y<<" ";
            cout<<"z: "<<elements[max]->z<<" ";
            cout<<endl;
            if(getSx(i) < currentSize){
            cout<<"x: "<<elements[getSx(i)]->x<<" ";
            cout<<"y: "<<elements[getSx(i)]->y<<" ";
            cout<<"z: "<<elements[getSx(i)]->z<<" ";
            cout<<endl;
            }
            if(getDx(i) < currentSize){
            cout<<"x: "<<elements[getDx(i)]->x<<" ";
            cout<<"y: "<<elements[getDx(i)]->y<<" ";
            cout<<"z: "<<elements[getDx(i)]->z<<" ";
            cout<<endl;
                }
            */
            
            if(getSx(i) < currentSize && compare(elements[getSx(i)],elements[max])){
                max = getSx(i);
                //cout<<"swappato SX"<<endl;
            }

            if(getDx(i) < currentSize && compare(elements[getDx(i)],elements[max])){
                max = getDx(i);
                //cout<<"swappato DX"<<endl;
            }
            //cout<<endl;
            if(max!=i){
                swap(elements[i],elements[max]);
                heapify(max);
            }
        }

        void buildHeap(){
            for(int i=round(currentSize/2)-1;i>=0;i--){
                heapify(i);
            }
        }

        void extract(){
            swap(elements[0],elements[currentSize-1]);
            currentSize--;
            heapify(0);
        }

        void heapsort(){
            buildHeap();
            for(int i=0;i<size;i++){
                extract();
            }
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
                string num1;
                in>>num1;
                string x = num1.substr(1,num1.length()-1);
                string num2;
                in>>num2;
                string y = num2;
                string num3;
                in>>num3;
                string z = num3.substr(0,num3.length()-1);
                heap.insert(atoi(x.c_str()),atoi(y.c_str()),atoi(z.c_str()));
            }
            //heap.printHeap();
            heap.heapsort();
            heap.printHeap();
        }

        else if(type == "double"){
            Heap <double> heap(size);
            for(int i=0;i<size;i++){
                string num1;
                in>>num1;
                string x = num1.substr(1,num1.length()-1);
                string num2;
                in>>num2;
                string y = num2;
                string num3;
                in>>num3;
                string z = num3.substr(0,num3.length()-1);
                heap.insert(atof(x.c_str()),atof(y.c_str()),atof(z.c_str()));
            }
            
            heap.heapsort();
            heap.printHeap();
        }

        else if(type == "bool"){
            Heap <bool> heap(size);
            for(int i=0;i<size;i++){
                string num1;
                in>>num1;
                string x = num1.substr(1,num1.length()-1);
                string num2;
                in>>num2;
                string y = num2;
                string num3;
                in>>num3;
                string z = num3.substr(0,num3.length()-1);
                heap.insert(atoi(x.c_str()),atoi(y.c_str()),atoi(z.c_str()));
            }
            
            heap.heapsort();
            heap.printHeap();
        }

        else if(type == "char"){
            Heap <char> heap(size);
            for(int i=0;i<size;i++){
                string num1;
                in>>num1;
                string x = num1.substr(1,num1.length()-1);
                string num2;
                in>>num2;
                string y = num2;
                string num3;
                in>>num3;
                string z = num3.substr(0,num3.length()-1);
                heap.insert(x[0],y[0],z[0]);
            }
           
            heap.heapsort();
            heap.printHeap();
        }

        
    }
}
