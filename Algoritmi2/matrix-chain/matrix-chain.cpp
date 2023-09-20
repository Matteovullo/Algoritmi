#include <iostream>
#include <fstream>
#include <string>
using namespace std;
ifstream in;
ofstream out;


class matrix{
    public:
        int x;
        int y;
        matrix(){}
};

void matrixChainOrder(matrix* m, int sizeM, int *P, int sizeP){
    int matrix[sizeM][sizeM];
    for(int i=0;i<sizeM;i++){
        matrix[i][i] = 0;
    }


    for(int offset = 1;offset <sizeM;offset++){
        for(int i=0;i<sizeM-offset;i++){
            int j = offset + i;
            matrix[i][j] = 10000;
            for(int k=i;k<j;k++){
                //cout<<"x: "<<matrix[i][k]<<" "; 
                //cout<<"y: "<<matrix[k+1][j]<<" ";
                //cout<<"pi-1: "<<P[i]<<" ";
                //cout<<"pk: "<<P[k+1]<<" ";
                //cout<<"pj: "<<P[j+1]<<" ";
                int f = matrix[i][k] + matrix[k+1][j] + (P[i]*P[k+1]*P[j+1]);
                //cout<<"f: "<<f<<endl;
                if(f < matrix[i][j]){
                    matrix[i][j] = f;
                }
            }
        }
    }
/*
    for(int i=0;i<sizeM-1;i++){
        int k = i;
        for(int j=i+1;j<sizeM;j++){
            int min = 100000;
            while(k>=i && k<j){
                cout<<"x: "<<matrix[i][k]<<" "; 
                cout<<"y: "<<matrix[k+1][j]<<" ";
                cout<<"pi-1: "<<P[i]<<" ";
                cout<<"pk: "<<P[k+1]<<" ";
                cout<<"pj: "<<P[j+1]<<" ";
                int f = matrix[i][k] + matrix[k+1][j] + (P[i]*P[k+1]*P[j+1]);
                cout<<"f: "<<f<<endl;
                if(f < min){
                    min = f;
                }
                k++;
            }
            matrix[i][j] = min;
        }
    }
*/
    
    /*
    for(int i=0;i<sizeM-1;i++){
        for(int j=i+1;j<sizeM;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    */
   out<<matrix[0][sizeM-1]<<endl;
    

}





int main(){
    in.open("input.txt");
    out.open("output.txt");
    for(int task=0;task<100;task++){
        int size;
        in>>size;
        int P[size+1];
        matrix m[size];
        int lastn;
        for(int i=0;i<size;i++){
            string s1;
            in>>s1;
            int posCom = s1.find('x');
            string xS = s1.substr(1,posCom-1);
            string yS = s1.substr(posCom+1,s1.length()-(posCom+2));
            int x = atoi(xS.c_str());
            int y = atoi(yS.c_str());
            P[i] = x;
            lastn = y;
            m[i].x = x;
            m[i].y = y; 
        }
        P[size] = lastn; 
        
        matrixChainOrder(m,size,P,size+1);
    }

}