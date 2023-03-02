#include <stdio.h>

int SumArray(int arr[], int size)
{
    int total = 0;
    for(int i=0 ; i<size ; i++)
        total += arr[i];

    return total;
}

int main()
{
    int arr[5] = {10, 40, 30, 20, 50};
    printf("%d", SumArray(arr, 5));
}