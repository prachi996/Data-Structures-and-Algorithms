package Sorting_Algorithms;

public class mergeSort {

    public static void merge(int[] arr, int l, int m, int r){
        // First of, calculate the lengths of the temporary arrays which we are going to merge
        int l1 = m-l+1;
        int l2 = r-m;

        //Create the temporary arrays and copy the data into them
        int[] left = new int[l1], right = new int[l2];

        // Copy elements of left subarray into left[] array
        for(int i=0;i<l1;++i){
            left[i] = arr[l+i];
        }
        //Copy elements of right subarray into right[] array
        for(int i=0;i<l2;++i){
            right[i] = arr[m+1+i];
        }

        int i=0, j=0, k=l; // These 2 pointers i and j shall go through the 2 temporary arrays created and merge them

        while(i<l1 && j<l2){
            if(left[i]<=right[j])
                arr[k] = left[i++];
            else{
                arr[k] = right[j++];
            }
            k++;
        }

        //After the above while loop after all the comparisons are finished, add the rest of the elements of both the arrays inside arr
        while(i<l1)
            arr[k++] = left[i++];

        while(j<l2)
            arr[k++] = right[j++];
    }

    public static void sort(int[] arr, int l, int r){
        if(l<r){
            // Find out the middle element
            int m = l + (r-l)/2;

            //Divide the array into 2 equal parts and sort them
            sort(arr, l, m);
            sort(arr, m+1, r);

            //Finally merge the 2 sorted subarrays using merge function written above
            merge(arr, l, m, r);
        }   
    }

    public static void main(String[] args) {
        int[] arr = {9,8,7,6,5,4,3,2,1};  //This is a simple example with worst case time complexity. Since we are sorting in ascending order, if an array is given in the descending order, then for sorting it in ascending will take the longest amount of time

        sort(arr, 0, arr.length-1);

        // Print the sorted array
        for(int i=0;i<arr.length;i++){
            System.out.print(arr[i] + " ");
        }
    }
}