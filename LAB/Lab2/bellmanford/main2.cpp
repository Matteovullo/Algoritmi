#include<iostream>
#include<fstream>

using namespace std;

class Edge{
    int s;
    int e;
    int w;

    public:
        Edge(int _s, int _e, int _w) : s(_s), e(_e), w(_w){}

        int getS(){return s;}
        int getE(){return e;}
        int getW(){return w;}
};

template<class H>
class Graph{
    Edge** edges;
    int totaledges;
    int esize;

    H* nodes;
    int totalnode;
    int nsize;

        int find_node(H x){
            for(int i=0; i<nsize; i++) 
                if(nodes[i]==x) return i;
            return -1;
        }

    public:
        Graph(int te, int tn){
            totaledges=te;
            totalnode=tn;
            edges=new Edge*[totaledges];
            esize=nsize=0;
        }

        void addNode(H x){ nodes[nsize++]=x;}
        void addEdge(H x, H y, int p){
            edges[esize++]=new Edge(find_node(x), find_node(y), p);
        }

        /*
        void bellmanford(H s, H e, ofstream &out){
            int source=find_node(s);
            int dest=find_node(e);

            int* dist=new int[nsize];

            for(int i=0; i<esize; i++) dist[i]=INT_MAX;

            dist[source]=0;

            for(int i=1; i<nsize; i++){
                for(int j=0; j<esize; j++){
                    int e=edges[j]->getE();
                    int s=edges[j]->getS();
                    int w=edges[j]->getW();

                    if(dist[s] != INT_MAX && dist[s]+w < dist[e])
                        dist[e]=dist[s]+w;
                }
            }

            for(int k=0; k<esize; k++){
                    int e=edges[k]->getE();
                    int s=edges[k]->getS();
                    int w=edges[k]->getW();

                    if(dist[s] != INT_MAX && dist[s]+w < dist[e])
                    out << "undef." << endl;
                        return;
            }
            if(dist[dest]==INT_MAX) out << "inf." << endl;
            else out << dist[dest] << endl;
        }
        */

       void bellmanford(ofstrema &out, H s, H e){
            int source=find_node(s);
            int dest=find_node(e);

            int* dist=new int[nsize];
            for(int i=0; i<nsize; i++) dist[i]=INT_MAX;
            
            dist[source]=0;
            for(int i=0; i<nsize; i++){
                for(int j=0; j<esize; j++){
                    int e=edges[j]->getE();
                    int s=edges[j]->getS();
                    int w=edges[j]->getW();

                    if(dist[s]!=INT_MAX && dist[s]+w<dist[e]) dist[e]=dist[s]+w;
                }
            }

            for(int j=0; j<esize; j++){
                int e=edges[j]->getE();
                int s=edges[j]->getS();
                int w=edges[j]->getW();

                if(dist[s]!=INT_MAX && dist[s]+w<dist[e]){
                     out << "undef." << endl;
                     return;
                }
            }
            if(dist[dest]==INT_MAX) out << "inf." << endl;
            else out << dist[dest] << endl;
       }
};

template<class H>
void solve(ifstream &in, ofstream &out, int n, int m){
    Graph<H> graph=Graph<H>(n, m);

    for(int i=0; i<n; i++){
        H r;
        in>>r;
        graph.addNode(r);
    }

    for(int j=0; j<m; j++){
        char tmp;
        H s, e; 
        int w;
        in>>tmp>>s>>e>>w>>tmp;
        graph.addEdge(s, e, w);
    }

    H start, end;
    graph.bellmanford(start, end, out);
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    for(int i=0; i<100; i++){
        int n, m;
        string type;
        in>>n>>m>>type;
        if(type=="int")
            solve<int>(in, out, n, m);
        else if(type=="double")
            solve<int>(in, out, n, m);
    }
}