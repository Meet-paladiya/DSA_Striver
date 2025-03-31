//for only 26 elements

// #include<iostream>

// using namespace std;

// int main(){
//     string s = "abcabcdef";

//     int n = s.length();


//     int hash[26] = {0};
//     for(int i=0;i<n;i++){
//         hash[s[i] - 'a']++;
//     }

//     int x;
//     cout << "enter the no. of element you want to get freq of :";
//     cin >> x;
//    while(x--){
//     char num;
//     cin >> num;
//     cout << ":" << hash[num - 'a'] << endl;
//    }
//    return 0;
// }

// for all elements = 256
#include<iostream>

using namespace std;

int main(){
    string s = "abcabcdef";

    int n = s.length();


    int hash[256] = {0};
    for(int i=0;i<n;i++){
        hash[s[i]]++;  // s[a] = 97 so we increment the 97th index place of hash array 
    }

    int x;
    cout << "enter the no. of element you want to get freq of :";
    cin >> x;
   while(x--){
    char ch;
    cin >> ch;
    cout << ":" << hash[ch] << endl;
   }
   return 0;
}