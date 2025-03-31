#include<iostream>

using namespace std;

void print1(int n){
    for(int i= 0;i<n;i++){
        for(int j=0;j<=n-i-1;j++){
            cout << "*";
        }
    cout << endl;
        }
    
}
void print2(int n){
    for(int i= 1;i<=2*n-1;i++){
        int stars= i;
       if(i>n){
        stars= 2*n - i;
       }
        for(int j=1;j<=stars;j++){
            cout << "*";
            }
            cout << endl;
    //    for(int j=)
        }
}
void print3(int n){
for(int i=1;i<=5;i++){
   int start =1 ;
    if(i%2== 0){
        start = 0;

    }
}
}
void print4(int n ){
int space = 2*(n-1);

for(int i=1;i<=n;i++){
   
    for(int j=1;j<=i;j++){
        cout << j;
    }
    for(int j=1;j<=space;j++){
        cout << " ";
    }
    for(int j=i;j>=1;j--){
        cout << j;
    }
    cout << endl;
    space = space -2;
}

}
void print5(int n){
    int counter =1 ;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout << counter << " " ;
            counter++;
        }
         cout << endl;
    }
                    
}

void print6(int n) {
    for (int i = 1; i <= n; i++) {
        for (char ch = 'A'; ch <= 'A' + i - 1; ch++) {
            cout << ch << " ";
        }
        cout << endl;
    }
}

void print7(int n){

    for(int i=1;i<=n;i++){
        for(int ch='A';ch<= 'A' + i;ch++){
            cout << ch << " ";
        }
         cout << endl;
    }
                    
}

void print8(int n){
    for(int i=0;i<n;i++){
        for(char ch = 'A';ch <='A' + (n-i-1);ch++){
            cout << ch;
        }
cout << endl;
    }
}

void print9(int n){
    int initspace= 0;
for(int i=0;i<n;i++){
  
   for(int j=1;j<=n-i;j++){
       cout << "*";
   }
   for(int j=0;j<initspace;j++){
       cout << " ";
   }
   for(int j=1;j<=n-i;j++){
       cout << "*";
   }
   cout << endl;
   initspace +=2;
}
  int is=8;
for(int i=0;i<n;i++){
    for(int j=1;j<=i+1;j++){
       cout << "*";
   }
   for(int j=0;j<is;j++){
       cout << " ";
   }
   for(int j=1;j<=i+1;j++){
       cout << "*";
   }
   cout << endl;
   is -= 2;

}
}

void print10(int n){
    int initspace= 8;
for(int i=1;i<=n;i++){
  
   for(int j=1;j<=i;j++){
       cout << "*";
   }
   for(int j=0;j<initspace;j++){
       cout << " ";
   }
   for(int j=1;j<=i;j++){
       cout << "*";
   }
   cout << endl;
   initspace -=2;
}
  int is=2;
for(int i=0;i<n-1;i++){
    for(int j=1;j<n-i;j++){
       cout << "*";
   }
   for(int j=0;j<is;j++){
       cout << " ";
   }
   for(int j=1;j<n-i;j++){
       cout << "*";
   }
   cout << endl;
   is += 2;

}
}

void print11(int n){
    int spaces= 2*n -2;
    for(int i=1;i<=2*n-1;i++){
        int stars = i;
        if(i>n) stars= 2*n - i;
        for(int j=1;j<=stars;j++){
            cout << "*";
            }
            for(int j=1;j<=spaces;j++){
                cout << " ";
                }
                for(int j=1;j<=stars;j++){
                    cout << "*";
                }
                cout << endl;
               if(i<n) spaces -= 2;
                else spaces +=2;
            }
}

void print12(int n){

    for(int i=1;i<=2*n - 1;i++){
    for(int j=1;j<=2*n - 1;j++){
        int left = j;
        int top = i;
        int right = 2*n - j;
        int bottom = 2*n - i;
        //nested min 
        cout << (n - min(min(top,right),min(bottom,left)));
    }
    cout << endl;
    }
}

void print13(int n){
        for(int i=0;i<5;i++){
        for(char ch = 'A';ch <='A' + (5-i-1);ch++){
            cout << ch;
        }
cout << endl;
    }
}

void print14(int n){
        for(int i=0;i<5;i++){
        char ch = 'A'+i;
        for(char j=0;j<=i;j++){
            cout << ch << " ";
        }
cout << endl;
    }  
}

void print15(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<=n-i-1;j++){
            cout << " ";
        }
        char ch = 'A';
        int breakpoint = (2*i + 1)/2;
        for(int j=1;j<=(2*i)+1;j++){
            cout << ch;
            if(j<=breakpoint) ch++;
            else ch--;
        }
         for(int j=0;j<=n-i-1;j++){
            cout << " ";
        }
        cout << endl;
    }
    
}

void print16(int n){
    for(int i = 0; i < n; i++) {
        for(char ch = 'E' - i; ch >= 'A'; ch--) {
            cout << ch << " ";
        }
        cout << endl;
    } 
}

void print17(int n){
for(int i=0;i<n;i++){
    for(char ch='E' - i;ch <='E';ch++){
        cout << ch << " ";
    }
    cout << endl;
}
}

int main() {
cout << "1st";
    cout << "\n";

print1(5);
cout << "2 th";
cout << "\n";
print2(5);
cout << "3 th";
cout << "\n";
print3(5);
cout << "4 th";
cout << "\n";
print4(4);
cout << "5 th";
cout << "\n";
print5(5);
cout << "6 th";
cout << "\n";
print6(5);
cout << "7 th";
cout << "\n";
print7(5);
cout << "9 th";
cout << "\n";
print9(5);
cout << "11 th";
cout << "\n";
//10 and 11 are same for cp 11 is better for less no. of for loops
// print10(5);
print11(5);
cout << "12 th";
cout << "\n";
print12(5);
cout << "13 th";
cout << "\n";
print13(10);
cout << "14 th";
cout << "\n";
print14(5);
cout << "15 th";
cout << "\n";
print15(5);
cout << "16 th";
cout << "\n";
print16(5);
cout << "17 th";
cout << "\n";
print17(5);
    return 0;
}



// // Online C++ compiler to run C++ program online
// #include <iostream>
// using namespace std;
// int main() {
// //     for(int i=0;i<5;i++){
// //         for(char ch = 'A';ch <='A' + (5-i-1);ch++){
// //             cout << ch;
// //         }
// // cout << endl;
// //     }

// //     for(int i=0;i<5;i++){
// //         char ch = 'A'+i;
// //         for(char j=0;j<=i;j++){
// //             cout << ch << " ";
// //         }
// // cout << endl;
// //     }    
int n=5;


// //
// for(int i=0;i<n;i++){
//     for(char ch='E' - i;ch >='A';ch--){
//         cout << ch << " ";
//     }
//     cout << endl;
// }



// rectanle 


//     return 0;
// }