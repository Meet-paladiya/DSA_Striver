// Problem: Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
#include <iostream>
#include <vector>
#include <algorithm> // For max() function
using namespace std;

// Brute Force Approach (O(n^2) Time Complexity)
int maxSubArrayBruteForce(vector<int>& nums) {
    int n = nums.size();
    int maxsum = INT_MIN;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) { // Compute all subarrays starting from i
            sum += nums[j];
            maxsum = max(maxsum, sum);
        }
    }
    return maxsum;
}

// Kadane’s Algorithm (O(n) Time Complexity)
int maxSubArrayKadane(vector<int>& nums) {
    int maxsum = INT_MIN;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        maxsum = max(maxsum, sum);
        if (sum < 0) sum = 0; // Reset sum if it goes negative // IMP
    }
    return maxsum;
}

int main() {
    vector<int> nums(9);
    nums[0] = -2;
    nums[1] = 1;
    nums[2] = -3;
    nums[3] = 4;
    nums[4] = -1;
    nums[5] = 2;
    nums[6] = 1;
    nums[7] = -5;
    nums[8] = 3;
    cout << "Input Array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Brute Force Result: " << maxSubArrayBruteForce(nums) << endl;
    cout << "Kadane's Algorithm Result: " << maxSubArrayKadane(nums) << endl;

    return 0;
}
