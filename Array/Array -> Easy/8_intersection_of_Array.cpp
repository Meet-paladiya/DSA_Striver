#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Brute Force Approach
vector<int> intersectionBruteForce(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size();
    int n2 = nums2.size();
    vector<int> vis(n2, 0);
    vector<int> temp;

    sort(nums2.begin(), nums2.end());

    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            if (nums1[i] == nums2[j] && vis[j] == 0 && find(temp.begin(), temp.end(), nums1[i]) == temp.end()) {
                temp.push_back(nums1[i]);
                vis[j] = 1;
                break;
            }
            if (nums2[j] > nums1[i]) break; // Early exit optimization
        }
    }
    return temp;
}

// Optimal Approach using Two Pointers
vector<int> intersectionOptimal(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size();
    int n2 = nums2.size();

    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    int i = 0, j = 0;
    vector<int> ans;

    while (i < n1 && j < n2) {
        if (nums1[i] < nums2[j]) {
            i++;
        } 
        else if (nums2[j] < nums1[i]) {
            j++;
        } 
        else {
            if (ans.empty() || ans.back() != nums1[i]) { // Ensure uniqueness
                ans.push_back(nums1[i]);
            }
            i++;
            j++;
        }
    }
    return ans;
}

// Driver function
int main() {
    vector<int> nums1(4);
    nums1[0] = 1;
    nums1[1] = 2;
    nums1[2] = 2;   
    nums1[3] = 3;
    vector<int> nums2(2);
    nums2[0] = 3;
    nums2[1] = 2;

    // Using brute force method
    vector<int> resultBruteForce = intersectionBruteForce(nums1, nums2);
    cout << "Brute Force Result: ";
    for (int num : resultBruteForce) cout << num << " ";
    cout << endl;

    // Using optimal method
    vector<int> resultOptimal = intersectionOptimal(nums1, nums2);
    cout << "Optimal Result: ";
    for (int num : resultOptimal) cout << num << " ";
    cout << endl;

    return 0;
}
