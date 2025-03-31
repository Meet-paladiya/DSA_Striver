#include <iostream>
using namespace std;
#include <vector>
#include <list>

void pairs() {
    // string m = "meet";
    // string k = "krish";
    
    // pair<int, int> p1 = {1, 2};
    // cout << p1.first << " " << p1.second << endl;  // Output: 1 2
    
    // pair<string, string> p0 = {m, k};
    // cout << p0.first << " " << p0.second << endl;  // Output: meet krish
    
    // pair<int, pair<int, int>> p2 = {1, {3, 6}};
    // cout << p2.second.first;  // Output: 3
    // cout << p2.second.second; // Output: 6
    // cout << p2.first << endl; // Output: 1  (prints 136)

    // pair<int, int> arr[] = {{2, 5}, {5, 6}};
    // cout << arr[0].first << " " << arr[0].second << endl; // Output: 2 5

    // pair<int, int> p = {2, 5};
    
    // // ✅ Fixed the issue: removed extra comma
    // pair<int, int> po[] = {{2, 5}, {4, 7}};
    // cout << po[1].second << endl; // Output: 7

    vector<int> v;
    v.push_back(1);
    v.emplace_back(2);
    
    cout << v[0] << " " << v[1] << endl << "\n";
    vector<pair<int,int>> v1;
    v1.push_back({5,6});
    v1.emplace_back(8,9);
    cout << v1[0].first << " " << v1[0].second << " " << v1[1].first<< endl;
    for(int it1s : v){
        cout << it1s << "\n";
    } ;

    vector <int> v2(5,100);
    v2.emplace_back(89);
    for(int it : v2){
        cout << it << " ";
    } ;
    cout << endl;

    vector <int> v3(5,20);
    // v3.push_back(10);   // for each loop mate pela declare karvanu
    // for(int it : v3){
    //     cout << it << " ";
    //     } ;
    //     cout << endl;
    cout << "it is v3" << "\n";
    auto it = v3.begin();

    while(it != v3.end()){ // pachal thi declare karvi to pan chale 
        cout << *it << " ";
        it++;
    }
    cout << endl;
    v3.push_back(8);

        // to copy one vector in to another 
        vector <int> v4(v3);
        // for(int it : v4){
        //     cout << it << " ";
        //     }
        vector <int> v5(7,100);
            vector<int>::iterator it1 = v5.begin();
            cout << *it1 << endl;

            cout << v4[0] << " " << v4[1] << "\n";
            cout << v4.back(); // gives last element 
//  vector<int>::iterator it  === to the      auto it

            for(auto it2 = v1.begin() ; it2!=v1.end() ;it2++ ){
                cout << it2->first << " " << it2->second << endl;
            }

            cout << " \n" << *(v2.rbegin()) << " ";
            cout << *(v2.rend()) << " "; 
            cout << *(v2.begin()) << " ";
            cout << *(v2.end()) << " \n" ; // last index ni pachina ne refer kare 
           v3.erase(v3.begin(),v3.begin() +2); // [start,end) 0 and 1 index elements are deleted 
           auto its = v3.begin();
          cout << "v3" << "\n";
        v3.insert(v3.begin(),2,500);
        while(its != v3.end()){
            cout << *its << " ";
            its++;
            }
            cout << "\n";
            
vector<int> copy(3,50);
copy.insert(copy.begin(),2,500);
for (auto itc = copy.begin(); itc != copy.end(); itc++) {
    cout << *itc << " ";
}
cout << endl;
// v3 ni starting ma copy insert thai jay
v3.insert(v3.begin(),copy.begin(),copy.end());

cout << "sixe is b" << v3.size() << "\n";
cout << (v3.empty() ? "Vector is empty" : "Vector is not empty") << endl;
v3.pop_back();
for (auto it = v3.begin(); it != v3.end(); it++) {
    cout << *it << " ";
}
// v2.swap(v3); all the vector is swapped
// v.clear(); remove all the elements
cout << v3.empty();

cout << endl;





list<int> ls;
ls.push_back(1);
ls.emplace_back(5);
ls.push_front(10);
ls.emplace_front(20);
//begin,end,rbegin,rend,clear,insert,size,swap
auto itl = ls.begin();
while(itl != ls.end()){
    cout << *itl << " ";
    itl++;
    }
    cout << "\n";
 cout << endl;
    
deque<int> dq;
dq.push_back(1);
dq.push_front(10);
dq.emplace_back(5);
dq.emplace_front(20);
//begin,end,rbegin,rend,clear,insert,size,swap
dq.pop_back();
dq.pop_front();
dq.back();
dq.front();
auto itd = dq.begin();
while(itd != dq.end()){
    cout << *itd << " ";
    it++;
    }
    cout << "\n";

}




int main() {
    pairs();
    return 0;
}
