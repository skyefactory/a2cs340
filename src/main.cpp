/*
    DYLAN OSTAPA - ID # 200463707
    UNIVERSITY OF REGINA FALL 2023
*/
#include <iostream>
 
#include <cmath>
using namespace std;
#define MAX 1000

class MinMaxHeap {
    private:
        int size = 1;
        int *heap = new int(MAX);

        //Helper Functions
        int parent(int i);
        int leftChild(int i);
        int rightChild(int i);
        void swap(int i, int j);
        bool isEven(int x);

        void bubbleUp(unsigned int idx);
        void bubbleUpMin(unsigned int idx);
        void bubbleUpMax(unsigned int idx);

        void bubbleDown(unsigned int idx);
        void bubbleDownMin(unsigned int idx);
        void bubbleDownMax(unsigned int idx);

    public:
        MinMaxHeap(int *arr, int n);


        int at(unsigned int i) {return heap[i];}

        //Functional Requirements
        void buildHeap(unsigned int inSize, int *arr);
        void printHeap();
        void insert(int x);
        void deleteMin();
        void deleteMax();
        int findMin();
        int findMax();
};

void MinMaxHeap::buildHeap(unsigned int inSize, int *arr)
{
    for(int i = 0; i < inSize; i++) {
        insert(arr[i]);
        printHeap();
    }
}

void MinMaxHeap::printHeap()
{
    for (int i = 0; i < size; i++) {
        cout << heap[i] << " , ";
    }
    cout << endl;
}

void MinMaxHeap::insert(int x)
{
    // Push the value onto the end of the heap
        heap[size] = x;
    // Reorder the heap so that the min-max heap property holds true
        size++;
        bubbleUp(size-1);


}

void MinMaxHeap::deleteMin()
{
    swap(0, size-1);
    size--;
    bubbleDown(0);
}

void MinMaxHeap::deleteMax()
{
    unsigned int maxIdx = findMax();
    swap(maxIdx, size-1);
    size--;
    bubbleDown(maxIdx);
}

int MinMaxHeap::findMin()
{
    return 0;
}

int MinMaxHeap::findMax()
{
    if (size == 1)
        return 0;
    else if (size == 2)
        return 1;
    else
        return (heap[1] > heap[2]) ? 1 : 2;
}

int MinMaxHeap::parent(int i)
{
        return ((i-1)/2);
}

int MinMaxHeap::leftChild(int i)
{
        return ((2*i) + 1);
}

int MinMaxHeap::rightChild(int i)
{
        return ((2*i) + 2);
}

void MinMaxHeap::swap(int i, int j)
{
        int temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
}

bool MinMaxHeap::isEven(int x)
{
        return (int((log2(x+1) )) % 2 == 0);
}

void MinMaxHeap::bubbleUp(unsigned int idx)
{
    //no parent
    if(idx == 0) return;
    //min level
    if(isEven(idx)){
        //if child is greater than parent
        if(heap[idx] > heap[parent(idx)]){
            swap(idx, parent(idx));
            bubbleUpMax(parent(idx));
        } else {
            bubbleUpMin(idx);
        }
    } else {
        if(heap[idx] < heap[parent(idx)]){
            swap(idx, parent(idx));
            bubbleUpMin(parent(idx));
        } else {
            bubbleUpMax(idx);
        }
    }
}

void MinMaxHeap::bubbleDown(unsigned int idx)
{
    if (isEven(idx)) {
        bubbleDownMin(idx);
    } else {
        bubbleDownMax(idx);
    }
}

void MinMaxHeap::bubbleUpMin(unsigned int idx)
{
    if(parent(idx) == 0) return;
    if(heap[idx] < heap[parent(parent(idx))]){
        swap(idx, parent(parent(idx)));
        bubbleUpMin(parent(parent(idx)));
    }
}

void MinMaxHeap::bubbleUpMax(unsigned int idx)
{
    if(parent(idx) == 0) return;
    if(heap[idx] > heap[parent(parent(idx))]){
        swap(idx, parent(parent(idx)));
        bubbleUpMax(parent(parent(idx)));
    }
}

void MinMaxHeap::bubbleDownMax(unsigned int idx)
{
    if(idx >= size) throw invalid_argument("Index out of bounds");

    unsigned int maximum = idx;
    unsigned int left = leftChild(idx);

    if(left < size && heap[left] > heap[maximum]) maximum = left;
    if(left+1 < size && heap[left+1] > heap[maximum]) maximum = left;

    unsigned int leftGrandChild = leftChild(left);

    for (unsigned int i = 0; i < 4 && leftGrandChild + i < size; ++i)
        if (heap[leftGrandChild + i] > heap[maximum]) maximum = leftGrandChild + i;

    if(idx == maximum) return;

    swap(idx, maximum);
    //test to change comp
    if(maximum - left > 1){
        if(heap[maximum] < heap[parent(maximum)]) swap(maximum, parent(maximum));
        bubbleDownMin(maximum);
    }
    
}


void MinMaxHeap::bubbleDownMin(unsigned int idx)
{
    if(idx >= size) throw invalid_argument("Index out of bounds");

    unsigned int minimum = idx;
    unsigned int left = leftChild(idx);

    if(left < size && heap[left] < heap[minimum]) minimum = left;
    if(left+1 < size && heap[left+1] < heap[minimum]) minimum = left;

    unsigned int leftGrandChild = leftChild(left);

    for (unsigned int i = 0; i < 4 && leftGrandChild + i < size; ++i)
        if (heap[leftGrandChild + i] < heap[minimum]) minimum = leftGrandChild + i;

    if(idx == minimum) return;

    swap(idx, minimum);
    //test to change comp
    if(minimum - left > 1){
        if(heap[minimum] > heap[parent(minimum)]) swap(minimum, parent(minimum));
        bubbleDownMin(minimum);
    }

}
MinMaxHeap::MinMaxHeap(int *arr, int n): size(n)
{
    for (int i = 0; i < n; i++) {
        heap[i] = arr[i];
    }
}

int main(){
    MinMaxHeap mmh(new int[0], 0);
    cout<<"Enter amount of elements: ";
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
        cout<<"Enter element #"<<i+1<<" : ";
        cin>>arr[i];
    }
    cout<<"Building Heap..."<<endl;
    mmh.buildHeap(n, arr);
    mmh.printHeap();
    cout<<"Max Element: "<<mmh.at(mmh.findMax())<<endl;
    cout<<"Min Element: "<<mmh.at(mmh.findMin())<<endl;
    cout<<"Deleting Max Element..."<<endl;
    mmh.deleteMax();
    mmh.printHeap();
    cout<<"Deleting Min Element..."<<endl;
    mmh.deleteMin();
    mmh.printHeap();
    cout<<"New Max Element: "<<mmh.at(mmh.findMax())<<endl;
    cout<<"New Min Element: "<<mmh.at(mmh.findMin())<<endl;
    return 0;
}