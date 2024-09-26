#include <string>
#include <iostream>

using namespace std;


class Solution 
{
public:
    string longestPalindrome(string s) 
    {
        string res = "";
        int resLen = 0;

        for(int i = 0; i < s.size(); i++)
        {
            // odd length
            int left = i, right = i;
            while(left >= 0 && right < s.size() && s[left] == s[right])
            {
                if(right - left + 1 > resLen)
                {
                    res = s.substr(left, right - left + 1);
                    resLen = right - left + 1;
                }
                left--;
                right++;
            }

            // even length
            left = i, right = i + 1;
            while(left >= 0 && right < s.size() && s[left] == s[right])
            {
                if(right - left + 1 > resLen)
                {
                    res = s.substr(left, right - left + 1);
                    resLen = right - left + 1;
                }
                left--;
                right++;
            }
        }
        return res;
    }
};


int main()
{
    string s = "babad";
    cout << "Input: " << s << endl;
    cout << "Output: " << Solution().longestPalindrome(s) << endl;
    return 0;
}