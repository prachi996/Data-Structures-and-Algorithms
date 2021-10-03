#include <iostream>
using namespace std;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selection_sort(int arr[], int n)
{
    int i, j, min_index;

    for (i = 0; i < n - 1; i++)
    {

        min_index = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_index])
                min_index = j;

        swap(&arr[min_index], &arr[i]);
    }
}

void showArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = {50, 23, 44, 78, 12, 89};
    int n = sizeof(arr) / sizeof(arr[0]);
    selection_sort(arr, n);
    cout << "Sorted array: \n";
    showArray(arr, n);
    return 0;
}
