#include<iostream>
#include<fstream>

using namespace std;

template<class H>
class Heap{
    private:
        int heapsize;
        int size;
        int heapifycalls;
        H* heap;

        int left(int i){return i*2;}
        int right(int i){return (i*2)+1;}
        int parent(int i){return i/2;}

        void heapify(int i){
            if(size>=1) heapifycalls++;

            int max=i;
            int l=left(i);
            int r=right(i);

            if(l<=size && heap[l]>heap[max]) max=l;
            if(r<=size && heap[r]>heap[max]) max=r;

            if(max!=i){
                swap(heap[i], heap[max]);
                heapify(max);
            }
        }

    public:
        Heap(H* _heap, int n){
            heap=_heap;
            size=n;
            heapsize=n;
            heapifycalls=0;
        }

        void build(){
            for(int i=heapsize/2; i>=1; i--){
                heapify(i);
            }
        }

        void extract(){
            swap(heap[1], heap[size--]);
            heapify(1);
        }

        void heapsort(){
            for(int i=1; i<=heapsize; i++){
                extract();
            }
        }

        void fprint(ofstream &out){
            out << heapifycalls << " ";
            for(int i=1; i<=heapsize; i++){
                out << heap[i] << " ";
            }
            out << endl;
        }
};

template<class H>
void solve(ifstream &in, ofstream &out, int n){
    H* array=new H[n+1];

    for(int i=1; i<=n; i++){
        in >> array[i];
    }

    Heap<H> heap=Heap<H>(array, n);
    heap.build();
    heap.heapsort();
    heap.fprint(out);
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    for(int i=0; i<100; i++){
        string type;
        int n;
        in >> type >> n;
        if(type=="bool") solve<bool>(in, out, n);
        else if(type=="double") solve<double>(in, out, n);
        else if(type=="int") solve<int>(in, out, n);
        else if(type=="char") solve<char>(in, out, n);
    }
}