#include <stdio.h>

void print_arr(int n, int arr[n]);
void insertion_sort(int n, int arr[n]);

int main(void)
{
    int arr[5] = {11, 1, 2, 44, 1};

    print_arr(5, arr);
    insertion_sort( 5, arr);
    print_arr(5, arr);

    return 0;
}

void insertion_sort(int n, int arr[n])
{

    for (int i = 1; i < n; i++) 
    {
        int j = i - 1;
        int key = arr[i];

        while (j >= 0 && arr[j] > key) 
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[++j] = key;
    }
}

void print_arr(int n, int arr[n])
{
    for (int i = 0; i < n; i++) 
        printf("%d ", arr[i]);
    printf("\n");
}
