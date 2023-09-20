/*#include<iostream>
#include<fstream>

using namespace std;

template<class H>
class Heap{
    private:
        int heapsize;
        int size;
        H* heap;

        int parent(int i){return i/2;}
        //int left(int i){return i*2;}
        //int right(int i){return (i*2)+1;}

        /*
        void heapify(int i){
            int max=i;
            int l=left(i);
            int r=right(i);

            if(l<=heapsize && heap[l]>heap[max]) max=l;
            if(r<=heapsize && heap[r]>heap[max]) max=r;  

            if(max!=i){
                swap(heap[max], heap[i]);
                heapify(max);
            }          
        }

    public:
        Heap(int _size){
            size=_size;
            heapsize=0;
            heap=new H[size];
        }

        void insert(H x){
            if(heapsize == size) return;

            heap[++heapsize]=x;
            int i=heapsize;
            while(i>1 || heap[parent(i)]<heap[i]){
                swap(heap[parent(i)], heap[i]);
                i=parent(i);
            }
        }

        void fprint(ofstream &out){
            for(int i=1; i<=heapsize; i++){
                out << heap[i] << " ";
            }
            out << endl;
        }
};

template<class H>
void solve(ifstream &in, ofstream &out, int n){
    Heap<H> heap=Heap<H>(n+1);
    for(int i=1; i<n+1; i++){
        H x;
        in >> x;
        heap.insert(x);
    }
    heap.fprint(out);
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
}*/

#include <iostream>
#include <fstream>

using namespace std;

template <class H>
class Heap
{

private:
    H *heap;
    int size;
    int maxsize;

    int parent(int i)
    {
        return i / 2;
    }

    void swap(int x, int y)
    {
        H tmp = heap[x];
        heap[x] = heap[y];
        heap[y] = tmp;
    }

public:
    Heap(int _size)
    {
        heap = new H[_size];
        maxsize = _size;
        size = 0;
    }

    ~Heap()
    {
        delete[] heap;
    }

    void enqueue(H key)
    {
        // Max size
        if (size == maxsize)
            return;

        // Inserimento
        heap[++size] = key;

        // Controllo
        int i = size;

        while (i > 1 && heap[parent(i)] > heap[i])
        {
            swap(i, parent(i));
            i = parent(i);
        }
    }

    void fprint(ofstream &out)
    {
        for (int i = 1; i <= size; i++)
            out << heap[i] << " ";

        out << endl;
    }
};

template <class H>
void solve(ifstream &in, ofstream &out, int size)
{
    Heap<H> heap = Heap<H>(size + 1);

    for (int i = 1; i <= size; i++)
    {
        H key;
        in >> key;
        heap.enqueue(key);
    }

    heap.fprint(out);
}

int main()
{
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
