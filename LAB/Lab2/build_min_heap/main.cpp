#include<iostream>
#include<fstream>

using namespace std;

template<class H>
class Heap{
    private:
        int size;
        int heapsize;
        H* heap;

    public:
        Heap(H* a, int n){
            size=n;
            heapsize=n;
            heap=a;
        }

        int left(int i){return i*2;}
        int right(int i){return (i*2)+1;}
        //int parent(int i){return i/2;}

        void heapify(int i){
            int l=left(i);
            int r=right(i);
            int max=i;

            if(l<=heapsize && heap[l]<heap[max]) max=l;
            if(r<=heapsize && heap[r]<heap[max]) max=r;

            if(max!=i){
                swap(heap[i], heap[max]);
                heapify(max);
            }       
        }

        void build(){
            for(int i=heapsize/2; i>=1; i--) heapify(i);
        }

        void print(ofstream &out){
            for(int i=1; i<=heapsize; i++){
                out << heap[i] << " ";
            }
            out << endl;
        }
};

template<class H>
void solve(ifstream &in, ofstream &out, int n){
    H* a=new H[n+1];
    for(int i=1; i<=n; i++){
        in>>a[i];
    }

    Heap<H> heap=Heap<H>(a, n);
    heap.build();
    heap.print(out);
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    for(int i=0; i<100; i++){
        string t;
        int n;
        in>>t>>n;
        if(t=="bool") solve<bool>(in, out, n);
        else if(t=="double") solve<double>(in, out, n);   
        else if(t=="int") solve<int>(in, out, n);
        else if(t=="char") solve<char>(in, out, n);
    }
}