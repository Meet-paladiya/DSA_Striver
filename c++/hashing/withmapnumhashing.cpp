#include<iostream>
#include<cmath>
#include <map>
using namespace std;
int main(){
    int n;
    cout << "enter the size of the array:";
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cout << "enter the element at index " << i+1 << ":";
        cin >> a[i];
    }
    //precompute
     // key value pair
     // key = num 
    //  value = freq
  unordered_map<int,int> mpp ;
  for(int i=0;i<n;i++){
    mpp[a[i]]++;
    }

    for(auto it : mpp){
        cout << it.first << "->" << it.second << endl;
    }

    int q;
    cout << "enter the number of elements of which you want to find the frequencies of :";
    cin >> q;
    while(q--){
        int x;
        cin >> x;
        //fetch
        cout << "freq of number " << x <<  " is: " << mpp[x] << endl;
    }

            int minFreq = INT_MAX, maxFreq = INT_MIN;
            int minFreqNum, maxFreqNum;
        
            for (auto it : mpp) {
                if (it.second > maxFreq) {
                    maxFreq = it.second;
                    maxFreqNum = it.first;
                }
                if (it.second < minFreq) {
                    minFreq = it.second;
                    minFreqNum = it.first;
                }
            }
        
            cout << "\nNumber with the highest frequency: " << maxFreqNum << " (Frequency: " << maxFreq << ")\n";
            cout << "Number with the lowest frequency: " << minFreqNum << " (Frequency: " << minFreq << ")\n";

            
            return 0;   

}
//     enter the size of the array:5
// enter the element at index 1:1
// enter the element at index 2:2
// enter the element at index 3:1
// enter the element at index 4:4
// enter the element at index 5:100
// 1->2
// 2->1
// 4->1
// 100->1
