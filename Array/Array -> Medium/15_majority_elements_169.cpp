#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Brute Force Approach (Time Limit Exceeds)
int majorityElementBruteForce(vector<int>& nums) {
    int n = nums.size();
    int requiredFreq = n / 2;
    for (int i = 0; i < n; i++) {
        int freq = 0;
        for (int j = 0; j < n; j++) {
            if (nums[j] == nums[i]) freq++;
        }
        if (freq > requiredFreq) return nums[i];
    }
    return -1;
}

// Better Approach (Using Hash Map)
int majorityElementWithMap(vector<int>& nums) {
    int requiredFreq = nums.size() / 2;
    map<int, int> freq;
    
    for (int num : nums) {
        freq[num]++;
    }

    for (auto it : freq) {
        if (it.second > requiredFreq) {
            return it.first;
        }
    }
    return -1;
}

// Optimal Approach (Boyer-Moore Voting Algorithm)
int majorityElementOptimal(vector<int>& nums) {
    int n = nums.size();
    int el, cnt = 0;
    
    // Step 1: Finding candidate
    for (int i = 0; i < n; i++) {
        if (cnt == 0) {
            el = nums[i];
            cnt = 1;
        } else if (el == nums[i]) {
            cnt++;
        } else {
            cnt--;
        }
    }

    // Step 2: Verify the candidate
    int cnt1 = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == el) cnt1++;
    }
    return (cnt1 > n / 2) ? el : -1;
}

int main() {
    vector<int> nums(7);
    nums[0] = 3;
    nums[1] = 2;
    nums[2] = 3;
    nums[3] = 2;
    nums[4] = 3;
    nums[5] = 2;
    nums[6] = 3;
    
    cout << "Brute Force Result: " << majorityElementBruteForce(nums) << endl;
    cout << "Map Approach Result: " << majorityElementWithMap(nums) << endl;
    cout << "Optimal Approach Result: " << majorityElementOptimal(nums) << endl;

    return 0;
}
