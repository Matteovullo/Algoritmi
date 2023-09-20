#include <iostream>
#include <fstream>
#include <string>
using namespace std;
ifstream in;
ofstream out;

class Graph{
    public:
        int *elements;
        int sizeN;
        int currentSize;
        int sizeM;
        int **W;
        int *d;

        Graph(int sizeN, int sizeM){
            this->sizeN = sizeN;
            this->sizeM = sizeM;
            currentSize = 0;
            W = new int*[sizeN];
            for(int i=0;i<sizeN;i++){
                W[i] = new int [sizeN];
            }

            for(int i=0;i<sizeN;i++){
                for(int j=0;j<sizeN;j++){
                    W[i][j] = 100000;
                }
            }

            elements=new int [sizeN];
            
            d=new int [sizeN];
        }

        bool checkVal(int val){
            for(int i=0;i<currentSize;i++){
                if(val == elements[i]){
                    return false;
                }
            }
            return true;
        }

        void addNode(int val){
            if(checkVal(val)){
                elements[currentSize] = val;
                currentSize++;
            }
        }


        void swap(int i,int j){
            int temp = elements[i];
            elements[i] = elements[j];
            elements[j] = temp;
        }
        void sort(){
            for(int i=0;i<sizeN;i++){
                int min=i;
                for(int j=i;j<sizeN;j++){
                    if(elements[j] < elements[min]){
                        min = j;
                    }
                }
                swap(i,min);
            }
        }
        int getIndex(int val){
            for(int i=0;i<currentSize;i++){
                if(elements[i] == val){
                    return i;
                }
            }
            return -1;
        }
        void addEdge(int x1, int y1, int weight){
           int x=getIndex(x1);
           int y=getIndex(y1);
           if(x1!=-1 && y1!=-1){
               W[x][y] = weight;
           }
        }

        void printGraph(){
            cout<<"nodes: ";
            for(int i=0;i<currentSize;i++){
                cout<<elements[i]<<" ";
            }
            cout<<endl;
            cout<<"W: ";
            for(int i=0;i<sizeN;i++){
                for(int j=0;j<sizeN;j++){
                    cout<<W[i][j]<<" ";
                }
                cout<<endl;
            }
        }

        void relax(int x, int y){
            if(d[y]>d[x] + W[x][y]){
                d[y]=d[x] + W[x][y];
            }
        }

        
        void bellmanFordP(int source, int dest, int z){
            int s = getIndex(source);
            int f = getIndex(dest);
            for(int i=0;i<sizeN;i++){
                d[i] = 100000;
            }
            d[s] = 0;
            
            for(int i=0;i<sizeN && z != 0;i++){
                z--;
                cout<<z<<endl;
                for(int j=0;j<sizeN;j++){
                    for(int k=0;k<sizeN;k++){
                        relax(j,k);
                    }
                }
            }

            if(d[f] == 100000){
                cout<<"inf."<<endl;
            }
            else{
                out<<d[f]<<endl;
            }
        }
};


int main(){
    in.open("input.txt");
    out.open("output.txt");
    for(int task=0;task<8;task++){
        int sizeN;
        in>>sizeN;
        int sizeE;
        in>>sizeE;
        int k;
        in>>k;
        Graph g(sizeN,sizeE);
        for(int i=0;i<sizeE;i++){
            string num1;
            in>>num1;
            string node1 = num1.substr(1,num1.length()-1);
            string num2;
            in>>num2;
            string node2 = num2;
            string num3;
            in>>num3;
            string node3 = num3.substr(0,num3.length()-1);
            //cout<<node1<<" "<<node2<<" "<<node3<<endl;
            int x = atoi(node1.c_str());
            int y = atoi(node2.c_str());
            int weight = atoi(node3.c_str());
            g.addNode(x);
            g.addNode(y);
            g.addEdge(x,y,weight);
        }
        int source;
        in>>source;
        int dest;
        in>>dest;
        g.bellmanFordP(source,dest,k);
    }
}