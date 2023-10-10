#include<stdlib.h>
#include<iostream>
#include<string>
#include "../header/sort.h"

using namespace std;

int opt = -1;
string i1, i2;
int sizeis = 0;
int *arr;
int main()
{
    elmIn:
        i1="",i2="";
        cout<<"Please enter the number of elements\n";
        getline(cin, i1);
        try {sizeis = stoi(i1);}
        catch (exception &e) {goto elmIn;}
        if (sizeis <= 0) 
        {
            cout<<"Please enter a number greater then 0\n";
            sizeis = 0;
            goto elmIn;
        }
        goto arrIn;

    arrIn:
        delete arr;
        system("clear");
        arr = new int(sizeis);
        for(int i = 0; i < sizeis; i++){
            i2 = "";
            cout<<i<<"# :"; getline(cin, i2);
            try {arr[i] = stoi(i2);}
            catch (exception &e) {goto arrIn;}
        }
        goto endIn;

    endIn:
        sort(arr,sizeis);
        cout<<"You entered: [ ";
        for(int i = 0; i < sizeis; i++){
            (i == 0) ? cout<<arr[i] :  cout<<", "<<arr[i];
        }
        cout<<" ]"<<endl;
    return 0;
}