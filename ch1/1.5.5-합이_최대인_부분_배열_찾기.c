#include <stdio.h>

int maxSubArraySum(int a[], int size)
{
    int maxSoFar = 0, maxEndingHere = 0;

    for(int i=0 ; i<size ; i++){
        maxEndingHere += a[i];

        if(maxEndingHere < 0)
            maxEndingHere = 0;

        if(maxSoFar < maxEndingHere)
            maxSoFar = maxEndingHere;
    }

    return maxSoFar;
}

int main()
{
    int arr[5] = {-30, 20, -40, -10, 50};
    printf("%d", maxSubArraySum(arr, 5));
}