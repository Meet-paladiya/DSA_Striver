#include <iostream>
#include <vector>
using namespace std;

// Function to check if the array is sorted and rotated
bool isSortedAndRotated(vector<int>& nums) {
    int n = nums.size();
    int count = 0; 

    for (int i = 0; i < n; i++) {
        if (nums[i] > nums[(i + 1) % n]) {  // jyare n=5 tyare arr[4+1 % 5 ==0 ]
            //aetle arr no last firest sathe pan compare thai jay 
            count++;
        }
        if (count > 1) return false; // More than one break → not a rotated sorted array
    }
    return true; 
}

// Function to take user input and call `isSortedAndRotated`
void checkArray() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    bool result = isSortedAndRotated(nums);
    cout << "Is the array sorted and rotated? " << (result ? "Yes" : "No") << endl;
}

// Main function to execute the program
int main() {
    checkArray();
    return 0;
}
