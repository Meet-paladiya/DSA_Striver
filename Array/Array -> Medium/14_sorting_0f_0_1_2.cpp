#include <iostream>
#include <vector>
using namespace std;

// Optimal Dutch National Flag Algorithm
void sortColorsOptimal(vector<int>& nums) {
    int n = nums.size();
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high) {
        if (nums[mid] == 0) {
            swap(nums[mid], nums[low]);
            mid++, low++;
        } else if (nums[mid] == 1) {
            mid++;
        } else {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

// Better Approach using Counting Sort
void sortColorsBetter(vector<int>& nums) {
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    for (int num : nums) {
        if (num == 0) cnt0++;
        else if (num == 1) cnt1++;
        else cnt2++;
    }
    
    for (int i = 0; i < cnt0; i++) nums[i] = 0;
    for (int i = cnt0; i < cnt0 + cnt1; i++) nums[i] = 1;
    for (int i = cnt0 + cnt1; i < nums.size(); i++) nums[i] = 2;
}

// Utility function to print the array
void printArray(const vector<int>& nums) {
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> nums1(7);
    nums1[0] =2;
    nums1[1] =0;
    nums1[2] =2;
    nums1[3] =1;
    nums1[4] =1;
    nums1[5] =0;
    nums1[6] = 1;
    
    vector<int> nums2 = nums1; // Copy for second function

    cout << "Original Array: ";
    printArray(nums1);
    
    sortColorsOptimal(nums1);
    cout << "Sorted using Optimal Approach: ";
    printArray(nums1);
    
    sortColorsBetter(nums2);
    cout << "Sorted using Better Approach: ";
    printArray(nums2);
    
    return 0;
}
