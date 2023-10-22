#include <stdlib.h>
#include <cmath>
#include <vector>
#include <iostream>
#include <cassert>
#include <climits>

using namespace std;

class MinMaxHeap
{
private:
    //Container to store heap structure
    vector<int> heap;
    void trickleDown(unsigned int idx);
    void trickleDown_min(unsigned int idx);
    void trickleDown_max(unsigned int idx);

    void trickleUp(unsigned int idx);
    void trickleUp_min(unsigned int idx);
    void trickleUp_max(unsigned int idx);

    //Implicit array navigation
    int parent(unsigned int idx);
    int lChild(unsigned int idx);
    int rChild(unsigned int idx);
    //Helper Functions
    int getAt(unsigned int idx);
    int getSize();
    int getLevel(unsigned int idx);
    void setAt(int x, unsigned int idx);
    void swap(unsigned int idx1, unsigned int idx2);

public:
    
    MinMaxHeap(vector<int> in);
    void printHeap();
    int findMax();
    int findMin();
    void deleteMax();
    void deleteMin();
    void insertHeap(int x);
    ~MinMaxHeap();
};

int MinMaxHeap::getAt(unsigned int idx)
{
    return heap[idx];
}

int MinMaxHeap::getSize()
{
    return heap.size();
}

int MinMaxHeap::getLevel(unsigned int idx)
{
    return floor(log2(idx));
}

void MinMaxHeap::setAt(int x, unsigned int idx)
{
    heap[idx]=x;
    return;
}

void MinMaxHeap::swap(unsigned int idx1, unsigned int idx2)
{
    cout<<"swapping "<<idx1<<" and "<< idx2;
    int t = getAt(idx1);
    heap[idx1] = heap[idx2];
    heap[idx2] = t;

}
MinMaxHeap::MinMaxHeap(vector<int> in) {
    // Initialize the heap with a sentinel element at the beginning.
    heap.push_back(INT_MIN);

    // Copy the input elements to the heap.
    heap.insert(heap.end(), in.begin(), in.end());

    // Start trickleDown from the last parent node.
    for (int idx = getSize() / 2; idx >= 1; idx--) {
        trickleDown(idx);
    }
}


void MinMaxHeap::printHeap() {
    cout << "[ ";
    for (int i = 1; i < getSize(); i++) {
        if (i == 1) cout << getAt(i) << " ";
        else cout << ", " << getAt(i);
    }
    cout << " ]\n";
    swap(0,getSize());
}


MinMaxHeap::~MinMaxHeap()
{}

void MinMaxHeap::trickleDown(unsigned int idx) {
    if (idx == 1) {
        // The root node is always treated as a min node.
        trickleDown_min(idx);
    }
    else if (getLevel(parent(idx)) % 2 == 0) {
        // The parent is a min node, so the current node should be a max node.
        trickleDown_max(idx);
    } 
    else {
        // The parent is a max node, so the current node should be a min node.
        trickleDown_min(idx);
    }
}

void MinMaxHeap::trickleDown_min(unsigned int idx)
{
        unsigned int leftChild, rightChild, smallest = idx;

        leftChild = lChild(idx);
        rightChild = rChild(idx);

        // Check to see if the index is within bounds and if it is less than the current smallest child.
        if (leftChild < getSize() && getAt(leftChild) < getAt(smallest)) {
            smallest = leftChild;
        }
        if (rightChild < getSize() && getAt(rightChild) < getAt(smallest)) {
            smallest = rightChild;
        }

        if (idx != smallest) {
            swap(smallest, idx);
            if (parent(smallest) < getSize() && getAt(smallest) > getAt(parent(smallest))) {
                swap(smallest, parent(smallest));
            }
            trickleDown_min(smallest);  // Continue trickling down with the smallest child.
        }
}

void MinMaxHeap::trickleDown_max(unsigned int idx)
{
    unsigned int leftChild, rightChild, largest = idx;

        leftChild = lChild(idx);
        rightChild = rChild(idx);

        // Check to see if the index is within bounds and if it is less than the current smallest child.
        if (leftChild < getSize() && getAt(leftChild) > getAt(largest)) {
            largest = leftChild;
        }
        if (rightChild < getSize() && getAt(rightChild) > getAt(largest)) {
            largest = rightChild;
        }

        if (idx != largest) {
            swap(largest, idx);
            if (parent(largest) < getSize() && getAt(largest) < getAt(parent(largest))) {
                swap(largest, parent(largest));
            }
            trickleDown_max(largest);  // Continue trickling down with the largest child.
        }
}

void MinMaxHeap::trickleUp(unsigned int idx){
    if((getLevel(idx) % 2 )== 0)
    {
        if((parent(idx) < getSize() && parent(idx) >= 0) && getAt(idx) > getAt(parent(idx)))
        {
            swap(idx,parent(idx));
            trickleUp_max(parent(idx));
        }
        else trickleUp_min(idx);
    }

    else
    {
        if((parent(idx) < getSize() && parent(idx) >= 0) && getAt(idx) < getAt(parent(idx)))
        {
            swap(idx,parent(idx));
            trickleUp_min(parent(idx));
        }
        else trickleUp_max(idx);
    }
}

void MinMaxHeap::trickleUp_min(unsigned int idx)
{
    if((parent(parent(idx)) < getSize() && parent(parent(idx)) >= 0) && getAt(idx) < getAt(parent(parent(idx))))
    {
     swap(parent(parent(idx)), idx);
     trickleUp_min(parent(parent(idx)));
    }
}

void MinMaxHeap::trickleUp_max(unsigned int idx)
{
    if((parent(parent(idx)) < getSize() && parent(parent(idx)) >= 0) && getAt(idx) > getAt(parent(parent(idx))))
    {
     swap(parent(parent(idx)), idx);
     trickleUp_max(parent(parent(idx)));
    }
}

int MinMaxHeap::parent(unsigned int idx) {
    assert(idx != 0);
    return idx / 2;
}

int MinMaxHeap::lChild(unsigned int idx) {
    assert(idx != 0);
    return 2 * idx;
}

int MinMaxHeap::rChild(unsigned int idx) {
    assert(idx != 0);
    return 2 * idx + 1;
}

int MinMaxHeap::findMax() {
    if (getSize() == 0) throw underflow_error("No Elements in heap");
    if (getSize() == 1) return getAt(0);
    if (getSize() == 2) return getAt(1);
    return (getAt(1) > getAt(2)) ? getAt(1) : getAt(2);
}

int MinMaxHeap::findMin() {
    if (getSize() == 0) throw underflow_error("No Elements in heap");
    return getAt(0);
}


void MinMaxHeap::deleteMax(){}
void MinMaxHeap::deleteMin(){
    if(getSize() == 0){
        heap.pop_back();
        return;
    }
    setAt(getAt(getSize()-1),0);
    heap.pop_back();
    trickleDown(0);
}

void MinMaxHeap::insertHeap(int x){}



int main(){
    vector<int> d = {81,87,6,17,12,14,28,31,42,20,52,78,80,71,25,16,24,59,31,63,79,15,48,32,13,19,18};
    MinMaxHeap mmh(d);
    mmh.printHeap();

}