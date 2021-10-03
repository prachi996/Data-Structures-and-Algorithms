// Insertion Sort Algorithm, Sorting array in ascending order

#include <stdio.h>

void Inserion_Sort(int arr[],int n)
{
    int i, j, key;

//insertion sort algorithm
    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void print_array(int arr[],int n)
{
    //printing sorted array elements
    printf("\n\nSorted array elements by insertion sort are :- \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int n; //elements in array are n

    printf("Enter number of elements in array : ");
    scanf("%d", &n);

    int arr[n]; //creating array named arr of size n
    //taking array input from user
    printf("\nEnter the elements in array : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    Inserion_Sort(arr,n);
    print_array(arr,n);

    return 0;
}
