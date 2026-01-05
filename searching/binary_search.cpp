/*
Algorithm Name: Binary Search

Category: Searching Algorithm
Technique: Divide and Conquer

Description:
Binary Search works on sorted arrays by repeatedly dividing
the search interval in half.

Time Complexity:
- Best Case: O(1)
- Average Case: O(log n)
- Worst Case: O(log n)

Space Complexity:
- O(1) (Iterative)

Data Requirement:
- Array must be sorted

Use Case:
- Large sorted datasets
*/

#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 23;

    int result = binarySearch(arr, n, key);

    if (result != -1)
        cout << "Element found at index " << result;
    else
        cout << "Element not found";

    return 0;
}
