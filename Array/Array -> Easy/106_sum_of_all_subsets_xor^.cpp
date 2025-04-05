#include <iostream>
#include <vector>
using namespace std;

// 1️⃣ Brute Force with Backtracking
void generateSubsets(vector<int>& nums, int i, vector<int>& currSubset, vector<vector<int>>& subsets) {
    if (i == nums.size()) {
        subsets.push_back(currSubset);
        // badha currsubset add karie tyare subsets bane jema badha hoi 
// The subsets of {1, 2} are:
// subsets = [{},{1},{2},{1, 2}]
        return;
    }
    // First Recursive Call (Including the Element)
// The function first adds the current element (nums[i]) to currSubset.
// Then, it recursively calls itself with i+1, progressing to the next element while keeping nums[i] in the subset.
// Backtracking Step (Removing the Element and Trying Other Possibilities)
// After the first recursive call completes, we remove (pop_back()) the last added element.
// Now, we call the function again, moving to the next index without including the current element in the subset.
   

    // Include current number
    currSubset.push_back(nums[i]); // 1st var lidhu 
    generateSubsets(nums, i + 1, currSubset, subsets);// aagal na indx par jaie last sudhi

    // Exclude current number (backtrack)
    currSubset.pop_back(); // 1st var no subset ne currsubset ma thi remove karyu
    generateSubsets(nums, i + 1, currSubset, subsets);
}

int subsetXORSum_bruteforce(vector<int>& nums) {
    vector<vector<int>> subsets;
    vector<int> currSubset;
    generateSubsets(nums, 0, currSubset, subsets);

    int total = 0;
    for (auto& subset : subsets) {
        int Xor = 0;
        for (int num : subset) {
            Xor ^= num;
        }
        total += Xor;
    }
    return total;
}

// 2️⃣ Recursive XOR (no subsets vector)
int solveRecursive(vector<int>& nums, int i, int currXor) {
    if (i == nums.size()) return currXor;

    int include = solveRecursive(nums, i + 1, currXor ^ nums[i]); // aagal na indx par jaie last sudhi
    int exclude = solveRecursive(nums, i + 1, currXor);
    return include + exclude;
}

int subsetXORSum_recursive(vector<int>& nums) {
    return solveRecursive(nums, 0, 0);
}
// optimal one 
// The sum of all XOR totals for every subset is 480. In the code by doing the or of the all of the element 
// of array after that left shifting the N -1  element to left after adding the N -1 number of zero at the last index,
//  which is empty because of the left shift of the result 
// 3️⃣ Optimal using OR and shifting

int subsetXORSum_optimal(vector<int>& nums) {
    int result = 0;
    for (int num : nums) {
        result |= num;
    }
    return result << (nums.size() - 1);
}

// ▶️ main function
int main() {
    vector<int> nums(2);
    nums[0] = 1;
    nums[1] = 3;
    vector<int> nums1(5);
    nums1[0] = 5;
    nums1[1] = 1;
    nums1[2] = 6;  


    cout << "Test case : 1"<<endl;
    cout << "Brute Force with Backtracking: " << subsetXORSum_bruteforce(nums) << endl;
    cout << "Recursive XOR (No Backtracking): " << subsetXORSum_recursive(nums) << endl;
    cout << "Optimal Bitwise Approach: " << subsetXORSum_optimal(nums) << endl;


    cout << "Test case : 2"<<endl;
    cout << "Brute Force with Backtracking: " << subsetXORSum_bruteforce(nums1) << endl;
    cout << "Recursive XOR (No Backtracking): " << subsetXORSum_recursive(nums1) << endl;
    cout << "Optimal Bitwise Approach: " << subsetXORSum_optimal(nums1) << endl;

    return 0;
}
