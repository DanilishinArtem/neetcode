#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;

        for(int i = coins.size() - 1; i >= 0; i--){
            vector<int> nextDP(amount + 1, 0);
            nextDP[0] = 1;

            for(int a = 1; a <= amount; a++){
                nextDP[a] = dp[a];
                if(a - coins[i] >= 0){
                    nextDP[a] += nextDP[a - coins[i]];
                }
            }
            dp = nextDP;
        }
        return dp[amount];
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
    vector<int> coins = {1, 2, 5};
    cout << "Input: coins = " << coins << endl;
    cout << "Output: " << Solution().change(5, coins) << endl;
    return 0;
}