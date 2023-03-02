#include <stdio.h>

// 왼쪽으로 회전
void reverseArray(int *a, int n)
{
    for(int i=0, j=n-1 ; i<j ; i++, j--)
        a[i] ^= a[j] ^= a[i] ^= a[j];
}

// k: 회전 횟수
void rotateArray2(int *a, int n, int k)
{
    reverseArray(a, k);
    reverseArray(&a[k], n-k);
    reverseArray(a, n);
}

int main()
{
    int arr[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    printf("%d\n", arr[0]);
    rotateArray2(arr, 10, 2);
    printf("%d", arr[0]);
}