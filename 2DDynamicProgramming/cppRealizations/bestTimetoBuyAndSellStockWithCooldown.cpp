#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return dfs(0, true, prices, dp);
    }
private:
    int dfs(int i, bool buying, vector<int>& prices, vector<vector<int>>& dp){

        if(i >= prices.size()){
            return 0;
        }
        if(dp[i][buying] != -1){
            return dp[i][buying];
        }
        int cooldown = dfs(i+1, buying, prices, dp);
        if(buying){
            int buy = dfs(i+1, not buying, prices, dp) - prices[i];
            dp[i][buying] = max(buy, cooldown);
        }else{
            int sell = dfs(i+2, not buying, prices, dp) + prices[i];
            dp[i][buying] = max(sell, cooldown);
        }
        return dp[i][buying];
    }
};


ostream& operator<<(ostream& out, const vector<int>& str){
    out << "[";
    for(size_t i = 0; i < str.size(); i++){
        if(i < str.size() - 1){
            out << str[i] << ",";
        }else{
            out << str[i];
        }
    }
    out << "]";
    return out;
}


int main(){
    vector<int> prices = {1,2,3,0,2};
    cout << "Input: prices = " << prices << endl;
    cout << "Output: " << Solution().maxProfit(prices) << endl;
    return 0;
}