#include <iostream>
#include <vector>
#include <map>
#include <algorithm> // For max() function


using namespace std;

// Sliding Window Approach - O(n) Time (for non-negative numbers)
int longestSubarrayWithSumK(vector<int> a, long long k) {
    int n = a.size();
    int left = 0, right = 0;
    int maxlen = 0;
    long long sum = 0;

    while (right < n) {
        sum += a[right];  // Expand window by adding a[right]

        // Shrink the window if sum exceeds k
        while (left <= right && sum > k) {
            sum -= a[left];
            left++;
        }

        // If sum matches k, update maxlen
        if (sum == k) {
            maxlen = max(maxlen, right - left + 1);
        }
        right++;  // Move right pointer forward
    }
    return maxlen;
}

// Brute Force Approach - O(n^2) Time
int longestSubarrayBruteForce(vector<int>& arr, int k) {
    int res = 0;
    for (int i = 0; i < arr.size(); i++) {
        int sum = 0;
        for (int j = i; j < arr.size(); j++) {
            sum += arr[j];
            if (sum == k) {
                int subLen = j - i + 1;
                res = max(res, subLen);
            }
        }
    }
    return res;
}

// Optimal Approach - O(n) Time (Handles negative numbers as well)
int longestSubarrayOptimal(vector<int>& nums, int k) {
    map<long long, int> presummap;
    long long sum = 0;
    int maxlen = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        if (sum == k) {
            maxlen = max(maxlen, i + 1);
        }
        int rem = sum - k;
        if (presummap.find(rem) != presummap.end()) {
            int len = i - presummap[rem];
            maxlen = max(maxlen, len);
        }
        if (presummap.find(sum) == presummap.end()) {
            presummap[sum] = i;
        }
    }
    return maxlen;
}

// Main function to test all approaches
int main() {
    // Test case 1 
    cout << "Test case 1:" << endl;
    cout << "for positive nums only" << endl;
    vector<int> arr1(5);
    arr1[0] = 1;
    arr1[1] = 2;
    arr1[2] = 3;
    arr1[3] = 4;
    arr1[4] = 5;
    int k =9;
    cout << "Sliding Window (Non-negative only): " << longestSubarrayWithSumK(arr1, k) << endl;

    cout << "for all the nums like +ve 0 -ve" << endl;
    vector<int> nums(8);
    nums[0] = 1;
    nums[1] = 2;
    nums[2] = -1; 
    nums[3] = 3;
    nums[4] = 4;
    nums[5] = -2;
    nums[6] = 2;
    nums[7] = -1;

    int m = 5;
    
    cout << "Brute Force: " << longestSubarrayBruteForce(nums, m) << endl;
    cout << "Optimal (Handles negative numbers): " << longestSubarrayOptimal(nums, m) << endl;
    
    return 0;
}
