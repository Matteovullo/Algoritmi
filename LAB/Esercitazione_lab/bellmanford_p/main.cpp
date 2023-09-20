#include<iostream>
#include<fstream>

using namespace std;

class Edge{
    private:
        int start;
        int end;
        int weight;

    public:
        Edge(int s, int e, int w) : start(s), end(e), weight(w){}

        int s(){return start;}
        int e(){return end;}
        int w(){return weight;}
};

template<class H>
class Graph{
    private:
        Edge** edges;
        int totaledge;
        int esize;

        int totalnode;

    public:
        Graph(int totalnode, int totaledge) {
            this->totalnode = totalnode;
            this->totaledge = totaledge;

            edges = new Edge*[this->totaledge];
            esize = 0;
        }

        void addEdge(int x, int y, int p){
            edges[esize++]=new Edge(x, y, p);
        }

        void bellmanford(H s, H f, int k, ofstream& out){
            int source=s;
            int dest=f;

            int* dist=new int[totalnode];

            for(int i=0; i<totalnode; i++){
                dist[i]=INT_MAX;
            }

            dist[source]=0;

            for(int i=0; i<k; i++){
                for(int j=0; j<esize; j++){
                    int s=edges[j]->s();
                    int e=edges[j]->e();
                    int w=edges[j]->w();

                    if(dist[s]!=INT_MAX && dist[s]+w<dist[e])
                        dist[e]=dist[s]+w;
                }
            }

            if(dist[dest]==INT_MAX)
                out << "inf." << endl;
            else
                out << dist[dest] << endl;
        }
};

template<class H>
void solve(ifstream &in, ofstream &out, int n, int e, int k){
    Graph<H> graph=Graph<H>(n, e);

    for(int i=0; i<e; i++){
        char tmp;
        H x, y;
        int p;
        in>>tmp>>x>>y>>p>>tmp;
        graph.addEdge(x, y, p);
    }

    H start, dest;
    in>>start>>dest;
    graph.bellmanford(start, dest, k, out);
}

int main(){
    ifstream in("output.txt");
    ofstream out("output.txt");

    for(int i=0; i<100; i++){
        int n, e, k;
        in>>n>>e>>k;
        solve<int>(in, out, n, e, k);
    }
}