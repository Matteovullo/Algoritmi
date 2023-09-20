#include<iostream>
#include<fstream>

using namespace std;

template<class H>
class Terna{
    H x;
    H y;
    H z;

    public:
        Terna(H x, H y, H z){
            this->x=x;
            this->y=y;
            this->z=z;
        }

        friend bool operator>(Terna &c1, Terna &c2){
            if (c1.x>c2.x) return true;
            if(c1.x==c2.x && c1.y>c2.y) return true;
            if(c1.x==c2.x && c1.y==c2.y && c1.z>c2.z) return true;
            return false;
        }

        friend ostream& operator<<(ostream &os, Terna &c){
            return os<<"("<<c.x<<" "<<c.y<< " " << c.z << ")";
        }
};

template<class H>
class Heap{
    private:
        Terna<H>** heap;
        int heapsize;
        int size;
        int fycalls;

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

        void extract(){
            swap(heap[1], heap[heapsize--]);
            heapify(1);
        }

    public:
        Heap(Terna<H>** heap, int size){
            this->size=size;
            this->heap=heap;
            heapsize=size;
            fycalls=0;
        }

        void build(){
            for(int i=heapsize/2; i>=1; i--){
                heapify(i);
            }
        }

        void heapsort(){
            for(int i=1; i<=size; i++){
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
        Terna<H> **v = new Terna<H> *[n + 1];

        for (int i = 1; i <= n; i++)
        {
            char tmp;
            H x, y, z;

            in >> tmp >> x >> y >> z >> tmp;
            v[i] = new Terna<H>(x, y, z);
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