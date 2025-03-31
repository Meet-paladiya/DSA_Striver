#include<iostream>
#include<vector>
using namespace std;


int brute_force(int arr[],int n){
    sort(arr,arr+n);
    int largest = arr[n-1];
    int slargest = -1;
    for(int i= n-2; i>=0; i--){
        if(arr[i] != largest){
            slargest = arr[i];
            break;
        }
    }
    return slargest;
}


int better_force(int arr[],int n){
    int largest = arr[0];
    for(int i=1; i<n; i++){
        if(arr[i]>largest){
            largest = arr[i];
        }
    }
    int slargest = -1;
    for(int i=0; i<n; i++){
        if(arr[i] > slargest && arr[i] != largest){
            slargest = arr[i];
        }
    }
    return slargest;
}


int optimal_force(int arr[],int n){
    int largest = arr[0];
    int slargest = -1;
   for(int i=1; i<n; i++){
    if(arr[i]>largest){
        slargest = largest;
        largest = arr[i];
    }
    else if(arr[i]>slargest && arr[i] < largest){
        slargest = arr[i];
    }
   }
   return slargest;
}

pair<int,int> ssmallest_optimal_force(int arr[],int n){
    int smallest = arr[0];
    int ssmallest = INT_MAX; // Start with the largest possible value

    for (int i = 1; i < n; i++) {
        if (arr[i] < smallest) {
            ssmallest = smallest; // Update second smallest before changing smallest
            smallest = arr[i];
        } 
        else if (arr[i] > smallest && arr[i] < ssmallest) {
            ssmallest = arr[i]; // Update second smallest if it's larger than the smallest
        }
    }
    if (ssmallest == INT_MAX) ssmallest = -1;

    return make_pair(smallest, ssmallest); // Return both as a pair
}


int main(){
    int arr[5] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "slargest using Brute Force: " << brute_force(arr, n) << endl;
    cout << "slargest using Better Force: " << better_force(arr, n) << endl;
    cout << "slargest using Optimal Approach: " << optimal_force(arr, n) << endl;
    pair<int, int> result = ssmallest_optimal_force(arr, n);
 // extra
    cout << "Smallest: " << result.first << endl;
    cout << "Second Smallest: " << result.second << endl;

 
    return 0;
}

// in case of array has negative number, we have to consider as Slargest= INT_MIN
// Brute Force (sort) → O(n log n) due to sorting.
// Better Force (traversal) → O(n) since it scans the array 2 times.
// Optimal Approach (traversal) → O(n) since it scans the array once.