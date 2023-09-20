#include <iostream>
#include <fstream>
#include <string>
using namespace std;
ifstream in;
ofstream out;

class activity{
    public:
        int s;
        int f;
        activity(){}
};


void swap(activity*vett, int i, int j){
    activity temp;
    temp.s = vett[i].s;
    temp.f = vett[i].f;

    vett[i].s = vett[j].s;
    vett[i].f = vett[j].f;

    vett[j].s = temp.s;
    vett[j].f = temp.f;    
}

void orderVect(activity *vett,int dim){
    for(int i=0;i<dim;i++){
        int min = i;
        for(int j=i;j<dim;j++){
            if(vett[min].f > vett[j].f){
                min = j;
            }
        }
        swap(vett, i, min);
    }
}

int maxtime(activity *vett,int dim){
    int max=0;
    for(int i=0;i<dim;i++){
        if(vett[i].f > max){
            max = vett[i].f;
        }
    }
    return max;
}

int max(int a, int b){
    if(a>=b){
        return a;
    }

    else return b;
}

int selectionActivity(activity *activity,int d){
    int time = maxtime(activity,d)+1;
    orderVect(activity,d);
    
    //cout<<time<<endl;
    int dim = d+1;
    int matrix[dim][time];
    for(int i=0;i<dim;i++){matrix[i][0] = 0;}
    for(int i=0;i<time;i++){matrix[0][i] = 0;}

    for(int i=1;i<dim;i++){
        for(int j=1;j<time;j++){

            //cout<<"confrontiamo: "<<activity[i-1].f<<" - "<<j<<" - risultato: ";
            if(activity[i-1].f > j){
                matrix[i][j] = matrix[i-1][j];
                //cout<<matrix[i-1][j]<<endl;
            }

            else{
                int num1 = matrix[i-1][j];
                int num2 = matrix[i-1][activity[i-1].s] + (activity[i-1].f - activity[i-1].s);
                //cout<<"num1: "<<num1<<" num2: "<<num2;
                matrix[i][j] = max(num1,num2);
                //cout<<matrix[i][j]<<endl;
            }
        }
    }

    
    
    return matrix[dim-1][time-1];
}

int main(){
    in.open("input.txt");
    out.open("output.txt");
    for(int task=0;task<100;task++){
        int numAtt;
        in>>numAtt;
        activity attivita[numAtt];
        for(int i=0;i<numAtt;i++){
            string act1;
            in>>act1;
            string act2;
            in>>act2;
            string s = act1.substr(1,act1.length()-1);
            string f = act2.substr(0,act2.length()-1);
            attivita[i].s = atoi(s.c_str());
            attivita[i].f = atoi(f.c_str());
        }
        out<<selectionActivity(attivita,numAtt)<<endl;
    }

}