#include <stdio.h>

int SequentialSearch(int arr[], int size, int value)
{
    for(int i=0 ; i<size ; i++){
        if(value == arr[i])
            return i;
    }

    return -1;
}

int main()
{
    int arr[5] = {10, 40, 30, 20, 50};
    printf("%d", SequentialSearch(arr, 5, 30));
}