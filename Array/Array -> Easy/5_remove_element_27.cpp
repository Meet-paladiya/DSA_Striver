#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int>& nums, int val) {
    int i = 0;
    for (int j = 0; j < nums.size(); j++) {
        if (nums[j] != val) {
            nums[i++] = nums[j];
        }
    }
    return i;
}

int main() {
    vector<int> nums(7);
    nums[0] = 3;
    nums[1] = 2;
    nums[2] = 2;
    nums[3] = 3;
    nums[4] = 4;
    nums[5] = 3;
    nums[6] = 5;

    int val = 3; // Value to remove

    int newSize = removeElement(nums, val);

    cout << "Array after removing " << val << ": ";
    for (int i = 0; i < newSize; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    cout << "Number of elements after removal: " << newSize << endl;

    return 0;
}
