//Searching in Bitonic Array
//its the variation of finding peak element in array
//in bitonic array elements are first increasing and then decreasing
//So its like first half is sorted in ascending order and second half is sorted in descending order
//So we can first find the peak element index and then do binary search in both halves to find the target element .

//pseudocode:
//1. find peak element index using binary search
//2. do binary search in first half (0 to peak index)
//3. if not found in first half then do binary search in second half (peak index+1 to n-1)
