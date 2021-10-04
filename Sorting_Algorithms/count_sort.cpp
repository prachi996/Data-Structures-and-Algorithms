#include <iostream>
#include <string>
#include <climits>
using namespace std;

void CountSort(int arr[], int n)
{
     // Finding the maximum value within the array
    int max_value = INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(arr[i] > max_value)
        {
            max_value = arr[i];
        }
    }
    
    // Initializing the count array with all values as 0
    int count[max_value+1];
    for(int i=0;i<=max_value;i++)
    {
        count[i] = 0;
    }
    
    // Updating the values in count array
    for(int i=0;i<n;i++)
    {
        ++count[arr[i]];
    }
    
    // Cumulative summation of count array values
    for(int i=0;i<max_value;i++)
    {
        count[i+1] += count[i];
    }
    
    // Updating the original array with sorted values
    int temp[n];
    for(int i=n-1;i>=0;i--)
    {
        temp[--count[arr[i]]] = arr[i];
    }
    
    cout << endl;
    // Printing the sorted array
    cout << "The final sorted array is: " << endl;
    for(int i=0;i<n;i++)
    {
        cout << temp[i] << " ";
    }
}



int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter the array elements: " << endl;
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }

    cout << "The elements are: " << endl;
    for(int i=0;i<n;i++)
    {
        cout << arr[i] << " ";
    }
    CountSort(arr, n);
    return 0;
}
