#include <iostream>
#include <vector>
#include <set>
using namespace std;

int removeDuplicates_bruteforce(vector<int>& nums) {
    set<int> st;
    int n = nums.size();
    for(int num : nums){
        st.insert(num);
    }
    int index=0;
    for(int num : st){
        nums[index++] = num;
    }
    nums.resize(index);
    return index;
}

    int removeDuplicates_optimal(vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        if (n == 0) return 0;

        // Start from the second element (index 1)
        for (int j = 1; j < n; j++) {
            if (nums[i] != nums[j]) {
                nums[++i] = nums[j]; // Move the unique element to the next position
            }
        }

        return i + 1; // Return the number of unique elements
    
};


int main() {
     // Test Case 1: Brute-force method
     vector<int> nums1(7);
    nums1[0] = 1; 
    nums1[1] = 1; 
    nums1[2] = 2;
    nums1[3] = 2; 
    nums1[4] = 2; 
    nums1[5] = 3; 
    nums1[6] = 3; 
   
     int result1 = removeDuplicates_bruteforce(nums1);
     cout << "Brute-force: Number of unique elements: " << result1 << endl;
     cout << "Array after removing duplicates: ";
     for (int i = 0; i < result1; i++) {
         cout << nums1[i] << " ";
     }
     cout << endl;
 
     // Test Case 2
    vector<int> nums2(10); 
    nums2[0] = 0; 
    nums2[1] = 0; 
    nums2[2] = 1; 
    nums2[3] = 1; 
    nums2[4] = 1; 
    nums2[5] = 2; 
    nums2[6] = 2; 
    nums2[7] = 3; 
    nums2[8] = 3; 
    nums2[9] = 4; 
     int result2 = removeDuplicates_optimal(nums2);
     cout << "Optimal: Number of unique elements: " << result2 << endl;
     cout << "Array after removing duplicates: ";
     for (int i = 0; i < result2; i++) {
         cout << nums2[i] << " ";
     }
     cout << endl;
 
     return 0;
}