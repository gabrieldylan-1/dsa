#include <stdio.h>

int partition(int start, int end, int arr[*]);
void quicksort(int start, int end, int arr[*]);
void print_arr(int n, int arr[n]);
void swap(int* a, int* b);

int main(void)
{
    int arr[5] = {11, 1, 2, 44, 1};

    quicksort(0, 5, arr);

    print_arr(5, arr);

    return 0;
}

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void print_arr(int n, int arr[n])
{
    for (int i = 0; i < n; i++) 
        printf("%d ", arr[i]);
    printf("\n");
}

void quicksort(int start, int end, int arr[])
{
    if (end - start <= 1) return;

    int pivot_index = partition(start, end, arr);

    quicksort(start, pivot_index, arr);
    quicksort(pivot_index+1, end, arr);
}

int partition(int start, int end, int arr[])
{
    int pivot = arr[end - 1], pivot_index = start;

    for (int i = start; i < end - 1; i++) 
        if (arr[i] <= pivot)
            swap(&arr[i], &arr[pivot_index++]);
    swap(&arr[pivot_index], &arr[end - 1]);

    return pivot_index;
}