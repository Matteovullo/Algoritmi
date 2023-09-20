#include <iostream>
#include <fstream>
#include <string>
using namespace std;
ifstream in;
ofstream out;

template <class T> class Node{
    public:
        T key;
        Node <T> * parent;
        Node <T> * sx;
        Node <T> * dx;
        char color;
        Node(T val){
            key = val;
            parent = NULL;
            sx = NULL;
            dx = NULL;
            color = 'R';
        }
};

template <class T> class RBtree{
    public:
        Node <T> * root;
        RBtree(){
            root = NULL;
        }


        void rotate(Node <T> * x){
            Node <T> * y = x->parent;
            if(x == y->sx){
                rotateDx(x,y);
            }

            else{
                rotateSx(x,y);
            }
        }
        void rotateDx(Node <T>*x,Node <T> * y){
            x -> parent = y -> parent;
            Node <T> * parentY = y->parent;
            y -> parent = x;
            y->sx = x->dx;
            y->sx->parent = y;
            x -> dx = y;

            if(y==parentY->sx){
                parentY->sx = x;
            }

            else{
                parentY->dx = x;
            }

            char s = x->color;
            x ->color = y->color;
            y ->color = s;
        }

        void rotateSx(Node <T>*x,Node <T> * y){
            x -> parent = y -> parent;
            Node <T> * parentY = y->parent;
            y -> parent = x;
            y->dx = x->sx;
            y->dx->parent = y;
            x -> sx = y;

            if(y==parentY->sx){
                parentY->sx = x;
            }

            else{
                parentY->dx = x;
            }

            char s = x->color;
            x ->color = y->color;
            y ->color = s;
        }


        string checkPositionNode(Node <T>*x, Node <T>*parent, Node <T> * granParent){
            if(parent == granParent->sx && x == parent->sx){
                return "esterno";
            }

            else if(parent == granParent->dx && x == parent->dx){
                return "esterno";
            }

            return "interno";
        }
        void fix(Node <T> * x){
            if (x == root) return;
            Node <T> * parent = x->parent;
            Node <T> * granParent = parent->parent;
            if(!granParent) return;
            //1 caso: zio nero, x = figlio esterno
            if((granParent->dx->color == 'B'||granParent->sx->color == 'B') && (checkPositionNode(x,parent,granParent) == "esterno")){
                rotate(parent);
            }
            //2 caso: zio nero, x = figlio interno
            if((granParent->dx->color == 'B'||granParent->sx->color == 'B') && (checkPositionNode(x,parent,granParent) == "interno")){
                rotate(x);
                rotate(x);
            }
            //3 caso: zio rosso, push livello di rosso e ricorsione

            if(granParent->dx->color == 'R'||granParent->sx->color == 'R'){
                granParent->sx->color = 'B';
                granParent->dx->color = 'B';
                granParent->color = 'R';
                fix(granParent);
            }

        }
        void insert(T val){
            Node <T> * newNode = new Node <T> (val);

            if(!root){
                root = newNode;
                newNode->color = 'B';
            }

            else{
                Node <T> * temp = root;
                Node <T> * x;
                while(temp){
                    x = temp;
                    if(val < temp->key){
                        temp = temp->sx;
                    }
                    else if(val >= temp->key){
                        temp = temp->dx;
                    }
                }

                if(val < x->key){
                    x->sx = newNode;
                }

                else{
                    x->dx = newNode;
                }
                newNode -> parent = x;
                if(newNode->color=='R' && x->color == 'R'){
                    fix(newNode);
                }
            }
            
            printPreorder();
            cout<<endl;
        }

        void preorder(Node <T> *x){
            if(x){
                cout<<"("<<x->key<<" "<<x->color<<") ";
                preorder(x->sx);
                preorder(x->dx);
            }
        }

        void inorder(Node <T> *x){
            if(x){
                inorder(x->sx);
                cout<<"("<<x->key<<" "<<x->color<<") ";
                inorder(x->dx);
            }
        }

        void postorder(Node <T> *x){
            if(x){
                postorder(x->sx);
                postorder(x->dx);
                out<<"("<<x->key<<" "<<x->color<<") ";
            }
        }

        void printPreorder(){
            preorder(root);
        }

        void printInorder(){
            inorder(root);
        }

        void printPostorder(){
            postorder(root);
        }

};
int main(){
    in.open("input.txt");
    out.open("output.txt");
    for(int task=0;task<100;task++){
        string type;
        in>>type;
        int size;
        in>>size;
        string typeVisit;
        in>>typeVisit;

        if(type == "int"){
            RBtree <int> tree;
            for(int i=0;i<size;i++){
                int val;
                in>>val;
                tree.insert(val);
            }
            if(typeVisit == "preorder"){
                tree.printPreorder();
            }
            
            else if(typeVisit == "inorder"){
                tree.printInorder();
            }

            else if(typeVisit == "postorder"){
                tree.printPostorder();
            }
            
        }

        if(type == "double"){
            RBtree <double> tree;
            for(int i=0;i<size;i++){
                double val;
                in>>val;
                tree.insert(val);
            }
            if(typeVisit == "preorder"){
                tree.printPreorder();
            }
            
            else if(typeVisit == "inorder"){
                tree.printInorder();
            }

            else if(typeVisit == "postorder"){
                tree.printPostorder();
            }
            
        }
    }
}