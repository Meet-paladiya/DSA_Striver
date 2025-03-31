#include<iostream>
#include<cmath>

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
    int hash[13] ={0};
    for(int i=0;i<n;i++){
        hash[a[i]]++;
    }


    int q;
    cout << "enter the number of elements of which you want to find the frequencies of :";
    cin >> q;
    while(q--){
        int x;
        cin >> x;
        //fetch
        cout << "freq of number " << x <<  " is: " << hash[x] << endl;
    }
            return 0;

    
}
//inside main only 10 to power 6.   for bool 7
// if globel 10 to power 7.     for bool 8