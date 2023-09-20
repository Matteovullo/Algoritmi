#include <iostream>
#include <fstream>
#include <string>
using namespace std;
ifstream in;
ofstream out;
#define INF 100000;

template <class T> class Graph{
    public:
        int **W;
        T*elements;
        int*d;
        int sizeN;
        int currentSize;
        int *check;
        Graph(int size){
            sizeN = size;
            elements = new T [sizeN];
            check = new int [sizeN];
            W = new int *[sizeN];
            for(int i=0;i<sizeN;i++){
                W[i] = new int[sizeN];
            }

            for(int i=0;i<sizeN;i++){
                for(int j=0;j<sizeN;j++){
                    W[i][j] = 100000;
                }
            }
            for(int i=0;i<sizeN;i++){
                check[i] = 0;
            }
            d = new int [sizeN];
            currentSize = 0;

        }
        
        void addNode(T val){
            elements[currentSize] = val;
            currentSize++;
        }

        int searchNode(T val){
            for(int i=0;i<sizeN;i++){
                if(elements[i] == val){
                    return i;
                }
            }
            return -1;
        }
        void addEdge(T node1, T node2, int weight){
            int x = searchNode(node1);
            int y = searchNode(node2);
            W[x][y] = weight;
        }

        void print(){
            for(int i=0;i<sizeN;i++){
                cout<<elements[i]<<" ";
            }
            cout<<endl;
            for(int i=0;i<sizeN;i++){
                for(int j=0;j<sizeN;j++){
                    cout<<W[i][j]<<" ";
                }
                cout<<endl;
            }
        }


        bool allVisited(){
            for(int i=0;i<sizeN;i++){
                if(check[i]==0){
                    return true;
                }
            }

            return false;
        }

        int getMin(){
            int min = 100000;
            int pos;
            for(int i=0;i<sizeN;i++){
                if(check[i]==0){
                    if(d[i] < min){
                        min = d[i];
                        pos = i;
                    }
                }
            }
            return pos;
        }

        void relax(int i, int j){
            if(d[j] > d[i] + W[i][j]){
                d[j] = d[i] + W[i][j];
            }
        }
        void Dijkstra(T so, T de){
            int source = searchNode(so);
            int dest = searchNode(de);

            for(int i=0;i<sizeN;i++){
                d[i] = INF;
            }

            d[source] = 0;

            while(allVisited()){
                int temp = getMin();
                //cout<<d[temp]<<endl;
                check[temp] = 1;
                for(int j=0;j<sizeN;j++){
                    relax(temp,j);
                }
            }

            if(d[dest]==100000){
                out<<"inf."<<endl;
            }

            else{
                out<<d[dest]<<endl;
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
        if(type == "int"){
            Graph <int> g(sizeN);
            for(int i=0;i<sizeN;i++){
                int val;
                in>>val;
                g.addNode(val);
            }

            for(int i=0;i<sizeE;i++){
                string s1;
                in>>s1;
                string node1 = s1.substr(1,s1.length()-1);
                string s2;
                in>>s2;
                string node2 = s2;
                string s3;
                in>>s3;
                string weight = s3.substr(0,s3.length()-1);
                g.addEdge(atoi(node1.c_str()),atoi(node2.c_str()),atoi(weight.c_str()));
            }
            //g.print();
            int x;
            in>>x;
            int y;
            in>>y;
            g.Dijkstra(x,y);
        }

        if(type == "double"){
            Graph <double> g(sizeN);
            for(int i=0;i<sizeN;i++){
                double val;
                in>>val;
                g.addNode(val);
            }

            for(int i=0;i<sizeE;i++){
                string s1;
                in>>s1;
                string node1 = s1.substr(1,s1.length()-1);
                string s2;
                in>>s2;
                string node2 = s2;
                string s3;
                in>>s3;
                string weight = s3.substr(0,s3.length()-1);
                g.addEdge(atof(node1.c_str()),atof(node2.c_str()),atof(weight.c_str()));
            }
            //g.print();
            double x;
            in>>x;
            double y;
            in>>y;
            g.Dijkstra(x,y);
        }


    }
}