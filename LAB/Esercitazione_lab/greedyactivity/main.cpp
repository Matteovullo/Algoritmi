#include<iostream>
#include<fstream>

using namespace std;

class Activity{
    private:
        int s;
        int e;

    public:
        Activity(int _s, int _e){
            s=_s;
            e=_e;
        }

        int getE(){return e;}
        int getS(){return s;}

        static void sort(Activity** attivita, int v){
            for(int i=1; i<v; i++){
                int index=i;
                while(index>0 && attivita[index]->getE() < attivita[index-1]->getE()){
                    swap(attivita[index], attivita[index-1]);
                    index--;
                }
            }
        }

        static int select(Activity** v, int n){
            int max=1;
            int last=0;
            for(int i=1; i<n; i++){
                if(v[i]->getS() >= v[last]->getE()){
                    max++;
                    last=i;
                }
            }
            return max;
        }

        /*
        static void print(Activity** v, int n){
            cout << "TOTAL:" << n << "->";
            for(int i=0; i<n; i++){
                cout << "(s:" << v[i]->getS() << "e:" << v[i]->getE() << ")";
                cout << endl;
            }
        }
        */
};

void solve(ifstream &in, ofstream &out, int n){
    Activity** v=new Activity*[n];

    for(int i=0; i<n; i++){
        char type;
        int s, e;
        in>>type>>s>>e>>type;
        v[i]=new Activity(s, e);
    }

    Activity::sort(v, n);
    out << Activity::select(v, n) <<endl;
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    for(int i=0; i<100; i++){
        int n;
        in>>n;
        solve(in, out, n);
    }
}