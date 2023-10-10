class Node {
    public:
        Node* c1;
        Node* c2;
        int datum;
        Node();
        Node(int data);
        Node(Node* one, Node* two, int data);
        ~Node();
};

Node* buildHeap(int *in, const int &size);
