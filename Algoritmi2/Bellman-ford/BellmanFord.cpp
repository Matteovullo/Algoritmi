#include <iostream>
#include <fstream>
#include <string>
using namespace std;
ifstream in;
ofstream out;
#define inf 100000;


template <class T> class Graph{
    public:
        T* elements;
        int currentSize;
        int sizeN;
        int sizeE;
        int** W;
        int *d;

        Graph(int x, int y){
            sizeN = x;
            sizeE = y;

            elements = new T [sizeN];

            W = new int * [sizeE];
            for(int i=0;i<sizeE;i++){
                W[i] = new int [sizeE];
            }

            for(int i=0;i<sizeE;i++){
                for(int j=0;j<sizeE;j++){
                    W[i][j] = inf;
                }
            }

            
            currentSize = 0;

            d = new int [sizeN];

        }

        int searchNode(T val){
            for(int i=0;i<sizeN;i++){
                if(elements[i] == val){
                    return i;
                }
            }
            return 0;
        }

        void addNode(T val){    
            elements[currentSize] = val;
            currentSize++;
        }

        void addEdge(T node1, T node2, int weight){
            int x = searchNode(node1);
            int y = searchNode(node2);
            W[x][y] = weight;
        }

        void relax(int i, int j){
            if(d[j] > d[i] + W[i][j]){
                d[j] = d[i] + W[i][j];
            }
        }

        void bellmanFord(T source, T destination){
            int s = searchNode(source);
            int t = searchNode(destination);
            for(int i=0;i<sizeN;i++){
                d[i] = inf;
            }
            d[s] = 0;



            for(int i=0;i<sizeN;i++){
                for(int j=0;j<sizeN;j++){
                    for(int k=0;k<sizeN;k++){
                        relax(j,k);
                    }
                }
            }

            for(int i=0;i<sizeN;i++){
                for(int j=0;j<sizeN;j++){
                    for(int k=0;k<sizeN;k++){
                        if(d[j] > d[i] + W[i][j]){
                            out<<"undef."<<endl;
                            return;
                        }
                    }
                }
            }


            printD();

            if(d[searchNode(destination)] == 100000){
                out<<"inf."<<endl;
                return;
            }

            out<<d[searchNode(destination)]<<endl;
        }
        
        void printElements(){
            for(int i=0;i<sizeN;i++){
                cout<<elements[i]<<" ";
            }
            cout<<endl;
        }

        void printEdge(){
            for(int i=0;i<sizeN;i++){
                for(int j=0;j<sizeN;j++){
                    cout<<"nodoS: "<<elements[i]<<" nodoD: "<<elements[j]<<" peso: "<<W[i][j]<<endl;
                }
            }
        }

        void printD(){
            for(int i=0;i<sizeN;i++){
                cout<<"nodo: "<<elements[i]<<" - "<<d[i]<<endl;
            }
        }

};
int main(){
    in.open("input.txt");
    out.open("output.txt");
    for(int task=0;task<100;task++){
        int sizeN;
        in>>sizeN;
        int sizeE;
        in>>sizeE;
        string type;
        in>>type;

        if(type=="int"){
            Graph <int> g(sizeN,sizeE);
            for(int i=0;i<sizeN;i++){
                int val;
                in>>val;
                g.addNode(val);
            }
            //g.printElements();
            for(int i=0;i<sizeE;i++){
                string s1;
                in>>s1;
                string node1 = s1.substr(1,s1.length()-1);
                //cout<<node1<<" ";
                string s2;
                in>>s2;
                string node2 = s2;
                //cout<<node2<<" ";
                string s3;
                in>>s3;
                string weight = s3.substr(0,s3.length()-1);
                //cout<<weight<<" "<<endl;
                g.addEdge(atoi(node1.c_str()),atoi(node2.c_str()),atoi(weight.c_str()));
            }
            //g.printEdge();
            int s;
            in>>s;
            int d;
            in>>d;
            g.bellmanFord(s,d);
            
        }

        if(type=="double"){
            Graph <double> g(sizeN,sizeE);
            for(int i=0;i<sizeN;i++){
                double val;
                in>>val;
                g.addNode(val);
            }
            //g.printElements();
            for(int i=0;i<sizeE;i++){
                string s1;
                in>>s1;
                string node1 = s1.substr(1,s1.length()-1);
                //cout<<node1<<" ";
                string s2;
                in>>s2;
                string node2 = s2;
                //cout<<node2<<" ";
                string s3;
                in>>s3;
                string weight = s3.substr(0,s3.length()-1);
                //cout<<weight<<" "<<endl;
                g.addEdge(atof(node1.c_str()),atof(node2.c_str()),atoi(weight.c_str()));
            }
            //g.printEdge();
            double s;
            in>>s;
            double d;
            in>>d;
            g.bellmanFord(s,d);
            
        }
    }
}