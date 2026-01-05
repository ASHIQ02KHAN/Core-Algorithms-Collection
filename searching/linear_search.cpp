/*
Algorithm Name: Linear Search

Category: Searching Algorithm
Technique: Sequential Search

Description:
Linear Search checks each element of the list sequentially
until the desired element is found or the list ends.

Time Complexity:
- Best Case: O(1)
- Average Case: O(n)
- Worst Case: O(n)

Space Complexity:
- O(1)

Data Requirement:
- Works on both sorted and unsorted arrays

Use Case:
- Small datasets
- Unsorted data
*/

#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int main() {
    int arr[] = {10, 23, 45, 70, 11, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 70;

    int result = linearSearch(arr, n, key);

    if (result != -1)
        cout << "Element found at index " << result;
    else
        cout << "Element not found";

    return 0;
}
