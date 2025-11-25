#include <stdio.h>

void swap(int* a, int *b);
void bubble_sort(int n, int arr[n]);
void print_arr(int n, int arr[n]);

int main(void)
{
    int arr[5] = {11, 1, 2, 44, 1};
 
    print_arr(5, arr);

    bubble_sort(5, arr);

    print_arr(5, arr);

    return 0;
}

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubble_sort(int n, int arr[n])
{
    for(int j = 0; j < n - 1; j++)
    {
        int swaps = 0;
        for (int i = 0; i < n - j - 1; i++)
            if (arr[i] > arr[i+1])
            { 
                swap(&arr[i], &arr[i+1]);
                swaps++;
            }
        if(!swaps) break;
    }
}

void print_arr(int n, int arr[n])
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}