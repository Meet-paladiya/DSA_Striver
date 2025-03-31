#include <iostream>
#include <vector>  // Include vector library
#include <ctime>   // Include ctime for clock()
#include <cstdlib> // Include cstdlib for rand()
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; // Temporary array
    int left = low;   // Left half start index
    int mid1 = mid + 1; // Right half start index

    // Merge two sorted halves
    while (left <= mid && mid1 <= high) {
        if (arr[left] <= arr[mid1]) {
            temp.push_back(arr[left]);
            left++;
        } else { // arr[mid1] < arr[left] je nanu hoi 1st arr and 2nd arr ma thi tene levanu final array ma 
            temp.push_back(arr[mid1]);
            mid1++;
        }
    }

    // Copy remaining elements of left half
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    // Copy remaining elements of right half
    while (mid1 <= high) {
        temp.push_back(arr[mid1]);
        mid1++;
    }

    // Copy back to original array
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void mergeSort(vector<int> &arr, int low, int high) {
    if (low >= high) return;
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);      // Sort left half
    mergeSort(arr, mid + 1, high); // Sort right half
    merge(arr, low, mid, high);    // Merge both halves
}

int main() {
    vector<int> arr = {9, 4, 7, 6, 3, 1, 5};  // Fixed vector initialization
    int n = arr.size();  // Use .size() instead of hardcoding size

    cout << "Before Sorting: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    mergeSort(arr, 0, n - 1);

    cout << "After Sorting: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
