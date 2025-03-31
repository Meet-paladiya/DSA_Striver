#include<iostream>
#include<math.h>
using namespace std;

void print(int i,int n){
    if(i>n){
        return;
    }
    cout << "hello meet" << endl;
    print(i+1,n);
 
}

bool isPalindrome(int x) {
    if(x<0){
        return false;
    }
    int n = x;
    long long reverse = 0;
    while(n>0){
        int digit = n%10;
        reverse = (reverse*10) + digit;
        n = n/10;
    }
    return reverse == x;
}

void printnum(int i,int n){
 
    if(i>n){
        return;
    }
    printnum(i+1,n);
    cout << i;
    
}

void sumofnum(int n,int sum = 0){
    if(n<1){
        cout << sum ;
        return;
    }
    else sumofnum(n-1,sum+n);
}
// functional recursion which not prints it returns something
// int sumofnum(int n){
//     if(n==0){
//         return 0;
//     }
//     else return n+sumofnum(n-1);
// }

void reversearr(int arr[],int n,int i=0){
if(i>n/2){
    return;
}
swap(arr[i],arr[n-i-1]);
reversearr(arr,n,i+1);
}

void revstr(string s,int l,int i=0){
if(s.length() == 0){
    return;
    if(i>l/2){
        return;
    }
    revstr(s,l,i+1);
}

}

int  fibo(int x){
if(x<=1){
    return x;
}
 int last = fibo(x-1);
 int slast = fibo(x-2);
 return last+slast;
}

int main()
{
    int n;
    cout<<"Enter the number to print the statement :";
    cin>>n;
    print(1,n);
    printnum(1,n);

    cout << "sum of n number is :";  
    // for functional 
    // cout << sumofnum(n);
    // for parameterized
    // sumofnum(n);
    // int x ;
    // cout  <<  "enter the size of the array : "; 
    // cin >> x;

    // int arr[x];

    // cout << "enter the elements of the array : ";
    // for(int i = 0 ; i < x ; i++){
    //     cin >> arr[i];
    //     }
    // reversearr(arr,x);

    // cout << "reversed array : ";
    // for(int i = 0 ; i < x ; i++){
    //     cout << arr[i] << " ";
    //     }



//     string s = "madam";
// int l = s.length();
//  revstr(s,l);
//  cout << "reversed string is :"<< s << endl;
//     if(s == string(s.rbegin(),s.rend())){
//         cout << "palindrome";
//     }
//     else{
//         cout << "not palindrome";
//         }

int y;
    cout << endl << "Enter the index of the Fibonacci element that you want: ";
    cin >> y;

    int result = fibo(y);
    cout << "Fibonacci number at index " << y << " is: " << result << endl;

    isPalindrome(121) ? cout << "Palindrome" : cout << "Not Palindrome";
        return 0;
}