#include "../header/heap.h"
#include <cmath>
#include <iostream>
#include "heap.h"
using namespace std;

void MinMaxHeap::swap(unsigned int i, unsigned int j)
{
    int temp = heapContainer[i];
    heapContainer[i] = heapContainer[j];
    heapContainer[j] = temp; 
}
// Helper functions to navigate container space.
unsigned int MinMaxHeap::parent(unsigned int index)
{
    return (index - 1) / 2;
}

unsigned int MinMaxHeap::leftChild(unsigned int index)
{
    return (2 * index + 1);
}

unsigned int MinMaxHeap::rightChild(unsigned int index)
{
    return (2 * index + 2);
}


//Beautiful
bool MinMaxHeap::minLevel(unsigned int index)
{
    return (int(floor(log2(index))) % 2 == 0);
}

bool MinMaxHeap::maxLevel(unsigned int index)
{
    return !minLevel(index); 
}

void MinMaxHeap::trickleDown(int index)
{
    if(minLevel(index)) trickleDown_min(index);
    if(maxLevel(index)) trickleDown_max(index);
}

void MinMaxHeap::trickleDown_min(int index)
{
    //implement

    if(index > size) std::__throw_invalid_argument("Element does not exist...");

    unsigned int smallest = index, l = leftChild(index), r = rightChild(index);

    // Check Children.
    if((l < size) && (heapContainer[l]  < heapContainer[smallest]))
        smallest = l;
    if((r < size) && (heapContainer[r] < heapContainer[smallest]))
        smallest = r;
    
    //Check Grandchildren
    unsigned int lGc = leftChild(l);
    for(int i = 0 ; i < 4 && lGc+i < size; ++i)
        if((heapContainer[lGc + i] ) < heapContainer[smallest])
            smallest = lGc+i;
    
    //If the smallest is equal to index -> index is the smallest value -> do nothing.
    if (index == smallest) return;
    // Else swap the value at the index passed & the smallest node
    swap(index,smallest);

    // If the difference between the smallest node and the left child is not 0, this means that it must be 
    if((smallest - l) > 1)
    {
        if(heapContainer[smallest] < heapContainer[parent(smallest)]) swap(smallest, parent(smallest));
        trickleDown_min(smallest);
    }
}

void MinMaxHeap::trickleDown_max(int index)
{
    //implement


    if(index > size) std::__throw_invalid_argument("Index is out of bounds...");

    unsigned int largest = index, l = leftChild(index), r = rightChild(index);

    // Check Children.
    if((l < size) && (heapContainer[l]  > heapContainer[largest]))
        largest = l;
    if((r < size) && (heapContainer[r] > heapContainer[largest]))
        largest = r;
    
    //Check Grandchildren
    unsigned int lGc = leftChild(l);
    for(int i = 0 ; i < 4 && lGc+i < size; ++i)
        if((heapContainer[lGc + i] ) > heapContainer[largest])
            largest = lGc+i;
    
    //If the largest is equal to index -> index is the largest value -> do nothing.
    if (index == largest) return;
    // Else swap the value at the index passed & the largest index
    swap(index,largest);

    // If the difference between the largest index and the left child index is not 0, this means that it must be 
    if((largest - l) > 1)
    {
        if(heapContainer[largest] > heapContainer[parent(largest)]) swap(largest, parent(largest));
        trickleDown_max(largest);
    }
}

void MinMaxHeap::trickleUp(int index)
{
    if(minLevel(i))
        if(index != 0 )
}
void MinMaxHeap::trickleUp_min(int index)
{
}
void MinMaxHeap::trickleUp_max(int index)
{
}
void MinMaxHeap::print()
{
    cout<<"Heap: [ ";
    for(int i = 0 ; i < size; i++)
        {if(i == (size-1))
            cout<<heapContainer[i]<<" ]"<<endl;
        else
            cout<<heapContainer[i]<<", ";}
}
