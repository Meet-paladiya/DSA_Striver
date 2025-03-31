#include <iostream>
#include <vector>

using namespace std;

vector<int> applyOperations(vector<int>& nums) {
    int i = 0;

    // First pass: Double adjacent equal elements and set the next one to 0
    for (int j = 0; j < nums.size() - 1; j++) {
        if (nums[j] == nums[j + 1]) {
            nums[j] *= 2;
            nums[j + 1] = 0;
        }
    }

    // Second pass: Move non-zero elements to the front
    for (int j = 0; j < nums.size(); j++) {
        if (nums[j] != 0) {
            nums[i++] = nums[j];
        }
    }

    // Third pass: Fill the remaining elements with zeros
    for (int x = i; x < nums.size(); x++) {
        nums[x] = 0;
    }

    return nums;
}

int main() {
    vector<int> nums(6);
    nums[0] = 2; 
    nums[1] = 2;
    nums[2] = 0;
    nums[3] = 4;
    nums[4] = 4;
    nums[5] = 8;

    cout << "Before applying operations: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> result = applyOperations(nums);

    cout << "After applying operations: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
