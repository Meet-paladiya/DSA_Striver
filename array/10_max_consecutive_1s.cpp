#include <iostream>
#include <vector>
#include <algorithm> // For max() function

using namespace std;


    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0, maxcnt = 0;
        
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                cnt++;
                maxcnt = max(maxcnt, cnt);
            } else {
                cnt = 0;
            }
        }
        return maxcnt;
    
};

int main() {
    vector<int> nums(7);
    nums[0] =1;
    nums[1] =1;
    nums[2] =0;
    nums[3] =1;
    nums[4] =1;
    nums[5] =1;
    nums[6] =1;

    int result = findMaxConsecutiveOnes(nums);

    cout << "Maximum consecutive ones: " << result << endl;
    return 0;
}
