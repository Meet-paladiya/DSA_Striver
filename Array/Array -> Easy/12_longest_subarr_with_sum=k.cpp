// Input:
// cpp
// Copy
// Edit
// nums = [1, 2, 1, 2, 1]
// k = 3
// Step-by-Step Execution
// Initial Variables
// sum = 0

// maxlen = 0

// presummap = {} (empty map)

// Iteration 1 (i = 0, nums[0] = 1)
// sum = 0 + 1 = 1

// sum == k → No

// rem = sum - k = 1 - 3 = -2

// presummap[-2] not found (Nothing happens)

// Store 1 in presummap:
// → presummap = {1: 0}

// Iteration 2 (i = 1, nums[1] = 2)
// sum = 1 + 2 = 3

// sum == k → ✅ Yes, maxlen = max(0, 2) = 2

// rem = sum - k = 3 - 3 = 0

// presummap[0] not found (Nothing happens)

// Store 3 in presummap:
// → presummap = {1: 0, 3: 1}

// Iteration 3 (i = 2, nums[2] = 1)
// sum = 3 + 1 = 4

// sum == k → No

// rem = sum - k = 4 - 3 = 1

// presummap[1] found at index 0

// len = i - presummap[1] = 2 - 0 = 2

// maxlen = max(2, 2) = 2

// Store 4 in presummap:
// → presummap = {1: 0, 3: 1, 4: 2}

// Iteration 4 (i = 3, nums[3] = 2)
// sum = 4 + 2 = 6

// sum == k → No

// rem = sum - k = 6 - 3 = 3

// presummap[3] found at index 1

// len = i - presummap[3] = 3 - 1 = 2

// maxlen = max(2, 2) = 2

// Store 6 in presummap:
// → presummap = {1: 0, 3: 1, 4: 2, 6: 3}

// Iteration 5 (i = 4, nums[4] = 1)
// sum = 6 + 1 = 7

// sum == k → No

// rem = sum - k = 7 - 3 = 4

// presummap[4] found at index 2

// len = i - presummap[4] = 4 - 2 = 2

// maxlen = max(2, 2) = 2

// Store 7 in presummap:
// → presummap = {1: 0, 3: 1, 4: 2, 6: 3, 7: 4}

#include <iostream>
#include <vector>
#include <map>
#include <algorithm> // For max() function


using namespace std;
//all on gfg

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

// → presummap = {1: 0}
// → presummap = {1: 0, 3: 1}
// → presummap = {1: 0, 3: 1, 4: 2}
// → presummap = {1: 0, 3: 1, 4: 2, 6: 3}
// → presummap = {1: 0, 3: 1, 4: 2, 6: 3, 7: 4}


// Optimal Approach - O(n) Time (Handles negative numbers as well)
int longestSubarrayOptimal(vector<int>& nums, int k) {
    map<long long, int> presummap;
    long long sum = 0;
    int maxlen = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        if (sum == k) {
            maxlen = max(maxlen, i + 1); // If sum is equal to k from the start
            // then we can take all the elements from 0 to i
            // so maxlen = i+1
            // because we are using 0 based index
        }
        int rem = sum - k;
        if (presummap.find(rem) != presummap.end()) { // means remainning che e last ele ne refer nathi kartu
            int len = i - presummap[rem]; // length of the subarray
            // from the last index of the remaining sum
            // to the current index
            // so we can take all the elements from presummap[rem] + 1 to i
            // so length = i - presummap[rem]
            // because we are using 0 based index
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
