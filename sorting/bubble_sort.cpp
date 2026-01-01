/*
Algorithm Name: Bubble Sort

Category: Sorting Algorithm
Technique: Comparison-based, In-place

Description:
Bubble Sort repeatedly steps through the list, compares adjacent elements,
and swaps them if they are in the wrong order. The process is repeated until
the list is sorted.

Time Complexity:
- Best Case: O(n)
- Average Case: O(n^2)
- Worst Case: O(n^2)

Space Complexity:
- O(1) (In-place sorting)

Stability:
- Stable

Use Case:
- Educational purposes
- Small datasets
*/

#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    bubbleSort(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
