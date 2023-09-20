#include<iostream>
#include<fstream>

using namespace std;

template<class H>
class Heap{
    private:
        int size;
        int heapsize;
        int heapifycalls;
        H* heap;

        int parent(int i){return i/2;}
        int left(int i){return i*2;}
        int right(int i){return (i*2)+1;}
        void heapify(int i){
            if(heapsize>=1) heapifycalls++;           
            int max=i;
            int l=left(i);
            int r=right(i);

            if(l<=heapsize && heap[l]<heap[max]) max=l;
            if(r<=heapsize && heap[r]<heap[max]) max=r;   

            if(max!=i){
                swap(heap[max], heap[i]);
                heapify(max);
            }         
        }


    public:
        Heap(H* array, int n){
            heap=array;
            size=n;
            heapsize=n;
            heapifycalls=0;
        }

        void build(){
            for(int i=size/2; i>=1; i--){
                heapify(i);
            }
        }

        void extract(){
            swap(heap[1], heap[heapsize--]);
            heapify(1);
        }

        void heapsort(){
            for(int i=1; i<=size; i++){
                extract();
            }
        }

        void print(ofstream &out){
            out << heapifycalls << " ";
            for(int i=1; i<=size; i++){
                out << heap[i] << " ";
            }
            out << endl;
        }
};

template<class H>
void solve(ifstream &in, ofstream &out, int n){
    H* array=new H[n+1];
    for(int j=1; j<=n; j++){
        in >> array[j];
    }

    Heap<H> heap=Heap<H>(array, n);
    heap.build();
    heap.heapsort();
    heap.print(out);
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    for(int i=0; i<100; i++){
        int n;
        string type;
        in>>type>>n;
        if(type=="bool") solve<bool>(in, out, n);
        else if(type=="double") solve<double>(in, out, n);
        else if(type=="int") solve<int>(in, out, n);
        else if(type=="char") solve<char>(in, out, n);    
    }
}