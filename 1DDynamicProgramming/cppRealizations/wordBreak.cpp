#include <vector>
#include <string>
#include <iostream>

using namespace std;


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp = vector<bool>(s.size() + 1, false);
        dp[s.size()] = true;
        for(int i = s.size() - 1; i >= 0; i--){
            for(auto word : wordDict){
                if(i + word.size() <= s.size() && s.substr(i, word.size()) == word){
                    dp[i] = dp[i + word.size()];
                }
                if(dp[i]){
                    break;
                }
            }
        }
        return dp[0];
    }
};


ostream& operator<<(ostream& out, const vector<string>& str){
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

    vector<string> wordDict = {"leet","code"};
    string s = "leetcode";
    cout << "Input: s = " << s << ", wordDict = " << wordDict << endl;
    cout << "Output: " << Solution().wordBreak(s, wordDict) << endl;
    return 0;
}