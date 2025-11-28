#include <stdio.h>

#define N 6

int binary_search(int target, int low, int high, int arr[]);
void print_arr(int n, int arr[n]);

int main(void)
{
    int arr[N] = {12, 32, 44, 55, 66, 77};

    print_arr(N, arr);

    int idx = binary_search(11, 0, 5, arr);
    if(idx != -1)
        printf("idx: %d, arr[idx]: %d\n", idx, arr[idx]);
    else
        printf("Not found\n");
}

int binary_search(int target, int low, int high, int arr[])
{
    while (low <= high) 
    {
        int mid = low + (high - low)/2;

        if (arr[mid] == target) return mid; 
        else if (arr[mid] > target) high = mid - 1;
        else low = mid + 1;
    }

    return -1;
}

void print_arr(int n, int arr[n])
{
    for (int i = 0; i < n; i++) 
        printf("%d ", arr[i]);
    printf("\n");
}