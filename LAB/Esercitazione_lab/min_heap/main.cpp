#include<iostream>
#include<fstream>
#include<sstream>
#include<typeinfo>

using namespace std;

template<class H>
class Heap{
    private:
        int heapsize;
        int size;
        H* heap;
        int heapifycalls;

        int parent(int i){return i/2;}
        int left(int i){return i*2;}
        int right(int i){return (i*2)+1;}

        void heapify(int i){
            if(heapsize>=1) heapifycalls++;

            int l=left(i);
            int r=right(i);
            int max=i;

            if(r<=heapsize && heap[r] < heap[max]) max=r;
            if(l<=heapsize && heap[l] < heap[max]) max=l; 

            if(max!=i){
                swap(heap[max], heap[i]);
                heapify(max);
            }          
        }

    public:
        Heap(int _size){
            size=_size;
            heapsize=0;
            heapifycalls=0;
            heap=new H[size];
        }

        void enqueue(H x){
            if(heapsize==size) return;
            heap[heapsize++]=x;
            int i=heapsize;
            while(i>=0 && heap[i] > heap[parent(i)]){
                swap(heap[i], heap[parent(i)]);
                i=parent(i);
            }
            //return this;
        }

        void extract(){
            //H tmp=heap[1];
            heap[1]=heap[heapsize--];
            heapify(1);
            //return tmp;
        }

        void print(ofstream &out){
            out << heapifycalls << " ";
            for(int i=1; i<heapsize; i++){
                out << heap[i] << " ";
            }
            out << endl;
        }
};

template<class H>
void solve(ifstream &in, ofstream &out, int n){
    Heap<H> heap=Heap<H>(n+1);

    for(int i=0; i<n; i++){
        string type;
        in >> type;
        if(type=="extract"){
            heap.extract();
        }else{
            stringstream s(type.substr(2));
            H key;
            s >> key;
            heap.enqueue(key);
        }
        type="";
    }
    heap.print(out);
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    for(int i=0; i<100; i++){
        string type;
        int n;
        in >> type >> n;
        if(type=="bool") solve<bool>(in ,out, n);
        else if(type=="double") solve<double>(in ,out, n);       
        else if(type=="char") solve<char>(in ,out, n);
        else if(type=="int") solve<int>(in ,out, n);
    }
}