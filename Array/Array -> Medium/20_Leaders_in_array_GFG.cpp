#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

// Brute Force Approach (O(n²))
vector<int> leaders_brute_force(vector<int>& arr) {
    vector<int> ans;
    int n = arr.size();
    for(int i = 0; i < n; i++) {
        bool leader = true;
        for(int j = i + 1; j < n; j++) {
            if(arr[j] > arr[i]) {
                leader = false;
                break;
            }
        }
        if(leader) ans.push_back(arr[i]);
    }
    return ans;
}

// Optimized Approach (O(n))
vector<int> leaders_optimized(vector<int>& arr) {
    vector<int> ans;
    int n = arr.size();
    int maxele = INT_MIN;

    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] >= maxele) {
            ans.push_back(arr[i]);
            maxele = arr[i];
        }
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    vector<int> arr(6);
    arr[0] = 16;
    arr[1] = 17;
    arr[2] = 4;
    arr[3] = 3;
    arr[4] = 5;
    arr[5] = 2;

    // Using Brute Force Approach
    vector<int> result_brute_force = leaders_brute_force(arr);
    cout << "Leaders (Brute Force): ";
    for (int i : result_brute_force) {
        cout << i << " ";
    }
    cout << endl;

    // Using Optimized Approach
    vector<int> result_optimized = leaders_optimized(arr);
    cout << "Leaders (Optimized): ";
    for (int i : result_optimized) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
