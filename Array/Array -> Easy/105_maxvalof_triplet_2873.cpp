//leetcode 2873
// C++ program to find the maximum triplet value

#include <iostream>
#include <vector>

using namespace std;

long long maximumTripletValue_optimal(vector<int>& nums) {
    long long maxPrefix = 0, maxDiff = 0, maxTriplet = 0;

    for (int num : nums) {
        maxTriplet = max(maxTriplet, maxDiff * (long long)num);
        maxDiff = max(maxDiff, maxPrefix - num);
        maxPrefix = max(maxPrefix, (long long)num);
    }
    return maxTriplet;
};

long long maximumTripletValue_bruteforce(vector<int>& nums) {
    int n = nums.size();
    long long maxans = 0; // Store maximum triplet value

    for(int i = 0; i < n - 2; i++) {
        for(int j = i + 1; j < n - 1; j++) {
            for(int k = j + 1; k < n; k++) {
                long long value = (long long)(nums[i] - nums[j]) * nums[k];
                maxans = max(maxans, value);
            }
        }
    }

    return maxans < 0 ? 0 : maxans; // Return 0 if maxans is negative
};


int main() {
    vector<int> nums(3);
    nums[0] = 2;  
    nums[1] = 3; 
    nums[2] = 1;
    cout << "Maximum Triplet Value: " << maximumTripletValue_bruteforce(nums) << endl;
    vector<int> nums1(5);
    nums1[0] = 12;  
    nums1[1] = 6; 
    nums1[2] = 1;
    nums1[3] = 2; 
    nums1[4] = 7;
    cout << "Maximum Triplet Value: " << maximumTripletValue_bruteforce(nums1) << endl;
    cout << "Maximum Triplet Value: " << maximumTripletValue_optimal(nums) << endl;
    cout << "Maximum Triplet Value: " << maximumTripletValue_optimal(nums1) << endl;
    return 0;
}
