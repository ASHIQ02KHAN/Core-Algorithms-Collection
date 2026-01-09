/*
Algorithm Name: Exponential Search

Category: Searching Algorithm
Technique: Exponential Growth + Binary Search

Description:
Exponential Search finds a range where the element may exist
and then applies Binary Search within that range.

Time Complexity:
- Best Case: O(1)
- Average Case: O(log n)
- Worst Case: O(log n)

Space Complexity:
- O(1)

Data Requirement:
- Sorted array

Use Case:
- Searching in unbounded or infinite arrays
*/

#include <iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int key) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key)
            return mid;
        if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int exponentialSearch(int arr[], int n, int key) {
    if (arr[0] == key)
        return 0;

    int i = 1;
    while (i < n && arr[i] <= key)
        i *= 2;

    return binarySearch(arr, i / 2, min(i, n - 1), key);
}

int main() {
    int arr[] = {2, 3, 4, 10, 40, 55, 60};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 10;

    int result = exponentialSearch(arr, n, key);

    if (result != -1)
        cout << "Element found at index " << result;
    else
        cout << "Element not found";

    return 0;
}
