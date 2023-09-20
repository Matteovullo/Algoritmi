#include<iostream>
#include<fstream>

using namespace std;

template<class H>
class Node{
    private:
        H key;
        Node* next;

    public:
        Node(H key, Node<H>* next){
            this->key=key;
            this->next=next;
        }

        Node<H>* getNext(){return next;}
        H getKey(){return key;}
        void setKey(H key){this->key=key;}
        void setNext(Node<H>* node){this->next=node;}
};

template<class H>
class LinkedList{
    private:
        Node<H>* head;
        Node<H>* tail;
        int size;

    public:
        LinkedList(){
            head=tail=new Node<H>(0, nullptr);
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
        HashTable(int size){
            this->size=size;
            bucket=new LinkedList<H>*[size];
            for(int i=0; i<size; i++){
                bucket[i]=new LinkedList<H>();
            }
        }

        void printBucketSize(ofstream &out){
            for(int i=0; i<size; i++){
                out << bucket[i]->getSize() << " ";
            }
            out << endl;
        }

        void virtual insert(H key)=0;
};

template<class H>
class HashDiv : public HashTable<H>{
    public:
        HashDiv(int size) : HashTable<H>(size){}

        void insert(H key){
            int pos=(int)key%this->size;
            this->bucket[pos]->insert(key);
        }
};

template<class H>
void solv(ifstream &in, ofstream &out,int bucket, int n){
    HashDiv<H> table=HashDiv<H>(bucket);
    H key;

    for(int i=0; i<n; i++){
        in>>key;
        table.insert(key);
    }

    table.printBucketSize(out);
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    for(int i=0; i<100; i++){
        string type;
        int bucket, n;
        in>>type>>bucket>>n;
        if(type=="bool") solv<bool>(in, out, bucket, n);
        else if(type=="double") solv<double>(in, out, bucket, n);
        else if(type=="int") solv<int>(in, out, bucket, n);
        else if(type=="char") solv<char>(in, out, bucket, n);
    }
}