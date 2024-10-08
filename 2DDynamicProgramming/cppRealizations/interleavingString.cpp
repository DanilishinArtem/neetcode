#include <string>
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }
        int n = s1.size(), m = s2.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[n][m] = true;
        for(int i = n; i >= 0; i--){
            for(int j = m; j >= 0; j--){
                if(i < n && s1[i] == s3[i + j] && dp[i + 1][j]){
                    dp[i][j] = true;
                }
                if(j < m && s2[j] == s3[i + j] && dp[i][j + 1]){
                    dp[i][j] = true;
                }
            }
        }
        return dp[0][0];
    }
};


int main(){
    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbcbcac";
    cout << "Input: " << s1 << ", " << s2 << ", " << s3 << endl;
    cout << "Output: " << Solution().isInterleave(s1, s2, s3) << endl;
    return 0;
}