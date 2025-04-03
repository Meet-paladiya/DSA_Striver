#include <iostream>
#include <vector>

using namespace std;

// Brute Force Approach: Uses extra space
void moveZerosToEnd(vector<int>& arr) {
    vector<int> temp; // Temporary array to store non-zero elements

    // Step 1: Extract all non-zero elements
    for (int num : arr) {
        if (num != 0) {
            temp.push_back(num);
        }
    }

    int nonZeroCount = temp.size(); // Number of non-zero elements

    // Step 2: Copy non-zero elements back to the original array
    for (int i = 0; i < nonZeroCount; i++) {
        arr[i] = temp[i];
    }

    // Step 3: Fill the rest of the array with zeros
    for (int i = nonZeroCount; i < arr.size(); i++) {
        arr[i] = 0;
    }
}

// Optimal Approach: In-place shifting (Two-Pointer Technique)
void moveZeroes_optimal(vector<int>& nums) {
    int i = 0;

    // First pass: Move non-zero elements to the front
    for (int j = 0; j < nums.size(); j++) {
        if (nums[j] != 0) {
            nums[i++] = nums[j]; // Place non-zero element at index i
        }
    }

    // Second pass: Fill the remaining elements with zeros
    for (int x = i; x < nums.size(); x++) {
        nums[x] = 0; // Fill the rest of the array with zeros
    }
}

int main() {
    vector<int> arr1(9);
    arr1[0] = 1; 
    arr1[1] = 0;
    arr1[2] = 2;
    arr1[3] = 3;
    arr1[4] = 2;
    arr1[5] = 0;
    arr1[6] = 0;
    arr1[7] = 4;
    arr1[8] = 5;

    vector<int> arr2(5);
    arr2[0] = 0;
    arr2[1] = 1;
    arr2[2] = 0;
    arr2[3] = 3;
    arr2[4] = 12;
    
    // Brute Force Approach
    cout << "Before (Brute Force): ";
    for (int num : arr1) cout << num << " ";
    cout << endl;

    moveZerosToEnd(arr1);

    cout << "After (Brute Force): ";
    for (int num : arr1) cout << num << " ";
    cout << endl;

    // Optimal Approach
    cout << "Before (Optimal): ";
    for (int num : arr2) cout << num << " ";
    cout << endl;

    moveZeroes_optimal(arr2);

    cout << "After (Optimal): ";
    for (int num : arr2) cout << num << " ";
    cout << endl;

    return 0;
}
