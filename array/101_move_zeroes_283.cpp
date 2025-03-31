#include <iostream>
#include <vector>

using namespace std;

void moveZeroes(vector<int>& nums) {
    int n = nums.size();
    int i = 0;

    // First pass: Move non-zero elements to the front
    for (int j = 0; j < n; j++) {
        if (nums[j] != 0) {
            nums[i++] = nums[j]; // Place non-zero element at index i
        }
    }

    // Second pass: Fill the remaining elements with zeros
    for (int x = i; x < n; x++) {
        nums[x] = 0; // Fill the rest of the array with zeros
    }
}

int main() {
    vector<int> nums(5);
    nums[0] = 0;
    nums[1] = 1;
    nums[2] = 0;
    nums[3] = 3;
    nums[4] = 12;


    cout << "Before moving zeroes: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    moveZeroes(nums);

    cout << "After moving zeroes: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
