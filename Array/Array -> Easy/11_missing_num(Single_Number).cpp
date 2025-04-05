#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

// Brute Force Approach - O(n^2) Time, O(1) Space
int singleNumberBruteForce(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        int num = nums[i];
        for (int j = 0; j < n; j++) {
            if (nums[j] == num) {
                cnt++;
            }
        }
        if (cnt == 1) return num;
    }
    return -1;
}

// Better Approach - O(n) Time, O(max element) Space (using frequency array)
int singleNumberBetter(vector<int>& nums) {
    int n = nums.size();
    int maxi = nums[0];
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, nums[i]);
    }
    vector<int> hash(maxi + 1, 0);
    for (int i = 0; i < n; i++) {
        hash[nums[i]]++;
    }
    for (int i = 0; i < n; i++) {
        if (hash[nums[i]] == 1) {
            return nums[i];
        }
    }
    return -1;
}

// Better Approach - O(n) Time, O(n) Space (using unordered_map)
int singleNumberMap(vector<int>& nums) {
    unordered_map<int, int> freq;
    for (int num : nums) {
        freq[num]++;
    }
    for (auto it : freq) {
        if (it.second == 1) {
            return it.first;
        }
    }
    return -1;
}

// Optimal Approach - O(n) Time, O(1) Space (using XOR)
int singleNumberOptimal(vector<int>& nums) {
    int xorr = 0;
    for (int num : nums) {
        xorr = xorr ^ num;
    }
    return xorr;
}

// Main function to test the implementations
int main() {
    vector<int> nums(5);
    nums[0] = 4; // Test case
    nums[1] = 1; // Test case
    nums[2] = 2; // Test case
    nums[3] = 1; // Test case
    nums[4] =2;
    
    cout << "Brute Force: " << singleNumberBruteForce(nums) << endl;
    cout << "Better Approach (Frequency Array): " << singleNumberBetter(nums) << endl;
    cout << "Better Approach (Unordered Map): " << singleNumberMap(nums) << endl;
    cout << "Optimal Approach (XOR): " << singleNumberOptimal(nums) << endl;
    
    return 0;
}
