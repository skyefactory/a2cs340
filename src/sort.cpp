#include "../header/sort.h"

void sort (int *a, const int &size){
    int i,j,t;
    for(i = 0 ; i < size ; i++)
        for(j = i + 1; j < size; j++){
            if(a[j] < a[i])
            {
                t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
}   