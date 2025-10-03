#include <bits/stdc++.h>
using namespace std;

// int main()
// {
//     int n;
//     cin>>n;
//     int arr[n];
//     for(int i=0; i<n; i++)
//     {
//         cin>>arr[i];
//     }
//     cout<<arr[n-1];
//     for(int i=0; i<n-1; i++)
//     {
//         cout<<" "<<arr[i];
//     }

// }

#include <iostream>
#include <vector>
using namespace std;

void rotateclockwise(vector<int> &arr, int k) {
    if (k == 0) {
        return;
    }

    int n = arr.size();
    if (n == 0) return;

    // Rotate array to the right by 1 position
    int temp = arr[n - 1];
    for (int i = n - 1; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = temp;

    // Recursive call for remaining k-1 rotations
    rotateclockwise(arr, k - 1);
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    int k = 2;

    rotateclockwise(arr, k);
    for (auto it : arr) {
        cout << it << " ";
    }

    return 0;
}

// Pseudo Code for Cyclic Rotate an Array by One using Recursion
/*function rotateclockwise(arr, k):
    if k == 0:
        return
    n = length of arr
    if n == 0:
        return

    // Rotate the last element to the front
    temp = arr[n - 1]
    for i from n - 1 down to 1:
        arr[i] = arr[i - 1]
    arr[0] = temp

    // Recursive call for remaining k-1 rotations
    rotateclockwise(arr, k - 1)  */


  //tree diagram with euler path
//   rotateclockwise(arr, 2)
//         |
//         v
// rotateclockwise(arr, 1)
//         |
//         v
// rotateclockwise(arr, 0)   <-- base case, returns  





