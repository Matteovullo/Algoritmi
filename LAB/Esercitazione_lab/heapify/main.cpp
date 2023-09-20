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

        int parent(int i){return i/2;}
        int left(int i){return i*2;}
        int right(int i){return (i*2)+1;}

        void heapify(int i){
            if(heapsize>=1) 
                heapifycalls++;

            int max=i;
            int l=left(i);
            int r=right(i);

            if(l<=size && heap[l]>heap[max]) max=l;
            if(r<=size && heap[r]>heap[max]) max=r;  

            if(max!=i){
                swap(heap[max], heap[i]);
                heapify(max);
            }          
        } 

    public:
        Heap(int _size, H* _heap){
            heap=_heap;
            size=_size;
            heapsize=_size;
            heapifycalls=0;
        }

        void build(){
            for(int i=size/2; i>=1; i--){
                heapify(i);
            }
        }

        void extract(){
            while(heapsize>0){
                swap(heap[1], heap[heapsize--]);
                heapify(1);
            }
        }

        void fprint(ofstream &out){
            out << heapifycalls << endl;
        }
};

template<class H>
void solve(ifstream &in, ofstream &out, int n){
    H* array=new H[n+1];
    for(int i=1; i<=n; i++){
        in >> array[i];
    }

    Heap<H> heap=Heap<H>(n+1, array);
    heap.build();
    heap.extract();
    heap.fprint(out);
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    for (int i = 0; i < 100; i++)
    {
        string type;
        int size;
        in >> type >> size;

        if (type == "int")
            solve<int>(in, out, size);

        else if (type == "double")
            solve<double>(in, out, size);

        else if (type == "bool")
            solve<bool>(in, out, size);

        else if (type == "char")
            solve<char>(in, out, size);
    }
}