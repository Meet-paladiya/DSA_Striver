#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    // Function to sort an array using QuickSort algorithm
    void quickSort(vector<int>& arr, int low, int high) {
        if (low < high) {
            int pindex = partition(arr, low, high);
            quickSort(arr, low, pindex - 1);
            quickSort(arr, pindex + 1, high);
        }
    }

    // Function to partition the array
    int partition(vector<int>& arr, int low, int high) {
        int pivot = arr[low];
        int i = low, j = high;

        while (i < j) {
            while (arr[i] <= pivot && i < high) i++;  // Move right until element > pivot
            while (arr[j] > pivot && j > low) j--;   // Move left until element ≤ pivot

            if (i < j) swap(arr[i], arr[j]);  // Swap misplaced elements
        }

        swap(arr[low], arr[j]);  // Swap pivot with correct position
        return j;
    }
};

// Main function to test QuickSort
int main() {
    Solution sol;
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    
    int n = arr.size();
    cout << "Original array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    sol.quickSort(arr, 0, n - 1); // Sorting the array

    cout << "Sorted array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}
