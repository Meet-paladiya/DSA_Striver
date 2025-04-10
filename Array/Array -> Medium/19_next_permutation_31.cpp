#include <iostream>
#include <vector>
#include <algorithm> // For reverse and next_permutation

using namespace std;

// Not implemented but yes it exists
// Brute Force: Finding all possible permutations. 
// Approach :
// Step 1: Find all possible permutations of elements present and store them.
// Step 2: Search input from all possible permutations.
// Step 3: Print the next permutation present right after it.

// With C++ STL
// Better
// class Solution {
// public:
//     void nextPermutation(vector<int>& nums) {
//         int n = nums.size();
//         next_permutation(nums.begin(), nums.end());
//     }
// };

// Optimal one
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int indx = -1;

        // Step 1: Find the first index from the end where nums[i] < nums[i + 1]
        // This marks the pivot point where the next permutation change is needed
        // if nums = {3,2,5,4,3,0,0} then indx 1 means nums[1] = 2 is the pivot point
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                indx = i;
                break;
            }
        }

        // Step 2: If no such index is found, the array is in descending order
        // Reverse the entire array to get the lowest (first) permutation
        if (indx == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 3: Find the next greater element to the right of indx and swap
        // It should be the smallest number greater than nums[indx]
        for (int i = n - 1; i > indx; i--) {
            if (nums[i] > nums[indx]) {
                swap(nums[i], nums[indx]);
                break;
            }
        }

        // Step 4: Reverse the subarray to the right of indx to get the next smallest lexicographical order
        reverse(nums.begin() + indx + 1, nums.end());
    }
};

// Example usage
int main() {
    Solution sol;
    vector<int> nums(7);
    nums[0] = 3; nums[1] = 2; nums[2] = 5; nums[3] = 4; nums[4] = 3;
    nums[5] = 0; nums[6] = 0;

    cout << "Original: ";
    for (int num : nums) cout << num << " ";
    cout << endl;

    sol.nextPermutation(nums);

    cout << "Next Permutation: ";
    for (int num : nums) cout << num << " ";
    cout << endl;

    return 0;
}
