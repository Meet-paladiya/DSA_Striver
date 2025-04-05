#include <iostream>
#include <vector>
using namespace std;


    // Function 1: Handles zeroes separately
    vector<int> rearrangeArrayWithZeros(vector<int>& nums) {
        int n = nums.size();
        vector<int> neg, pos;
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (nums[i] < 0) {
                neg.push_back(nums[i]);
            } else if (nums[i] > 0) {
                pos.push_back(nums[i]);
            } else {
                ans.push_back(nums[i]); // handle zeroes separately
            }
        }

        for (int i = 0; i < pos.size(); i++) { // whatever the pos size is equal to neg arr size
            ans.push_back(pos[i]);
            ans.push_back(neg[i]);
        }

        return ans;
    }

    // Function 2: No zeroes; alternate +ve and -ve at even-odd indices
    vector<int> rearrangeArrayNoZeros(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        int posindx = 0, negindx = 1;

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                ans[posindx] = nums[i];
                posindx += 2;
            } else if (nums[i] < 0) {
                ans[negindx] = nums[i];
                negindx += 2;
            }
        }
        return ans;
    };

int main() {

    // Example 1: No zeroes
    vector<int> nums1(6);
    nums1[0] = 3;
    nums1[1] = 1;
    nums1[2] = -2;
    nums1[3] = -5;
    nums1[4] = 2;
    nums1[5] = -4;

    vector<int> result1 = rearrangeArrayNoZeros(nums1);
    cout << "Rearranged (No Zeroes): ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    // Example 2: With zeroes (not truly handled well here, just included for reference)
    vector<int> nums2(6);
    nums2[0] = 8;
    nums2[1] = 3;
    nums2[2] = -1;
    nums2[3] = 0;
    nums2[4] = 2;
    nums2[5] = 9;

    vector<int> result2 = rearrangeArrayWithZeros(nums2);
    cout << "Rearranged (With Zeroes Handling): ";
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
