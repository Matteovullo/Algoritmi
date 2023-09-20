#include <iostream>
#include <fstream>
#include <limits.h>
#include <list> 

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

    int getEdge(){return totaledge;}

    int dijkstra(H s, H f, ofstream &out)
    {
        int source = find_node_index(s);
        int dest = find_node_index(f);

        int *dist = new int[nsize];

        for (int i = 0; i < nsize; i++)
            dist[i] = INT_MAX;

        dist[source] = 0;

        bool *visit = new bool[nsize]{0};

        for (int i = 0; i < nsize; i++)
        {
            int min = INT_MAX;
            int posmin = 0;

            for (int m = 0; m < nsize; m++)
            {
                if (visit[m] == 0 && dist[m] < min)
                {
                    min = dist[m];
                    posmin = m;
                }
            }
            visit[posmin] = 1;

            for (int j = 0; j < esize; j++)
            {
                int s = edges[j]->getS();
                int e = edges[j]->getE();
                int w = edges[j]->getW();

                if (s == posmin && dist[s] + w < dist[e])
                    dist[e] = dist[s] + w;
            }
        }

        if (dist[dest] == INT_MAX){
            out << "inf" << endl;
            return -1;
        }
        else
            return dist[dest];
    }
};

template <class T> class HashTable
{  		 
  public:	     	
	     virtual HashTable<T>* insertKey(T x)=0;
	     virtual HashTable<T>* deleteKey(T key)=0;		
		 virtual int searchKey(T key) = 0;	
};

template <class T> 
class ChainedHashTable : public HashTable<T>
{
private:
	int slots;    // Number of slots 	
	list<T>* table;
	int size;

protected:
	list<T>* getTable()
	{
		return this->table;
	}
  public:
	virtual int computeHashFunction(T x) = 0;
	int getSlotNumber()
	{
		return slots;
	}

	int getSize()
	{
		return size;
	}

	void printHashTable()
	{
		for (int i = 0; i < this->getSlotNumber(); i++)
		{
			cout << i;
			for (auto x : table[i])
				cout << " --> [" << x << "]";
			cout << endl;
		}
	}

	ChainedHashTable<T>(int x)
	{
		this->slots = x;
		table = new list<T>[slots];
		size = 0;		
	}

	
	
	int searchKey(T key)
	{
		int index = computeHashFunction(key);
		list<T>::iterator i;
		for (i = table[index].begin(); i != table[index].end(); i++)
		{
			if (*i == key)
				return index;
		}
		return -1;	
	}

	void searchKey(T key, int* pos1, int* pos2)
	{
		*pos1 = computeHashFunction(key);
		list<T>::iterator i;
		for (i = table[*pos1].begin(); i != table[*pos1].end(); i++)
		{
			if (*i == key)
			{				
				*pos2 = (int) distance(table[*pos1].begin(), i);
				return;
			}
		}		 
		*pos2 = -1;
		return;
	}

	ChainedHashTable<T>* insertKey(T key)
	{
		int index, pos2;		
		searchKey(key, &index, &pos2);		
		if (pos2 == -1)
		{			
			table[index].push_front(key);
			size++;
		}
		return this;
	}

	ChainedHashTable<T>* deleteKey(T key)
	{		
		int pos1 = -1;
		int pos2 = -1;
		searchKey(key, &pos1, &pos2);
		if (pos2 != -1)
		{
			list<T>::iterator i = table[pos1].begin();
			advance(i, pos2);
			table[pos1].erase(i);
			size--;
		}
		return this;
	}

};

template <class H>
void solve(ifstream &in, ofstream &out, int n, int e)
{
    Graph<H> graph = Graph<H>(n, e);

    for (int j = 0; j < n; j++)
    {
        H val;
        in >> val;
        graph.addNode(val);
    }

    for (int j = 0; j < e; j++)
    {
        char tmp;
        H x, y;
        int p;
        in >> tmp >> x >> y >> p >> tmp;
        graph.addEdge(x, y, p);
    }

    H start, dest;
    in >> start >> dest;

    ChainedHashTable<H> t(graph.getEdge());
    t.insertKey(graph.dijkstra(start, dest, out););

    int pos;
    pos = t.searchKey(graph.dijkstra(start, dest, out));
    cout << pos << endl;
}

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");

    for (int i = 0; i < 100; i++)
    {
        int n, e;
        in >> n >> e;
        string type;
        in >> type;

        if (type == "int")
            solve<int>(in, out, n, e);

        else if (type == "double")
            solve<double>(in, out, n, e);
    }
}