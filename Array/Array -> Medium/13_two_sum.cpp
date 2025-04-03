#include <vector>
#include <map>
#include <algorithm> // For sort()
#include <iostream>
using namespace std;

// Brute force approach
vector<int> twoSumBruteForce(vector<int>& nums, int target) {
    int n = nums.size();
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(nums[i] + nums[j] == target) {
                return vector<int>(i, j); // Corrected here
            }
        }
    }
    return vector<int>(0, 0); 
}

// Better approach using map
vector<int> twoSumWithMap(vector<int>& nums, int target) {
    map<int, int> mpp;
    int n = nums.size();
    for(int i = 0; i < n; i++) {
        int num = nums[i];
        int more_needed = target - num;
        if(mpp.find(more_needed) != mpp.end()) {
            return vector<int>(mpp[more_needed], i);
        }
        mpp[num] = i;   // If more_needed isn't found, store num in mpp with its index (i).
    }
    return vector<int>(); 
}

// Optimal but only works for sorted array 
// For unsorted array we have to use this kind of cause first we have to store indexes of the elements after 
// have to apply below approach
// without map  
// not for unsorted array

// two pointers approach
vector<int> twoSumSorted(vector<int>& nums, int target) {
    int n = nums.size();
    int l = 0, r = n - 1;
    for(int i = 0; i < n; i++) {
        if(nums[l] + nums[r] == target) {
            return vector<int>(l, r); 
        }
        else if(nums[l] + nums[r] > target) {
            r--;
        }
        else {
            l++;
        }
    }
    return vector<int>();
}

// Main function to call all three approaches
int main() {
    vector<int> nums(4);
    nums[0] = 2;
    nums[1] = 7;
    nums[2] = 11;
    nums[3] = 15;
    int target = 9;

    vector<int> resultBrute = twoSumBruteForce(nums, target);
    vector<int> resultMap = twoSumWithMap(nums, target);

    // Sorting array before calling twoSumSorted
    vector<int> sortedNums = nums;  
    sort(sortedNums.begin(), sortedNums.end());
    vector<int> resultSorted = twoSumSorted(sortedNums, target);

    // Output results
    cout << "Brute Force Result: [" << resultBrute[0] << ", " << resultBrute[1] << "]" << endl;
    cout << "Map Approach Result: [" << resultMap[0] << ", " << resultMap[1] << "]" << endl;
    cout << "Sorted Array Approach Result: [" << resultSorted[0] << ", " << resultSorted[1] << "]" << endl;

    return 0;
}
