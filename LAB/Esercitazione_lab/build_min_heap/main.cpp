#include<iostream>
#include<fstream>

using namespace std;

template<class H>
class Heap{
    private:
        int size;
        H* heap;

        int parent(int i){return i/2;}
        int left(int i){return i*2;}
        int right(int i){return (i*2)+1;}

        void heapify(int i){
            int max=i;
            int l=left(i);
            int r=right(i);

            if(l<=size && heap[l]<heap[max]) max = l;
            if(r<=size && heap[r]<heap[max]) max = r; 

            if(max!=i){
                swap(heap[max], heap[i]);
                heapify(max);
            }          
        }

    public:
        Heap(H* array, int _size){
            size=_size;
            heap=array;
        }

        void build(){
            for(int i=size/2; i>0; i--){
                heapify(i);
            }
        }

        void fprint(ofstream &out){
            for(int i=1; i<=size; i++){
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
    heap.fprint(out);
    delete[] array;
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    for(int i=0; i<100; i++){
        string type;
        in >> type;
        int n;
        in >> n;
        if(type=="bool") solve<bool>(in, out, n);
        else if(type=="double") solve<double>(in, out, n);
        else if(type=="int") solve<int>(in, out, n);
        else if(type=="char") solve<char>(in, out, n);      
    }
}