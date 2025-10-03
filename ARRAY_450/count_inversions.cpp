// Example 1:

// Input: N = 5, arr[] = {2, 4, 1, 3, 5}
// Output: 3
// Explanation: The sequence 2, 4, 1, 3, 5
// has three inversions (2, 1), (4, 1), (4, 3).
// Example 2:

// Input: N = 5
// arr[] = {2, 3, 4, 5, 6}
// Output: 0
// Explanation: As the sequence is already
// sorted so there is no inversion count.
// Example 3:

// Input: N = 3, arr[] = {10, 10, 10}
// Output: 0
// Explanation: As all the elements of array
// are same, so there is no inversion count.

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;
//     int arr[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     int c = 0;
//     for (int i = 0; i < n - 1; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             if (arr[j] < arr[i])
//             {
//                 c++;
//             }
//         }
//     }
//     cout << c;
// }





// this question is always been asked to solve using merge sort technique

// C++ program to Count
// Inversions in an array
// using Merge Sort
#include <bits/stdc++.h>
using namespace std;

int _mergeSort(int arr[],int left, int right);
int merge(int arr[],int left, int mid,
          int right);

// This function sorts the
// input array and returns the
// number of inversions in the array
int mergeSort(int arr[], int array_size)
{
       return _mergeSort(arr,0,array_size - 1);
}

// An auxiliary recursive function
// that sorts the input array and
// returns the number of inversions in the array.
int _mergeSort(int arr[],int left, int right)
{
    // Inversion count will be sum of
    // inversions in left-part, right-part
    // and number of inversions in merging

    int mid, inv_count = 0;
    if (right > left)
    {
         
        mid = (right + left) / 2;

        // Recursively count inversions in the left and 
        // right halves
        inv_count += _mergeSort(arr,left, mid);  
        inv_count += _mergeSort(arr,mid + 1, right);

    //  count the cross inversions
        // i.e., count inversions where one element is in the left half
        inv_count += merge(arr,left, mid + 1, right);
    }
    return inv_count;
}

// This function merges two sorted arrays
// and returns inversion count in the arrays.
int merge(int arr[], int left, int mid, int right)
{
    int i = left, j = mid, k = left;
    int inv_count = 0;
    int temp[right + 1]; // Temporary array

    while (i <= mid - 1 && j <= right)
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
        {
            temp[k++] = arr[j++];
            inv_count += (mid - i);  // There are mid - i inversions, because all the remaining elements in the left subarray (arr[i], arr[i+1], ..., arr[mid-1]) are greater than arr[j]
        }
    }

    // Copy the remaining elements of left subarray, if any
    while (i <= mid - 1)
        temp[k++] = arr[i++];
        // Copy the remaining elements of right subarray, if any
    while (j <= right)
        temp[k++] = arr[j++];

    // Copy back to original array
    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}

// Driver code
int main()
{
    int arr[] = {1, 20, 6, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int ans = mergeSort(arr,n);
    cout << " Number of inversions are " << ans;
    return 0;
}

//provide pseudo code for the above code
// Pseudo Code for Count Inversions using Merge Sort
/*function mergeSort(arr, left, right):
    if left < right:
        mid = (left + right) / 2
        inv_count = 0
        
        // Count inversions in left half
        inv_count += mergeSort(arr, left, mid)
        
        // Count inversions in right half
        inv_count += mergeSort(arr, mid + 1, right)
        
        // Merge the two halves and count inversions during merging
        inv_count += merge(arr, left, mid + 1, right)
        
        return inv_count   */