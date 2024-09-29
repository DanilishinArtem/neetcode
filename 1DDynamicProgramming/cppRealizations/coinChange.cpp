#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;



class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for(int i = 1; i <= amount; i++)
        {
            for(int j = 0; j < coins.size(); j++)
            {
                if(coins[j] <= i)
                {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
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


int main()
{
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    cout << "Input: coins = " << coins << ", amount = " << amount << endl;
    cout << "Output: " << endl;
    cout << Solution().coinChange(coins, amount) << endl;
    return 0;
}