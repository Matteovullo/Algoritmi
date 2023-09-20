#include<iostream>
#include<fstream>

using namespace std;

class Edge{
    private:
        int start;
        int end;
        int weight;

    public:
        Edge(int _start, int _end, int _weight){
            start=_start;
            end=_end;
            weight=_weight;
        }

        int getS(){return start;}
        int getE(){return end;}
        int getW(){return weight;}
};

template<class H>
class Graph{
    private:
        H* nodes;
        int totalnode;
        int nsize;
        Edge** edges;
        int totaledge;
        int esize;

        int finde_node_index(H x){
            for(int i=0; i<nsize; i++){
                if(nodes[i] == x) return i;
            }
            return -1;
        }

    public:
        Graph(int totalnode, int totaledge){
            this->totaledge=totaledge;
            this->totalnode=totalnode;

            edges=new Edge*[totaledge];
            nodes=new H[totalnode];
            esize=nsize=0;
        }

        void addNode(H x){
            nodes[nsize++]=x;
        }

        void addEdge(H x, H y, int p){
            edges[esize++]=new Edge(finde_node_index(x), finde_node_index(y), p);
        }

        void dijkstra(H s, H f, ofstream &out){
            int source=finde_node_index(s);
            int dest=finde_node_index(f);

            int* dist=new int[nsize];

            for(int i=0; i<nsize; i++) dist[i]=INT_MAX;

            dist[source]=0;

            bool* visit=new bool[nsize]{0};

            for(int i=0; i<nsize; i++){
                int min=INT_MAX;
                int posmin=0;

                for(int m=0; m<nsize; m++){
                    if(visit[m]==0 && dist[m] < min){
                        min = dist[m];
                        posmin=m;
                    }
                }
                visit[posmin]=1;

                for(int j=0; j<esize; j++){
                    int s=edges[j]->getS();
                    int e=edges[j]->getE();
                    int w=edges[j]->getW();

                    if(s==posmin && dist[s]+w < dist[e])
                        dist[e]=dist[s]+w;
                }
                if(dist[dest] == INT_MAX)
                    out << "inf" << endl;
                else
                    out << dist[dest] << endl;
            }
        }
};

template<class H>
void solve(ifstream &in, ofstream &out, int n, int e){
    Graph<H> graph=Graph<H>(n, e);

    for(int i=0; i<n; i++){
        H val;
        in >> val;
        graph.addNode(val);
    }

    for(int i=0; i<e; i++){
        char tmp;
        H x, y;
        int p;
        in >>tmp>>x>>y>>p>>tmp;
        graph.addEdge(x, y, p);
    }

    H start, dest;
    in>>start>>dest;
    graph.dijkstra(start, dest, out);
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    for(int i=0; i<100; i++){
        int n, m;
        string type;
        in >>n>>m>>type;
        if(type=="int") solve<int>(in, out, n, m);
        else if (type == "double") solve<double>(in, out, n, m);
    }
}