/*
Algorithm Name: Interpolation Search

Category: Searching Algorithm
Technique: Improved Binary Search

Description:
Interpolation Search estimates the position of the key
based on value distribution.

Time Complexity:
- Best Case: O(1)
- Average Case: O(log log n)
- Worst Case: O(n)

Space Complexity:
- O(1)

Data Requirement:
- Sorted array
- Uniformly distributed data

Use Case:
- Large uniformly distributed datasets
*/

#include <iostream>
using namespace std;

int interpolationSearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high && key >= arr[low] && key <= arr[high]) {
        if (low == high) {
            if (arr[low] == key)
                return low;
            return -1;
        }

        int pos = low + ((double)(high - low) /
                         (arr[high] - arr[low])) * (key - arr[low]);

        if (arr[pos] == key)
            return pos;
        if (arr[pos] < key)
            low = pos + 1;
        else
            high = pos - 1;
    }
    return -1;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 50;

    int result = interpolationSearch(arr, n, key);

    if (result != -1)
        cout << "Element found at index " << result;
    else
        cout << "Element not found";

    return 0;
}
