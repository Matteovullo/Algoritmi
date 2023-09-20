#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;
ifstream in;
ofstream out;

template <class T> class coppie{
    public:
        T x;
        T y;
        
        coppie(T x, T y){
            this->x = x;
            this->y = y;
            
        }
};


template <class T> class Heap{
    public:
        coppie <T> **elements;
        int dim;
        int currentsize;
        int count;
        Heap(int d){
            dim = d;
            currentsize = 0;
            elements = new coppie <T> *[dim];
            count=0;
        }

        int getP(int i){
            return floor((i-1)/2);
        }

        int getSx(int i){
            return i*2 +1;
        }

        int getDx(int i){
            return i*2 +2;
        }

        bool compare(coppie <T>*a, coppie<T> *b){
            if(a->x > b->x){
                return true;
            }

            if(a->x == b->x && a->y > b->y){
                return true;
            }

            return false;
        }

        void swap(coppie <T> **vett,int a,int b){
            coppie <T>*temp = vett[a];
            vett[a] = vett[b];
            vett[b] = temp;
        }
        void insert(T x, T y){
            elements[currentsize] = new coppie <T> (x,y);
            //cout<<elements[currentsize]->x<<" - "<<elements[currentsize]->y<<endl;
            currentsize ++; 
            int i = currentsize-1;
            //while(i > 0 && compare(elements[i],elements[getP(i)])){
              //  swap(elements,i,getP(i));
                //i=getP(i);
           // }
        }

        void heapify(int i){
            
            if(currentsize==0) return;
            count++;
            int max = i;
            if(getSx(i) < currentsize && compare(elements[getSx(i)],elements[max])){
                max = getSx(i);
            }

            if(getDx(i) < currentsize && compare(elements[getDx(i)],elements[max])){
                max = getDx(i);
            }

            if(max!=i){
                swap(elements,max,i);
                heapify(max);
            }
        }

        void buildheap(){
            for(int i=round(currentsize/2)-1;i>=0;i--){
                heapify(i);
            }
        }

        void printHeap(){
            out<<count;
            for(int i=0;i<dim;i++){
                out<<" ("<<elements[i]->x<<" "<<elements[i]->y<<")";
            }
        }

        void extractmax(){
            swap(elements,0,currentsize-1);
            currentsize--;
            heapify(0);
        }

        void heapsort(){
            buildheap();
            for(int i=0;i<dim;i++){
                extractmax();
            }
        }

};

int main(){
    in.open("input.txt");
    out.open("output.txt");

    for(int task=0;task<100;task++){
        string type;
        in>>type;
        int dim;
        in>>dim;
        if(type=="int"){
            Heap <int> heap(dim);
            for(int i=0;i<dim;i++){
                string num1;
                string num2;
                in>>num1;
                in>>num2;
                string xs = num1.substr(1,num1.length()-1);
                string ys = num2.substr(0,num2.length()-1);
                int x = atoi(xs.c_str());
                int y = atoi(ys.c_str());
                heap.insert(x,y);
                
            }   
            heap.heapsort();
            heap.printHeap();
        }

        else if(type=="double"){
            Heap <double> heap(dim);
            for(int i=0;i<dim;i++){
                string num1;
                string num2;
                in>>num1;
                in>>num2;
                string xs = num1.substr(1,num1.length()-1);
                string ys = num2.substr(0,num2.length()-1);
                double x = atof(xs.c_str());
                double y = atof(ys.c_str());
                cout<<x<<endl;
                heap.insert(x,y);
                cout<<heap.elements[heap.currentsize-1]->x<<endl;
            }   
            heap.heapsort();
            heap.printHeap();
        }

        else if(type=="bool"){
            Heap <bool> heap(dim);
            for(int i=0;i<dim;i++){
                string num1;
                string num2;
                in>>num1;
                in>>num2;
                string xs = num1.substr(1,num1.length()-1);
                string ys = num2.substr(0,num2.length()-1);
                int x = atoi(xs.c_str());
                int y = atoi(ys.c_str());
                heap.insert(x,y);
            }   
            heap.heapsort();
            heap.printHeap();
        }

        else if(type=="char"){
            Heap <char> heap(dim);
            for(int i=0;i<dim;i++){
                string num1;
                string num2;
                in>>num1;
                in>>num2;
                string xs = num1.substr(1,num1.length()-1);
                string ys = num2.substr(0,num2.length()-1);
                char x = xs[0];
                char y = ys[0];
                heap.insert(x,y);
            }   
            heap.heapsort();
            heap.printHeap();
        }
        out<<endl;
    }
}