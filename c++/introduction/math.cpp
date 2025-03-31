#include <iostream>
#include <vector>
#include <algorithm> // Required for sort()

using namespace std;

// Function to print divisors of a number
void printDivisors(int n) {
    vector<int> ls;

    // Iterate from 1 to sqrt(n)
    for(int i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            ls.push_back(i);
            if((n / i) != i) { // Ensure we don't push duplicate divisors
                ls.push_back(n / i);
            }
        }
    }

    // Sort the divisors to maintain order
    sort(ls.begin(), ls.end());

    // Print the divisors
    for(int it : ls) cout << it << " ";
    cout << endl;
}
void primenum(int n){
    int cnt = 0;
    for(int i=1;i*i<=n;i++){
        if(n%i ==0) {
            cnt++;
            if( (n/i) != i){
                cnt++;
            }
        }
    }if(cnt ==2){
        cout<<"prime"<<endl;
    }
    else{
        cout<<"not prime"<<endl;
        }

}

void gcd(int a,int b){
    while(a>0 && b>0){
        if(a>b) a = a % b;
        else b = b % a;
    }
    if( a== 0) cout << (b);
    else cout << (a);
}
int main() {
    int N, dup, sum = 0, lastDigit;
    
    // Input the number for Armstrong check
    cout << "Enter a number to check if it's an Armstrong number: ";
    cin >> N;

    dup = N; // Store original number for comparison

    while (N > 0) {
        lastDigit = N % 10; // Extract last digit
        sum = sum + (lastDigit * lastDigit * lastDigit); // Cube and add to sum
        N = N / 10; // Remove last digit
    }

    // Check Armstrong condition
    if (sum == dup) {
        cout << dup << " is an Armstrong number." << endl;
    } else {
        cout << dup << " is NOT an Armstrong number." << endl;
    }

    // Input for finding divisors
    cout << "Enter a number to find its divisors: ";
    int n;
    cin >> n;

    cout << "Divisors of " << n << " are: ";
    printDivisors(n);

    cout << " enter num to find the num is prime or not:";
    int x;
    cin >> x;
    primenum(x);
    
    cout << " enter num a and b to find the gcd";
    int a;
    cout << " a is:";
    cin  >> a;

    int b;
    cout << " b is:";
    cin >> b;
    gcd(a,b);
    
    return 0;


}
