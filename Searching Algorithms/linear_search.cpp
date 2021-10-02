#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    long int arr[n];

    cout << "Enter the array elements: " << endl;
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }

    cout << "Elements of the array: " << endl;
    for(int i=0;i<n;i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    long int target;
    cout << "Enter the number to be found: ";
    cin >> target;
    for(int j=0;j<n;j++)
    {
        if(arr[j] == target)
        {
            cout << "Element found at: " << j;
            break;
        }
    }
    return 0;
}

//Time Complexity: O(n)
//Space complexity: O(1)
