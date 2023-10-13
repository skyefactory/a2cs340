#include "../header/heap.h"
#include <iostream>
#include <stdlib.h>


using namespace std;


int main(){
    int *in;
    goto sizeIn;
    sizeIn:
        unsigned int size = 0;

        cout<<"How many initial elements? : "; 
        try {cin>>size;}
        catch(exception &e){cout<<"Please enter an integer value for the size...\n"; goto sizeIn;}
        if(size == 0)
            {
                cout<<"Please enter a number greater than 0.\n";
                goto sizeIn;
            }
        goto inputIn;

    inputIn:
        cout<<"Please enter the elements \n";
        in = new int[size]{};
        for(int i = 0 ; i < size; i++)
        {
            int x = 0;
            try
            {

                cout<<(i+1)<<" : ";
                cin>>x;
                in[i] = x;

            }
            catch(exception &e) {cout<<"Please enter integers only...\n"; delete in; goto inputIn;}
            
        }
        cout<<"You Entered [ ";
        for(int i = 0 ; i < size; i++)
            {if(i == (size-1))
                cout<<in[i]<<" ]"<<endl;
            else
                cout<<in[i]<<", ";}
        goto heapify;

    heapify:
        MinMaxHeap mmh(in,size);
        mmh.print();
    return 0;







}