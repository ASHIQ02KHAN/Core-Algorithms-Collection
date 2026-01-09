/*
Algorithm Name: Jump Search

Category: Searching Algorithm
Technique: Block Jumping

Description:
Jump Search works on sorted arrays by jumping ahead
by fixed steps and then performing linear search.

Time Complexity:
- Best Case: O(1)
- Average Case: O(√n)
- Worst Case: O(√n)

Space Complexity:
- O(1)

Data Requirement:
- Array must be sorted

Use Case:
- Faster than linear search for sorted arrays
*/

#include <iostream>
#include <cmath>
using namespace std;

int jumpSearch(int arr[], int n, int key) {
    int step = sqrt(n);
    int prev = 0;

    while (arr[min(step, n) - 1] < key) {
        prev = step;
        step += sqrt(n);
        if (prev >= n)
            return -1;
    }

    for (int i = prev; i < min(step, n); i++) {
        if (arr[i] == key)
            return i;
    }

    return -1;
}

int main() {
    int arr[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 13;

    int result = jumpSearch(arr, n, key);

    if (result != -1)
        cout << "Element found at index " << result;
    else
        cout << "Element not found";

    return 0;
}
