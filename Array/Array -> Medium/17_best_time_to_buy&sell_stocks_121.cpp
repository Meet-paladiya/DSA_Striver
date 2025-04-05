#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to calculate max profit
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int miniprevprice = prices[0];
    int maxprofit = 0;
    for (int i = 1; i < n; i++) {
        int cost = prices[i] - miniprevprice; // current potential profit
        maxprofit = max(maxprofit, cost); 
        miniprevprice = min(miniprevprice, prices[i]); // update minimum buying price
    }
    return maxprofit;
}

int main() {
    vector<int> prices(6);
    prices[0] = 7;
    prices[1] = 1;
    prices[2] = 5;
    prices[3] = 3;
    prices[4] = 6;
    prices[5] = 4;

    int profit = maxProfit(prices);
    cout << "Maximum Profit: " << profit << endl;
    return 0;
}
