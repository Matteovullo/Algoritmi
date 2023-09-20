#include <iostream>
#include <fstream>
#include <string>
using namespace std;
ifstream in;
ofstream out;

template <class T> class Node{
    public:
    Node <T> * succ;
    T val;
    Node (T val){
        this->val = val;
        succ = NULL;
    }
    
};

template <class T> class List{
    public:
        Node <T> * head;
        int count;
        List (){
            head = NULL;
            count = 0;
        }

        void insert(T val){
            Node <T> * nuovo = new Node <T> (val);
            nuovo->succ = head;
            head = nuovo;
            count++;
        }
};

template <class T> class hashTable{
    public:
    int size;
    List <T> **Table;

    hashTable(int size){
        this->size = size;
        Table = new List <T>* [size];
        for(int i=0;i<size;i++){
            Table[i] = new List<T>();
        }
    }
    void insert(T val){
        int function = (int(val)%size);
        Table[function]->insert(val);
    }

    void print(){
        for(int i=0;i<size;i++){
            out<<Table[i]->count<<" ";
        }
        out<<endl;
    }
};

int main(){
    in.open("input.txt");
    out.open("output.txt");

    for(int task = 0;task<100;task++){
        string type;
        int sizeTable;
        int numberKeys;
        in>>type;
        in>>sizeTable;
        in>>numberKeys;

        if(type == "int"){
            hashTable <int> table(sizeTable);
            for(int i=0;i<numberKeys;i++){
                int val;
                in>>val;
                table.insert(val);
            }
            table.print();
        }

        else if(type == "double"){
            hashTable <double> table(sizeTable);
            for(int i=0;i<numberKeys;i++){
                double val;
                in>>val;
                table.insert(val);
            }
            table.print();
        }
        else if(type == "bool"){
            hashTable <bool> table(sizeTable);
            for(int i=0;i<numberKeys;i++){
                bool val;
                in>>val;
                table.insert(val);
            }
            table.print();
        }

        else if(type == "char"){
            hashTable <char> table(sizeTable);
            for(int i=0;i<numberKeys;i++){
                char val;
                in>>val;
                table.insert(val);
            }
            table.print();
        }
    }

}