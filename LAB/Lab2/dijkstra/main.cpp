#include <iostream>
#include <fstream>
#include <limits.h>

using namespace std;

class Edge
{
private:
    int start;
    int end;
    int weight;

public:
    Edge(int start, int end, int weight)
    {
        this->start = start;
        this->end = end;
        this->weight = weight;
    }

    int getS()
    {
        return start;
    }

    int getE()
    {
        return end;
    }

    int getW()
    {
        return weight;
    }
};

template <class H>
class Graph
{
private:
    H *nodes;
    int totalnode;
    int nsize;

    Edge **edges;
    int totaledge;
    int esize;

    int find_node_index(H x)
    {
        for (int i = 0; i < nsize; i++)
            if (nodes[i] == x)
                return i;

        return -1;
    }

public:
    Graph(int totalnode, int totaledge)
    {
        this->totalnode = totalnode;
        this->totaledge = totaledge;

        edges = new Edge *[this->totaledge];
        nodes = new H[this->totalnode];

        esize = nsize = 0;
    }

    ~Graph()
    {
    }

    void addNode(H x)
    {
        nodes[nsize++] = x;
    }

    void addEdge(H x, H y, int p)
    {
        int posx = find_node_index(x);
        int posy = find_node_index(y);

        edges[esize++] = new Edge(posx, posy, p);
    }

    /*
    void bellmanFord(H s, H f, ofstream &out)
    {
        int source = find_node_index(s);
        int dest = find_node_index(f);

        int *dist = new int[nsize];

        for (int i = 0; i < nsize; i++)
            dist[i] = INT_MAX;

        dist[source] = 0;

        bool* b=new int[nsize];

        for(int i=0; i<nsize; i++){
            int pos=0;
            int min=INT_MIN;
            for(int m=0; m<nsize; m++){
                if(visit[m]==0 && dist[m]<min){
                    min=dist[m];
                    pos=m;
                }
            }
            visit[pos]=1;
        }
    }

    */

   void dikstra(H s, H e, ofstream &out){
    int source=find_node_index(s);
    int dest=find_node_index(e);

    int* dist=new int[nsize];

    for(int i=0; i<nsize; i++) dist[i]=INT_MAX;

    dist[source]=0;

    bool* visit=new bool[nsize]{0};

    for(int i=0; i<nsize; i++){
        int min=INT_MAX;
        int pos=0;
        for(int m=0; m<nsize; m++){
            if(visit[m]==0 && dist[m] < min){
                min=dist[m];
                pos=m;
            }
        }
        visit[pos]=1;
            for(int j=0; j<esize; j++){
                int s=edges[j]->getS();
                int e=edges[j]->getE();
                int w=edges[j]->getW();
            
                if(s==pos && dist[s]+w < dist[e])
                dist[e]=dist[s]+w;
            }
    }
    if(dist[dest]==INT_MAX) out << "inf." << endl;
    else out << dist[dest] << endl;
   }
};
