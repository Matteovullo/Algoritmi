#include<iostream>
#include<fstream>

using namespace std;

template<class H>
class Terne{
    private:
        H x;
        H y;
        H z;

    public:
        Terne(H _x, H _y, H _z) : x(_x), y(_y), z(_z){}

        friend bool operator>(Terne<H> t1, Terne<H> t2){
            if((t1.x>t2.x) || (t1.x==t2.x && t1.y>t2.y) ||
            (t1.x==t2.x && t1.y==t2.y && t1.z>t2.z)) return true;
            else return false;
        }

        friend ostream& operator<<(ostream &os, Terne<H> &t){
            return os<<"("<<t.x<<","<<t.y<<","<<t.z<<")";
        }
};

template<class H>
class Heap{
    private:
        int heapsize;
        int size;
        int fycalls;
        Terne<H>** heap;

        int parent(int i){return i/2;}
        int left(int i){return i*2;}
        int right(int i){return (i*2)+1;}

        void heapify(int i){
            if(heapsize>=1) fycalls++;

            int l=left(i);
            int r=right(i);
            int m=i;
            
            if(l<=heapsize && *heap[l] > *heap[m]) m=l;
            if(r<=heapsize && *heap[r] > *heap[m]) m=r;
            if(m!=i){
                swap(heap[i], heap[m]);
                heapify(m);
            }            
        }


    public:
        Heap(Terne<H>** _heap, int n){
            heapsize=n;
            size=n;
            fycalls=0;
            heap=_heap;
        }

        void build(){
            for(int i=heapsize/2; i>=1; i--){
                heapify(i);
            }
        }

        void extract(){
            swap(heap[1], heap[heapsize--]);
            heapify(1);
        }

        void heapsort(){
            for(int i=1; i<=heapsize; i++){
                extract();
            }
        }

        void fprint(ostream &out){
            out << fycalls << " ";
            for(int i=1; i<=size; i++){
                out << *heap[i] << " ";
            }
            out << endl;
        }
};

template <class H>
void solve(ifstream &in, ofstream &out, int n)
{
        Terne<H> **v = new Terne<H> *[n + 1];

        for (int i = 1; i <= n; i++)
        {
            char tmp;
            H x, y, z;

            in >> tmp >> x >> y >> z >> tmp;
            v[i] = new Terne<H>(x, y, z);
        }

        Heap<H> heap = Heap<H>(v, n);
        heap.build();
        heap.heapsort();
        heap.fprint(out);
}

int main()
{
        ifstream in("input.txt");
        ofstream out("output.txt");

        for (int i = 0; i < 100; i++)
        {
            string type;
            int n;
            in >> type >> n;

            if (type == "int" || type == "bool")
                solve<int>(in, out, n);

            else if (type == "double")
                solve<double>(in, out, n);

            else if (type == "char")
                solve<char>(in, out, n);
        }
}