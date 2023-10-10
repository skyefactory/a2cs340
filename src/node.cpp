#include "node.h"

Node::Node()
{
    c1 = nullptr;
    c2 = nullptr;
    datum = 0;
}

Node::Node(int data)
{
    c1 = nullptr;
    c2 = nullptr;
    datum = data;
}

Node::Node(Node *one, Node *two, int data)
{   
    c1 = one;
    c2 = two;
    datum = data;
}

Node::~Node()
{
    delete c1;
    delete c2;
}

Node* buildHeap(int *in, const int &size)
{  
    int i, l = 0 , h = size;
    Node* res = new Node(in[0]);
    Node* head = res;
    for(i = 0 ; i < size ; i ++){
        if(i == 0){
            res->c1 = new Node(in[h]);
            h--;
            res->c2 = new Node(in[h]);
            h--;
            continue;
        }
        if(i % 2 == 0){
            
        }

    }
    return head;

}
