#include<iostream>
#include<vector>
using namespace std;


int brute_force(int arr[],int n){
    sort(arr,arr+n);
    return arr[n-1];
}


int optimal_force(int arr[],int n){
    int max = arr[0];
    for(int i=1; i<n; i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    return max;
}

int main(){
    // int arr[5] = {1, 2, 3, 4, 5};
    int arr[5] = {1, 2, 3, 4, 5};

    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Max using Brute Force: " << brute_force(arr, n) << endl;
    cout << "Max using Optimal Approach: " << optimal_force(arr, n) << endl;
 
    return 0;
}

// Brute Force (sort) → O(n log n) due to sorting.

// Optimal Approach (traversal) → O(n) since it scans the array once.