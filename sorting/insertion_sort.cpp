/*
Algorithm Name: Insertion Sort

Category: Sorting Algorithm
Technique: Comparison-based, In-place

Description:
Insertion Sort builds the final sorted array one element at a time.
It is efficient for small datasets and nearly sorted arrays.

Time Complexity:
- Best Case: O(n)
- Average Case: O(n^2)
- Worst Case: O(n^2)

Space Complexity:
- O(1)

Stability:
- Stable

Use Case:
- Small or nearly sorted data
- Online sorting
*/

#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
