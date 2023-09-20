#include <iostream>
#include <fstream>
#include <string>
using namespace std;
ifstream in;
ofstream out;

class Activity{
    public:
        int s;
        int f;
        Activity(int start, int stop){
            s=start;
            f=stop;
        }
};

void bubbleSort(Activity **vett,int dim){
    bool flag = true;
    while(dim>0){
        for(int i=0;i<dim-1;i++){
            if(vett[i]->f > vett[i+1]->f){
            swap(vett[i],vett[i+1]);
            }
        }    
        dim--;
    } 
}

void swap(Activity *a, Activity* b){
    Activity *temp = a;
    a = b;
    b = temp;
}

int activitySelection(Activity **vett,int dim){
    bubbleSort(vett,dim);
    int count=0;
    int act=0;
    for(int i=1;i<dim;i++){
        if(vett[act]->f <= vett[i]->s){
            count++;
            act = i;
        }
    }
    return count+1;
}

int main(){
    in.open("input.txt");
    out.open("output.txt");
    for(int task=0;task<100;task++){
        int numAttivita;
        in>>numAttivita;
        Activity **activity;
        activity = new Activity*[numAttivita];
        for(int i=0;i<numAttivita;i++){
            string start;
            string stop;
            in>>start;
            in>>stop;
            string s = start.substr(1,start.length()-1);
            string f = stop.substr(0,stop.length()-1);
            activity[i] = new Activity(atoi(s.c_str()),atoi(f.c_str()));
        }
        out<<activitySelection(activity,numAttivita)<<endl;

    }
}