// Problem: Find the missing number in an array containing n distinct numbers taken from 0, 1, 2, ..., n.
#include <iostream>
#include <vector>
using namespace std;

// Brute Force Approach - O(n^2) Time, O(1) Space
int missingNumberBruteForce(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i <= n; i++) {
        int flag = 0;
        for (int j = 0; j < n; j++) {
            if (nums[j] == i) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            return i;
        }
    }
    return -1;
}

// Better Approach - O(n) Time, O(n) Space (extra frequency array)
int missingNumberBetter(vector<int>& nums) {
    int n = nums.size();
    vector<int> freq(n + 1, 0); // Frequency array initialized to 0
    
    // First loop: Count the occurrences of numbers in nums
    for (int i = 0; i < n; i++) {
        freq[nums[i]]++;
    }
    
    // Second loop: Find the missing number
    for (int i = 0; i <= n; i++) {
        if (freq[i] == 0) {
            return i;
        }
    }
    return -1;
}

// Better Approach - O(n) Time, O(1) Space (using sum formula)
int missingNumberSum(vector<int>& nums) {
    int n = nums.size();
    long long sum = (long long)n * (n + 1) / 2; // Sum of first n natural numbers
    long long actualSum = 0;
    
    // Compute the sum of elements in nums
    for (int i = 0; i < n; i++) {
        actualSum += nums[i];
    }
    
    return sum - actualSum; // The missing number
}

// Optimal Approach - O(n) Time, O(1) Space (using XOR)
int missingNumberOptimal(vector<int>& nums) {
    int n = nums.size();
    int xor1 = 0, xor2 = 0;
    
    // Compute XOR of numbers from 1 to n and actual elements in nums
    for (int i = 0; i < n; i++) {
        xor1 = xor1 ^ (i + 1); // XOR of numbers 1 to n
        xor2 = xor2 ^ nums[i]; // XOR of elements in nums
    }
    
    return xor1 ^ xor2; // The missing number
}

// Main function to test the implementations
int main() {
    cout <<  "Test case: 1"<< endl;
    vector<int> nums(2);
    nums[0] = 0; 
    nums[1] = 1;
    cout << "Test case: 2"<< endl;
    vector<int> nums3(4);
    nums3[0] = 0;
    nums3[1] = 1;
    nums3[2] = 2;
    nums3[3] = 4;


    
    cout << "Brute Force: " << missingNumberBruteForce(nums) << endl;
    cout << "Better Approach (Frequency Array): " << missingNumberBetter(nums) << endl;
    cout << "Better Approach (Sum Formula): " << missingNumberSum(nums) << endl;
    cout << "Optimal Approach (XOR): " << missingNumberOptimal(nums) << endl;

    cout << "Brute Force: " << missingNumberBruteForce(nums3) << endl;
    cout << "Better Approach (Frequency Array): " << missingNumberBetter(nums3) << endl;
    cout << "Better Approach (Sum Formula): " << missingNumberSum(nums3) << endl;
    cout << "Optimal Approach (XOR): " << missingNumberOptimal(nums3) << endl;
    
    return 0;
}
