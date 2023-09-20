#include<iostream>
#include<fstream>
#include<cmath>

using namespace std;

template<class H>
class Node{
    private:
        Node<H>* next;
        H key;

    public:
        Node(H _key, Node<H>* n) : key(_key), next(n){}

        Node<H>* getNext(){return next;}
        H getKey(){return key;}
        void setNext(Node<H>* n){next=n;}
        void setKey(H k){key=k;}
};

template<class H>
class LinkedList{
    private:
        int size;
        Node<H>* head;
        Node<H>* tail;

    public:
        LinkedList(){
            head=tail=new Node<H>(0, NULL);
            head->setNext(tail);
            size=0;
        }

        void insert(H key){
            Node<H>* tmp=new Node<H>(key, head->getNext());
            head->setNext(tmp);
            size++;
        }

        int getSize(){return size;}
};

template<class H>
class HashTable{
    protected:
        LinkedList<H>** bucket;
        int size;

    public:
        HashTable(int s) : size(s){
            bucket=new LinkedList<H>*[size];
            for(int i=0; i<size; i++){
                bucket[i]=new LinkedList<H>();
            }
        }

        void printbucket(ofstream &out){
            for(int i=0; i<size; i++){
                out << bucket[i]->getSize() << " ";
            }
            out << endl;
        }

        virtual void insert(H key)=0;
};

template<class H>
class HashMult : public HashTable<H>{
    private:
        double const A=0.61803;

    public:
        HashMult(int _size) : HashTable<H>(_size){}
        void insert(H key){
            int pos=this->size*fmod(key*A, 1);
            this->bucket[pos]->insert(key);
        }
};

template<class H>
void solve(ifstream &in, ofstream &out, int n, int m){
    HashMult<H> table=HashMult<H>(n);

    for(int i=0; i<m; i++){
        H key;
        in>>key;
        table.insert(key);
    }

    table.printbucket(out);
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    for(int i=0; i<100; i++){
        string type;
        int n, m;
        in>>type>>n>>m;
        if(type=="bool") solve<bool>(in, out, n, m);
        else if(type=="double") solve<double>(in, out, n, m);
        else if(type=="int") solve<int>(in, out, n, m);
        else if(type=="char") solve<char>(in, out, n, m);  
    }
}
