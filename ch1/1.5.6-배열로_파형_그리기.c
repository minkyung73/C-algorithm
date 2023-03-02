#include <stdio.h>

void swap(int arr[], int a, int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void quickSort(int arr[], int L, int R)
{
    int left = L, right = R-1;
    int pivot = arr[(left+right)/2];
    int temp;

    do{
        while(arr[left] < pivot)
            left++;
        while(arr[right] > pivot)
            right--;

        if(left <= right){
            temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;

            left++;
            right--;
        }
    }while(left <= right);

    // recursion
    if(L < right)
        quickSort(arr, L, right);
    if(left < R)
        quickSort(arr, left, R);
}

void WaveArray(int arr[], int size)
{
    quickSort(arr, 0, size-1);
    // 배열의 인접 원소끼리 바꾸기
    for(int i=0 ; i<size-1 ; i+=2)
        swap(arr, i, i+1);
}

void WaveArray2(int arr[], int size)
{
    // 홀수 인덱스는 짝수 인덱스보다 작다
    for(int i=1 ; i<size ; i+=2){
        if((i-1) >= 0 && arr[i] > arr[i-1])
            swap(arr, i, i-1);
        if((i+1) < size && arr[i] > arr[i+1])
            swap(arr, i, i+1);
    }
}

void printArray(int arr[], int size)
{
    for(int i=0 ; i<size ; i++)
        printf("%d ", arr[i]);
}

int main()
{
    int arr[] = {8, 1, 2, 3, 4, 5, 6, 4, 2};
    int size = size = sizeof(arr)/sizeof(int);
    WaveArray2(arr, size);
    printArray(arr, size);

    return 0;
}