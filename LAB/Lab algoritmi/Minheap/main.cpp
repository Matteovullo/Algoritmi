#include <iostream>
#include <fstream>
#include <sstream>
#include <typeinfo>
using namespace std;

template <class H>
class Heap{
    private:
        int size;
        H* heap;
        int heapsize;
        int heapifycalls;

        int parent(int i){ return i/2;}
        int left(int i){ return i*2;}
        int right(int i){return (i*2)+1;}

        void heapify(int i){
            if(heapsize>=1)
            heapifycalls++;

            int min=i;
            int l=left(i);
            int r=right(i);
            if(l<=heapsize && heap[l] < heap[min]) min=l;
            if(r<=heapsize && heap[r] < heap[min]) min=r;

            if(min!=i){
                swap(heap[i], heap[min]);
                heapify(min);
            }
        }

    public:
        Heap(int _size){
            heapifycalls=0;
            size=_size;
            heapsize=0;
            heap=new H[size];
        }

        ~Heap(){
            delete[] heap;
        }

        Heap* enqueue(H x){
            if(heapsize==size) return nullptr;
            heap[++heapsize]=x;
            int i=heapsize;
            while(i>1 && heap[i]<heap[parent(i)]){
                swap(heap[i], heap[parent(i)]);
                i=parent(i);
            }
        }

        Heap* extract(){
            heap[1]=heap[heapsize--];
            heapify(1);
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
    void solve(ifstream &in, ofstream &out, int n) {
    Heap<H> heap = Heap<H>(n + 1);

    for (int i=0; i<n; i++) {
    string tmp;
    in >> tmp;

    if (tmp == "extract")
    heap.extract();
    else{
    stringstream s(tmp.substr(2));
    H key;
    s>>key;
    heap.enqueue(key);
    }

    }

    heap.fprint(out);
}

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    for (int i=0; i<100; i++) {
    string type;
    int n;

    in >> type >> n;

    if (type == "int")
    solve<int>(in, out, n);

    else if (type == "double")
    solve<double>(in, out, n);

    else if (type == "bool")
    solve<bool>(in, out, n);

    else if (type == "char")
    solve<char>(in, out, n);
    }
}