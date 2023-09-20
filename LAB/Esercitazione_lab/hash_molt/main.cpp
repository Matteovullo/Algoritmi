#include<iostream>
#include<fstream>
#include <math.h>

using namespace std;

template<class T>
class Node{
    private:
        Node* next;
        T key;

    public:
        Node(T _key, Node<T>* _next){
            key=_key;
            next=_next;
        }

        T getKey(){return key;}
        Node<T>* getNext(){return next;}

        void setKey(T key){this->key=key;}
        void setNext(Node<T>* n){next=n;}
};

template<class T>
class LinkedList{
    private:
        Node<T>* head;
        Node<T>* tail;
        int size;

    public:
        LinkedList(){
            size=0;
            head=tail=new Node<T>(0, NULL);
            head->setNext(tail);
        }

        void insert(T key){
            Node<T>* tmp=new Node<T>(key, head->getNext());
            tail->setNext(tmp);
            size++;
        }

        int getSize(){return size;}
};

template<class T>
class HashTable{
    protected:
        LinkedList<T>** bucket;
        int size;

    public:
        HashTable(int _size){
            size=_size;
            bucket=new LinkedList<T>*[size];
            for(int i=0; i<size; i++){
                bucket[i]=new LinkedList<T>();
            }
        }

        void PrintBucket(ofstream &out){
            for(int i=0; i<size; i++){
                out << bucket[i]->getSize() << " ";
            }
            out << endl;
        }
};

template<class T>
class HashMult : public HashTable<T>{
    private:
        const double c=0.61803;
    public:
        HashMult(int size) : HashTable<T>(size){}

        void insert(T key){
            int pos=this->size*fmod(key*c, 1);
            this->bucket[pos]->insert(key);
        }
};

template <class T>
void solve(ifstream &in, ofstream &out, int bucket, int n)
{
    HashMult<T> table = HashMult<T>(bucket);
    T key;

    for (int i = 0; i < n; i++)
    {
        in >> key;
        table.insert(key);
    }

    table.PrintBucket(out);
}

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");

    for (int i = 0; i < 100; i++)
    {
        string type;
        int bucket, n;

        in >> type >> bucket >> n;

        if (type == "int")
            solve<int>(in, out, bucket, n);

        else if (type == "bool")
            solve<bool>(in, out, bucket, n);

        else if (type == "double")
            solve<double>(in, out, bucket, n);

        else if (type == "char")
            solve<char>(in, out, bucket, n);
    }
}