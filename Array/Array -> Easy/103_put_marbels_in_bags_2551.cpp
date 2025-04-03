// Input:
// cpp
// Copy
// Edit
// weights = {1, 4, 2, 5, 2};
// k = 3;
// Step 1: Compute Pair Sums
// Pairs	Sum
// (1,4) → 1+4	5
// (4,2) → 4+2	6
// (2,5) → 2+5	7
// (5,2) → 5+2	7
// pairsum = [5, 6, 7, 7]


// Step 2: Sort pairsum
// cpp
// Copy
// Edit
// [5, 6, 7, 7]
// (Sorted order)


// Step 3: Compute minSum and maxSum
// Since k = 3, we pick k-1 = 2 smallest and largest elements.

// minSum → Sum of smallest 2 elements → 5 + 6 = 11
// maxSum → Sum of largest 2 elements → 7 + 7 = 14

// Step 4: Compute the Result
// cpp
// Copy
// Edit
// maxSum - minSum = 14 - 11 = 3
// ✔ Final Output: 3 ✅

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long putMarbles(vector<int>& weights, int k) {
    int n = weights.size();
    int m = n - 1;

    vector<long long> pairsum(m, 0);

    // Compute adjacent pair sums
    for (int i = 0; i < m; i++) {
        pairsum[i] = (long long)weights[i] + weights[i + 1];
    }

    // Sort the pair sums
    sort(pairsum.begin(), pairsum.end());

    // Compute minSum and maxSum
    long long minSum = 0, maxSum = 0;
    for (int i = 0; i < k - 1; i++) {
        minSum += pairsum[i];         // Sum of smallest k-1 pairs
        maxSum += pairsum[m - 1 - i]; // Sum of largest k-1 pairs
    }

    return maxSum - minSum;
}

int main() {
    int n, k;
    
    // Take user input
    cout << "Enter the number of marbles: ";
    cin >> n;
    
    vector<int> weights(n);
    cout << "Enter the weights of marbles: ";
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }
    
    cout << "Enter the number of groups (k): ";
    cin >> k;
    
    // Call function and display output
    long long result = putMarbles(weights, k);
    cout << "Max-Min Difference: " << result << endl;

    return 0;
}
