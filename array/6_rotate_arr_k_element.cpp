#include <iostream>
#include <vector>
using namespace std;

void rotateLeft(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n; // Handle cases where k > n

    vector<int> temp(k);
    for (int i = 0; i < k; i++) {
        temp[i] = nums[i];
    }
    
    for (int i = 0; i < n - k; i++) {
        nums[i] = nums[i + k];
    }
    
    for (int i = 0; i < k; i++) {
        nums[n - k + i] = temp[i];
    }
}

void rotateRight(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;

    vector<int> temp(k);
    for (int i = 0; i < k; i++) {
        temp[i] = nums[n - k + i];
    }
    
    for (int i = n - k - 1; i >= 0; i--) {
        nums[i + k] = nums[i];
    }
    
    for (int i = 0; i < k; i++) {
        nums[i] = temp[i];
    }
}

int main() {
    int n, k, choice;
    
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> nums(n);
    
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    cout << "Enter the value of k (shift positions): ";
    cin >> k;

        rotateLeft(nums, k);
        cout << "Left rotated array: ";
        for (int num : nums) {
            cout << num << " ";
        }
        cout << endl;

    rotateRight(nums, k);
    cout << "Right rotated array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
