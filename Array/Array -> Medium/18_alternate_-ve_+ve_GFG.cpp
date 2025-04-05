#include <iostream>
#include <vector>
using namespace std;
 // putting remaining element at the end of the array
// 1. Split the array into two vectors: one for positive numbers and one for negative numbers.
// 2. Use two pointers to iterate through both vectors and fill the original array in an alternating fashion.
// 3. If there are remaining elements in either vector, append them to the end of the original array.
// 4. The time complexity is O(n) and space complexity is O(n) due to the use of additional vectors.

class Solution {
public:
    void rearrange(vector<int>& arr) {
        vector<int> neg, pos;
        int n = arr.size();

        // Split array into positive and negative vectors
        for (int i = 0; i < n; i++) {
            if (arr[i] < 0)
                neg.push_back(arr[i]);
            else
                pos.push_back(arr[i]);
        }

        int possize = pos.size();
        int negsize = neg.size();
        int i = 0, j = 0, k = 0;

        // Alternately add positive and negative numbers starting with positive
        while (i < possize && j < negsize) {
            arr[k++] = pos[i++];
            arr[k++] = neg[j++];
        }

        // Add remaining positives
        while (i < possize) {
            arr[k++] = pos[i++];
        }

        // Add remaining negatives
        while (j < negsize) {
            arr[k++] = neg[j++];
        }
    }
};

int main() {
    Solution sol;

    vector<int> arr(10);
    arr[0] = 1; arr[1] = 2; arr[2] = 3; arr[3] = 4; arr[4] = 5;
    arr[5] = 2; arr[6] = 3; arr[7] = -4; arr[8] = -1; arr[9] = 4;

    cout << "Original array: ";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;

    sol.rearrange(arr);  // Call the rearrange function

    cout << "Rearranged array: ";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
