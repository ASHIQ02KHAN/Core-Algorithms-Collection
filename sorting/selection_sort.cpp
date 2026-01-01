/*
Algorithm Name: Selection Sort

Category: Sorting Algorithm
Technique: Comparison-based, In-place

Description:
Selection Sort divides the array into a sorted and an unsorted part.
It repeatedly selects the minimum element from the unsorted part and
moves it to the beginning.

Time Complexity:
- Best Case: O(n^2)
- Average Case: O(n^2)
- Worst Case: O(n^2)

Space Complexity:
- O(1)

Stability:
- Not Stable

Use Case:
- When memory writes are costly
- Small datasets
*/

#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
}

int main() {
    int arr[] = {29, 10, 14, 37, 13};
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
