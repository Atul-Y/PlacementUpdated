// Sort a nearly sorted (or K sorted) array
// Given an array arr[] and a number k . The array is sorted in a way that every element is at max k distance away from it sorted position. It means if we completely sort the array, then the index of the element can go from i - k to i + k where i is index in the given array. Our task is to completely sort the array.
// Examples:
// Input: arr= [6, 5, 3, 2, 8, 10, 9], k = 3
// Output: [2, 3, 5, 6, 8, 9, 10]

// Input: arr[]= [1, 4, 5, 2, 3, 6, 7, 8, 9, 10], k = 2
// Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

#include <bits/stdc++.h>
using namespace std;
void sortKSortedArray(vector<int> &arr, int k)
{
    priority_queue<int, vector<int>, greater<int>> mnhp;
    int j = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        mnhp.push(arr[i]);
        if (mnhp.size() > k)
        {
            arr[j++] = mnhp.top();
            mnhp.pop();
        }
    }
    while (!mnhp.empty())
    {
        arr[j++] = mnhp.top();
        mnhp.pop();
    }
}

int main()
{
    vector<int> arr = {6, 5, 3, 2, 8, 10, 9};
    int k = 3;
    sortKSortedArray(arr, k);
    for (auto x : arr)
        cout << x << " ";
    return 0;
}