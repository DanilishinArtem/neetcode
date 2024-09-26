#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;


class Solution 
{
public:
    int numDecodings(string s) 
    {
        map<int, int> dp;
        dp[s.size()] = 1;
        for(int i = s.size() - 1; i >= 0; i--)
        {
            if(s[i] == '0')
            {
                dp[i] = 0;
            }
            else
            {
                dp[i] = dp[i + 1];
            }
            if(i + 1 < s.size() && (s[i] == '1' || (s[i] == '2' && s[i + 1] >= '1' && s[i + 1] <= '6')))
            {
                dp[i] += dp[i + 2];
            }        
        }
        return dp[0];
    }
};


int main()
{
    string s = "111111111111111111111111111111111111111111111";
    cout << "Input: " << s << endl;
    cout << "Output: " << Solution().numDecodings(s) << endl;
    return 0;
}