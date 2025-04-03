#include <iostream>
#include <vector>
#include <set>
using namespace std;

// Optimal approach: Using two-pointer technique (O(n1 + n2))
vector<int> findUnionOptimal(vector<int> &a, vector<int> &b) {
    int n1 = a.size();
    int n2 = b.size();
    int i = 0, j = 0;
    vector<int> unionArr;

    // Merge two sorted arrays
    while (i < n1 && j < n2) {
        if (a[i] <= b[j]) {
            if (unionArr.empty() || unionArr.back() != a[i]) {
                unionArr.push_back(a[i]);
            }
            i++;
        } else {
            if (unionArr.empty() || unionArr.back() != b[j]) {
                unionArr.push_back(b[j]);
            }
            j++;
        }
    }

    // Insert remaining elements from 'a'
    while (i < n1) {
        if (unionArr.empty() || unionArr.back() != a[i]) {
            unionArr.push_back(a[i]);
        }
        i++;
    }

    // Insert remaining elements from 'b'
    while (j < n2) {
        if (unionArr.empty() || unionArr.back() != b[j]) {
            unionArr.push_back(b[j]);
        }
        j++;
    }

    return unionArr;
}

// Brute force approach: Using set (O(n log n))
vector<int> findUnionBruteForce(vector<int> &a, vector<int> &b) {
    set<int> st;
    
    // Insert elements from both arrays into a set
    for (int num : a) {
        st.insert(num);
    }
    for (int num : b) {
        st.insert(num);
    }
    
    // Convert set to vector
    return vector<int>(st.begin(), st.end());
}

int main() {
    vector<int> a(5);
    a[0] = 1;
    a[1] = 2;
    a[2] = 2;
    a[3] = 3;
    a[4] = 4;

    vector<int> b(4);
    b[0] = 2;
    b[1] = 3;
    b[2] = 5;
    b[3] = 6;
    // Optimal approach
    vector<int> resultOptimal = findUnionOptimal(a, b);
    cout << "Optimal Union: ";
    for (int num : resultOptimal) {
        cout << num << " ";
    }
    cout << endl;

    // Brute force approach
    vector<int> resultBrute = findUnionBruteForce(a, b);
    cout << "Brute Force Union: ";
    for (int num : resultBrute) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
