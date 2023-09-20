#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;

ifstream in;
ofstream out;

template <class T> class Nodo{
    public:
        Nodo <T> *p;
        Nodo <T> *left;
        Nodo <T> * right;
        T key;
        Nodo(T val){
            key = val;
            p = NULL;
            left = NULL;
            right = NULL;
        }
};

template <class T> class BST{
    public:
        Nodo <T> * root;
        BST(){
            root = NULL;
        }

        void insert(T val){
            Nodo <T> * newNode = new Nodo <T> (val);
            if(!root){
                root = newNode;
            }
            else{
                Nodo <T> * cond = root;
                Nodo <T> * temp;
                while(cond){
                    temp = cond;
                    if(val <= cond->key){
                        cond = cond->left;
                    }

                    else{
                        cond = cond->right;
                    }
                }
                

                if(val <= temp->key){
                    temp->left = newNode;
                }

                else{
                    temp->right=newNode;
                }

                newNode->p = temp;
            }   
        }


        Nodo <T> * search(T val){
            Nodo <T> * temp = root;
            while(temp){
                if(val == temp->key){
                    return temp;
                }

                else if(val < temp->key){
                    temp = temp->left;
                }

                else if(val > temp->key){
                    temp = temp->right;
                }
            }
            return NULL;
        }

        Nodo <T> * getMin(Nodo <T> * temp){
            Nodo <T> * cond = temp;
            Nodo <T> * min;
            while(cond){
                min = cond;
                cond = cond->left;
            }
            return min;
        }

        Nodo <T> * findSuccessor(Nodo <T> * temp){
            return getMin(temp->right);
            
        }

        void swap(Nodo <T> *x, Nodo <T> *y){
            T val = x->key;
            x->key = y ->key;
            y ->key = val;
        }
        void canc(Nodo <T> *cancNode){
            Nodo <T> * y;
            if(cancNode->left == NULL){
                Trapianta(cancNode,cancNode->right);
            }
            else if(cancNode->right == NULL){
                Trapianta(cancNode,cancNode->left);
            }

            else{
                y = getMin(cancNode->right);
                if(y -> p != cancNode){
                    Trapianta(y,y->right);
                    y->right = cancNode->right;
                    y->right->p = y;
                }
                Trapianta(cancNode,y);
                y->left = cancNode->left;
                y->left->p = y;
            }

        }

        void Trapianta(Nodo <T> * u, Nodo <T> * v){
            if(u->p == NULL){
                root = v;
            }

            else if(u == u->p->left){
                u->p->left = v;
            }

            else{
                u->p->right = v;
            }

            if(v!=NULL){
                v->p = u->p;
            }
        }

        void inorder(Nodo <T> * temp){
            if(temp){
                inorder(temp->left);
                out<<temp->key<<" ";
                inorder(temp->right);
            }
            
        }

        void preorder(Nodo <T> * temp){
            if(temp){
                out<<temp->key<<" ";
                preorder(temp->left);
                preorder(temp->right);
            }
        }

        void postorder(Nodo <T> * temp){
            if(temp){
                postorder(temp->left);
                postorder(temp->right);
                out<<temp->key<<" ";
            }
        }

        void printBST(string x){
            if(x == "preorder"){
                preorder(root);
            }

            else if(x=="inorder"){
                inorder(root);
            }

            else if (x=="postorder")
            {
                postorder(root);
            }
            
            out<<endl;
        }

        void rotation(int intX , string dir){
            
            Nodo <T> * x = search(intX);
            
            if(x == NULL){return;}
            Nodo <T> *y;
            
            if(x == root){
                if(dir == "left"){
                    y = x->right;
                    if(!y){return;}
                    x -> right = y -> left;
                    if(x->right){x -> right -> p = x;}
                    
                    y->p = NULL;
                    root = y;
                    x->p = y;
                    y -> left = x;
                }

                else if(dir == "right"){
                    y = x->left;
                    if(!y){return;}
                    x -> left = y -> right;
                    if(x->left){x -> left -> p = x;}
                    
                    y->p = NULL;
                    root = y;
                    x->p = y;
                    y -> right = x;
                }
            }

            else if(x!= root && dir == "left"){
                y = x->right;
                if(!y){return;}
                x -> right = y -> left;
                if(x->right){x -> right -> p = x;}
                y->p = x->p;
                if(x == x->p->right){x->p->right = y;}
                else { x->p->left = y;}
                x->p = y;
                y -> left = x;
            }
            
            else if(x!= root && dir == "right"){
                y = x->left;
                if(!y){return;}
                x -> left = y -> right;
                if(x->left){x -> left -> p = x;}
                y->p = x->p;
                if(x == x->p->right){x->p->right = y;}
                else { x->p->left = y;}
                x->p = y;
                y -> right = x;
            }  
        }

           
};




int main(){

    in.open("input.txt");
    out.open("output.txt");

    for(int task=0;task<100;task++){
        string type;
        in>>type;
        int dim;
        in>>dim;
        int numOp;
        in>>numOp;
        string typeSearch;
        in>>typeSearch;
        
        if(type=="int"){
            BST <int> bst;
            
         
            

            for(int i=0;i<dim;i++){
                string op;
                in>>op;
                if(op[0]=='i'){
                    string valop = op.substr(4,op.length()-4);
                    int val = atoi(valop.c_str());
                    bst.insert(val);
                }
                if(op[0]=='c'){
                    string valop = op.substr(5,op.length()-5);
                    int val = atoi(valop.c_str());
                    bst.canc(bst.search(val));
                }
            }
            for(int i=0;i<numOp;i++){
                string op;
                in>>op;
                if(op[0]=='l'){
                    string valop = op.substr(5,valop.length()-5);
                    int val = atoi(valop.c_str());
                    bst.rotation(val,"left");
                }
                else if(op[0]=='r'){
                    string valop = op.substr(6,valop.length()-6);
                    int val = atoi(valop.c_str());
                    bst.rotation(val,"right");
                }
            } 

            bst.printBST(typeSearch);   
        }

        else if (type == "double"){
            BST <double> bst;

            for(int i=0;i<dim;i++){
                string op;
                in>>op;
                if(op[0]=='i'){
                    string valop = op.substr(4,op.length()-4);
                    double val = atof(valop.c_str());
                    bst.insert(val);
                }
                if(op[0]=='c'){
                    string valop = op.substr(5,op.length()-5);
                    double val = atof(valop.c_str());
                    bst.canc(bst.search(val));
                }
            }

            for(int i=0;i<numOp;i++){
                string op;
                in>>op;
                if(op[0]=='l'){
                    string valop = op.substr(5,valop.length()-5);
                    double val = atof(valop.c_str());
                    bst.rotation(val,"left");
                }
                else if(op[0]=='r'){
                    string valop = op.substr(6,valop.length()-6);
                    double val = atof(valop.c_str());
                    bst.rotation(val,"right");
                }
            } 

            bst.printBST(typeSearch);   
        }
        
    }
    
    
    

}