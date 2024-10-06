#include <string>
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        for(int i = 0; i < text1.size(); i++){
            for(int j = 0; j < text2.size(); j++){
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
                if(text1[i] == text2[j]){
                    dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);
                }
            }
        }
        return dp[text1.size()][text2.size()];
    }
};


int main(){
    string text1 = "abcde";
    string text2 = "ace";
    cout << "Input: text1 = " << text1 << ", text2 = " << text2 << endl;
    cout << "Result: " << Solution().longestCommonSubsequence(text1, text2) << endl;
    return 0;
}