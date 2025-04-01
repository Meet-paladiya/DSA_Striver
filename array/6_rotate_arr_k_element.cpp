#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to reverse elements in the array between two indices
void reverseArray(vector<int>& arr, int start, int end) {
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

// Optimized Left Rotate using Reversal Algorithm (O(n) Time, O(1) Space)
void rotateLeft_less_space_complexity(vector<int>& arr, int d) {
    int n = arr.size();
    d = d % n; // Handle cases where d > n

    // Step 1: Reverse first d elements
    reverseArray(arr, 0, d);

    // Step 2: Reverse remaining n-d elements
    reverseArray(arr, d+1, n - 1);

    // Step 3: Reverse the entire array
    reverseArray(arr, 0, n - 1);
}

// Brute Force Left Rotate using Extra Space
void rotateLeft_bruteForce(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n; // Handle cases where k > n

    vector<int> temp(k);
    for (int i = 0; i < k; i++) {
        temp[i] = nums[i];
    }
    
    for (int i = 0; i < n - k; i++) {
        nums[i] = nums[i + k];
    }
    
    for (int i = 0; i < k; i++) {
        nums[n - k + i] = temp[i];
    }
}

// Right Rotate using Extra Space
void rotateRight(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;

    vector<int> temp(k);
    for (int i = 0; i < k; i++) {
        temp[i] = nums[n - k + i];
    }
    
    for (int i = n - k - 1; i >= 0; i--) {
        nums[i + k] = nums[i];
    }
    
    for (int i = 0; i < k; i++) {
        nums[i] = temp[i];
    }
}

int main() {
    int n, k;
    
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> nums(n), nums1, nums2;

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    cout << "Enter the value of k (shift positions): ";
    cin >> k;

    // Create copies for different rotation methods
    nums1 = nums;
    nums2 = nums;

    // Apply left rotation using optimized reversal method
    rotateLeft_less_space_complexity(nums, k);
    cout << "Left rotated array(more time complexity) (less space complexity): ";
    for (int num : nums) cout << num << " ";
    cout << endl;

    // Apply left rotation using brute force
    rotateLeft_bruteForce(nums1, k);
    cout << "Left rotated array (brute force): ";
    for (int num : nums1) cout << num << " ";
    cout << endl;

    // Apply right rotation
    rotateRight(nums2, k);
    cout << "Right rotated array: ";
    for (int num : nums2) cout << num << " ";
    cout << endl;

    return 0;
}
