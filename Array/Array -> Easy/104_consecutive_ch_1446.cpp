#include <iostream>
#include <algorithm> // For max()
using namespace std;

class Solution {
public:
    int maxPower(string s) {
        int n = s.size();
        int cnt = 1, maxcnt = 1; // Start from 1 since we count the first character

        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) {
                cnt++; // Increase count if same character repeats
            } else {
                cnt = 1; // Reset count when a different character appears
            }
            maxcnt = max(maxcnt, cnt); // ✅ Update maxcnt in every iteration
        }
        return maxcnt;
    }
};

int main() {
    Solution sol;
    string s = "abbcccddddeeeeedcba";
    cout << "max no. of consecutive characters of the string: " << sol.maxPower(s) << endl;
    return 0;
}
