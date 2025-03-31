#include<iostream>
#include<string>
using namespace std;
// pass by refernce ma real value pan change thay 

//by value
void doSomething1(string s){
  s[1] = 'i';
  s[2] = 't';
  s[3] = ' ';
  cout << s << endl;
}


//by reference
void doSomething2(string &s){
  s[1] = 'i';
  s[2] = 't';
  s[3] = ' ';
  cout << s << endl;
}


int main() {
    // int , long , long long, float, double 
    // string and getline
    // char

//   cout << "Hello World!" <<  "good morning" << "\n";
//   int x,y;
//   cin >> x >> y;
//   cout << "You entered: " << x << " and "  << y << endl << "which is good number"<< endl;
  
//   string st;
//   getline(cin, st);
//   cout << st << endl;

//   string s1, s2;
//   cin >> s1 >> s2;
//   cout << s1 << " " << s2 << endl;
//   char ch ='g';
//   cout << ch << endl;

//   int arr[5];
//   cin >> arr[1] >> arr[2];
//   cout << arr[1] << " " << arr[2] << endl;
// int arr1[3][5];
//  arr1[1][0]= 20;
//     cout << arr1[2][4];
// string s = "meet";
// cout << s[0] << endl;

// for(int i=1;i<=10;i++){
//   cout << i <<endl ;
// }

int i=12;

// while(i<10){
//   cout << i << endl;
//   i++;
// }

//first time executes no matter what happens
do{
  cout << i << endl;
  i++;
}
while(i<10);
cout << i <<endl; 


string s = "meet";
doSomething1(s);

cout << s << endl;

doSomething2(s);

cout << s << endl;


return 0;
}

