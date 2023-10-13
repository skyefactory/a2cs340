#pragma once

class MinMaxHeap {
    int* heapContainer;
    unsigned int size;

    unsigned int parent(unsigned int index);
    unsigned int leftChild(unsigned int index);
    unsigned int rightChild(unsigned int index);
    bool minLevel(unsigned int index);
    bool maxLevel(unsigned int index);
    void swap(unsigned int i, unsigned int j);

    void trickleDown(int index);
    void trickleDown_min(int index);
    void trickleDown_max(int index); // opposite of min vers.

    void trickleUp(int index);
    void trickleUp_min(int index);
    void trickleUp_max(int index); // opposite of min vers.



    public:
        MinMaxHeap() { }
        MinMaxHeap(int* hc, unsigned int s) 
            : heapContainer(hc), size(s) { trickleDown(0); } 

        bool empty() { return (size == 0); }
        unsigned int getSize() { return size; }

        //Functionality procedures
        void insert(const int value);
        int deleteMin();
        int deleteMax();
        int findMin();
        int findMax();
        void print();

};