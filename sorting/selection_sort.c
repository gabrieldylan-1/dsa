#include <stdio.h>

void swap(int* a, int *b);
int find_min_index(int s, int n, int arr[n]);
void selection_sort(int n, int arr[n]);
void print_arr(int n, int arr[n]);

int main(void)
{
    int arr[5] = {11, 1, 2, 44, 1};
 
    print_arr(5, arr);

    selection_sort(5, arr);

    print_arr(5, arr);

    return 0;
}

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int find_min_index(int s, int n, int arr[n])
{
    int m = arr[s], ans = s;

    for (int i = s+1; i < n; i++) 
    {
        if (arr[i] < m)
        {
            m = arr[i];
            ans = i;
        }
    }
    
    return ans;
}

void selection_sort(int n, int arr[n])
{
    for (int i = 0; i < n; i++) 
    {
        int min_index = find_min_index(i, n, arr);
        swap(&arr[min_index], &arr[i]);
    }
}

void print_arr(int n, int arr[n])
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}