#include<iostream>
#include<fstream>

using namespace std;

template<class H>
class Node{
    private:
        Node* next;
        H key;

    public:
        Node(H k, Node<H>* n) : key(k), next(n){}
        H getKey(){return key;}
        void setKey(H k){key=k;}
        Node<H>* getNext(){return next;}
        void setNext(Node<H>* n){next=n;}     
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
            size=0;
        }

        void insert(H key){
            Node<H>* tmp=new Node<H>(key, head->getNext());
            tail->setNext(tmp);
            size++;
        }

        int getSize(){return size;}
};

template<class H>
class HashTable{
    protected:
        int size;
        LinkedList<H>** bucket;

    public:
        HashTable(int s) : size(s){
            bucket=new LinkedList<H>*[size];
            for(int i=0; i<size; i++) bucket[i]=new LinkedList<H>();
        }

        void printBucketSize(ofstream &out){
            for(int i=0; i<size; i++) 
                out << bucket[i]->getSize() << " ";
            out << endl;
        }

        virtual void insert(H key)=0;
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
void solve(ifstream &in, ofstream &out, int bucket, int n){
    HashDiv<H> table=HashDiv<H>(bucket);

    for(int i=0; i<n; i++){
        H key;
        in >> key;
        table.insert(key);
    }

    table.printBucketSize(out);
}

int main() {
ifstream in("input.txt");
ofstream out("output.txt");

for (int i = 0; i < 100; i++) {
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
