#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int profit = 0;
        for(int price : prices){
            minPrice = min(minPrice, price);
            profit = max(profit, price - minPrice);
        }
        return profit;
    }
};


int main(){
    vector<int> prices = {7,1,5,3,6,4};
    cout << Solution().maxProfit(prices) << endl;
    return 0;
}