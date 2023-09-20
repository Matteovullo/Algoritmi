//lcs
#include<iostream>

using namespace std;

int lsc(string x, string y, int n, int m){
    int** v=new int*[n+1];
    for(int i=0; i<n+1; i++) v[i]=new int[m+1]{0};

    for(int i=1; i<n+1; i++){
        for(int j=1; j<m+1; j++){
            x[i-1]==y[j-1]? v[i][j]=v[i-1][j-1]+1
            : v[i][j]=max(v[i-1][j], v[i][j-1]);
        }
    }
    return v[n][m];
}

//edit
int edit(string x, string y, int n, int m){
    int** v=new int*[n+1];
    for(int i=0; i<n+1; i++) v[i]=new int[m+1]{0};

    for(int i=0; i<n+1; i++) v[i][0]=i;
    for(int j=0; j<m+1; j++) v[0][j]=j;

    for(int i=1; i<n+1; i++){
        for(int j=0; j<m+1; j++){
            x[i-1]==y[j-1]? v[i][j]=v[i-1][j-1]
            : v[i][j]=min(min(v[i-1][j], v[i][j-1]), v[i-1][j-1])+1;
        }
    }
    return v[n][m];
}

//activity
static void sort(Activity** v, int n){

    for(int i=1; i<n; i++){
        int index=i;
        while((index>0 && v[index]->end()<v[index-1]->end()) 
        || (index>0 && v[index]->end() == v[index-1]->end())){
            swap(v[index], v[index-1]);
            index--;
        }
    }
}

static void selector(Activity** v, int n){
    int* p=new int[n]{0}
    for(int i=1; i<n; i++){
        p[i]=v[i]->profit();
    }

    for(int i=1; i<n; i++){
        for(int j=i; j>=0; j--){
            if(v[j]->end() <= v[i]->start()){
                t[i]=max(t[i], t[j]+v[i]->profit());
            }
        }
    }
    int max=v[0];
    for(int i=0; i<n; i++)
    if(v[i]>max) max=v[i];
    return max;
}

//greedy activity
void sort(Activity** v, int n){
    for(int i=1; i<n; i++){
        int index=i;

        while(index>0 && v[index]->end() < v[index-1]->end()){
            swap(v[index], v[index-1]);
            index--;
        }
    }
}

void int selector(Activity** v, int n){
    int max=1;
    int last=0;

    for(int i=1; i<n; i++){
        if(v[i]->start() >= v[last]->end()){
            max++;
            last=i;
        }
    }
    return max;
}

//greedy knpsack
namespace sort{
    void swap(int* v, int x, int y){
        int tmp=v[x];
        v[x]=v[y];
        v[y]=tmp;
    }

    void selector(int* v, int n){
        for(int i=1; i<n; i++){
            int index=i;

            while(index>=1 && v[index]<v[index-1]){
                    swap(v, index, index-1);
                    index--;
                }
        }
    }
}

int knpsakc(int* v int n, int p, ofstream &out){
    sort::selector(v, n);
    int max=0;
    for(int i=0; i<p; i++){
        max+=v[i];
    }
    out << max << endl;
}

//matrix
int matrix_chain(int* v, int n){
    int** table=new int*[n];
    for(int i=0; i<n; i++){
        table[i]=new int[n]{0};
    }

    for(int l=2; l<n; l++){
        for(int i=0; i<n-l; i++){
            int j=l+i;
            table[i][j]=INT_MAX;
            for(int k=i+1; k<j; k++){
                int q=table[i][k]+table[k][j]*v[i]*v[j]*v[k];
                if(q<table[i][j]) table[i][j]=q;
            }
        }
    }
    return table[0][n-1];
}

//bellmanford
void bellmanford(ofstream &out, H s, H f){
    int dest=find_node(f);
    int source=find_node(s);

    int* dist=new int[nsize];
    for(int i=0; i<nsize; i++) dist[i]=INT_MAX;

    dist[sorce]=0;

    for(int i=1; i<nsize; i++){
        for(int j=0; j<esize; j++){
            int e=egdes[j]->getE();
            int s=egdes[j]->getS();
            int w=egdes[j]->getW();

            if(dist[s]!=INT_MAX && dist[s]+w<dist[e]) dist[e]=dist[s]+w;           
        }
    }

    for(int j=0; j<esize; j++){
        int e=egdes[j]->getE();
        int s=egdes[j]->getS();
        int w=egdes[j]->getW();

        if(dist[s]!=INT_MAX && dist[s]+w<dist[e]) out << "undef." << endl;           
    }  

    if(dist[dest] == INT_MAX) out << "inf." << endl;
    else out << dist[dest] << endl; 
}

//dijstra
void dijkstra(ofstream &out, H s, H f){
    int source=finde_node(s);
    int dest=find_node(f);

    int* dest=new int[nsize]{INT_MAX};
    dist[source]=0;

    bool* visit=new bool[nsize]{0};

    for(int i=0; i<nsize; i++){
        int min=INT_MIN;
        int pos=0;
        for(int m=0; m<nsize; m++){
            if(visit[m]==0 && dist[m]<min){
                 min=visit[m];
                pos=m;
            }
        }
        visit[pos]=1;

        for(int j=0; j<esize; j++){
        int e=egdes[j]->getE();
        int s=egdes[j]->getS();
        int w=egdes[j]->getW();

        if(s==posmin && dist[s]+w<dist[e]) dist[e]=dist[s]+w;         
    }  
    }

    if(dist[dest] == INT_MAX) out << "inf" << endl;
    else out << dist[dest] << endl;
}

//heap
void build(){
    for(int i=heapsize/2; i>=1; i++) heapify(i);
}

void print(){
    //out << heapifycalls << endl;
    for(int i=1; i<heapisize; i++) out << heap[i] << endl;
    out << endl;
}

void enqueue(H x){
    heap[++heapsize]=x;
}

void extract(){
    swap(heap[1],heap[heapsize--]);
    heapift(1);
}

void heapsort(){
    for(int i=1; i<heapsize; i++){
        exctract();
    }
}

void heapify(int i){
    if(heapisize<=1) heapifycalls++;

    int l=left(i);
    int r=right(i);
    int max=i;

    if(l<=heapisize && heap[l]<heap[max]) max=l;
    if(r<=heapisize && heap[r]<heap[max]) max=r;

    if(max!=i){
        swap(heap[i], heap[max]);
        heapify(max);
    }
}

//hash div
template<class H>
class Node{
    H key;
    Node* next;

    public:
    Node(H _key, Node<H>* _next) : key(_key), next(_next){}

    H getKey(){return key;}
    Node<H>* getNode(){return node;}
    void setKey(H _key){key=_key;}
    void setNode(Node<H>* _next){next=_next;}
};

template<class H>
class LinkedList{
    Node<H>* head, tail;
    int size;

    public:
        LinkedList(){
            tail=head=new Node<H>(0, nullptr);
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
    LinkedList<H>** bucket;
    int size;

    public:
        HashTable(int _size) : size(_size){
        for(int i=0; i<size; i++)
            bucket[i]=new LinkedList<H>();
        }

        void print(ofstream &out){
            for(int i=0; i<size; i++){
                out << bucket[i]->getSize() << " ";
            }
            out << endl;
        }

        virtual void insert(H key)=0;
};

template<class H>
class HashDiv : public HashTable<H>{
    public:
    HashDiv(int _size) : HashDiv(_size){}

    void insert(H key){
        int pos=(int)key&this->size;
        this->bucket[pos]->insert(key);

        //int pos=this->size*fmod(key*A, 1);
        //this->bucket[pos]->insert(key);
    }
};




