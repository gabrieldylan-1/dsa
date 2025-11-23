#include <stdio.h>

void merge(int start, int mid, int end, int arr[*]);
void merge_sort(int start, int end, int arr[*]);
void print_arr(int n, int arr[n]);

int main(void)
{
    int arr[5] = {11, 1, 2, 44, 1};

    print_arr(5, arr);
    merge_sort(0, 5, arr);
    print_arr(5, arr);

    return 0;
}

void print_arr(int n, int arr[n])
{
    for (int i = 0; i < n; i++) 
        printf("%d ", arr[i]);
    printf("\n");
}

void merge_sort(int start, int end, int arr[])
{
    if (end - start <= 1) return;

    int mid = start + (end - start) / 2;

    merge_sort(start, mid, arr);
    merge_sort(mid, end, arr);

    merge(start, mid, end, arr);
}

void merge(int start, int mid, int end, int arr[])
{
    // s1 = [start, mid), s2 = [mid, end)
    int s1 = mid - start, s2 = end - mid;
    int arr1[s1], arr2[s2];

    for (int i = 0, j = start; j < mid; i++, j++) arr1[i] = arr[j];
    for (int i = 0, j = mid; j < end; i++, j++) arr2[i] = arr[j];
    
    // print_arr(s1, arr1);
    // print_arr(s2, arr2);

    int i = 0, j = 0, k = start;

    while (i < s1 && j < s2) 
        if (arr1[i] < arr2[j])
            arr[k++] = arr1[i++];
        else
            arr[k++] = arr2[j++];
    
    while (i < s1) arr[k++] = arr1[i++];
    while (j < s2) arr[k++] = arr2[j++];
}

