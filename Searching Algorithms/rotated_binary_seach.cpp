#include <bits/stdc++.h>
using namespace std;

class Array {
    // Attributes.
    int vector_size;
    vector<int> array;
    
    public:
    
    // Constructor.
    Array() {
        vector_size = 0;
    }
    
    // Input New Vector.
    void input_new_array() {
        array.clear();

        cout << "Enter Array Size: ";
        cin >> vector_size; 
        
        if(vector_size > 0) {
            int element;
            cout << "Enter Array Elements:\n";
            for(int i = 0; i < vector_size; ++i) {
                cin >> element;
                array.push_back(element);
            }    
        }
    }

    // Binary Search Logic.
    int rotated_binary_search(int target) {
        int start = 0;
        int end = array.size() - 1;
        
        while (start <= end)
        {
            int mid = (start + end) / 2;
            
            if (array[mid] == target)
                return mid;
            
            if (array[start] <= array[mid])
            {
                if(target >= array[start] && target <= array[mid])
                    end = mid - 1;
                else
                    start = mid + 1;
            }
            else
            {
                if (target >= array[mid] && target <= array[end])
                    start = mid + 1;
                else
                    end = mid - 1;
            }
        }

        return -1;
    }

    // Output Vector.
    void print_array() {
        for(auto &it : array)
            cout << it << ' ';
        cout << '\n';
    }
};

int main(void) {
    // Create array object.
    Array test_array;

    // Input array elements.
    test_array.input_new_array();
    cout << "Your Array:\n";
    test_array.print_array();

    // Searching
    int target;
    cout << "Enter Target: ";
    cin >> target;
    int index = test_array.rotated_binary_search(target);
    if(index == -1)
        cout << "Target Not Found.";
    else
        cout << "Target Found @ Index " << index << "!\n";
        
    return 0;
}