#include <stdio.h>

// 정렬된 배열 조건
// 시간 복잡도: O(logN)
int BinarySEarch(int arr[], int size, int value)
{
    int low = 0, mid;
    int high = size-1;

    while(low <= high){
        mid = low + (high - low)/2;
        if(arr[mid] == value)
            return mid;
        else if(arr[mid] < value)
            low = mid + 1;
        else    
            high = mid -1;
    }

    return -1;
}

int main()
{
    int arr[5] = {10, 20, 30, 40, 50};
    printf("%d", BinarySEarch(arr, 5, 40));
}