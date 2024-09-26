#include <string>
#include <iostream>

using namespace std;


class Solution 
{
public:
    int countSubstrings(string s) 
    {
        int nSubstrings = 0;

        for(int i = 0; i < s.size(); i++)
        {
            // odd length
            int left = i, right = i;
            while(left >= 0 && right < s.size() && s[left] == s[right])
            {
                nSubstrings++;
                left--;
                right++;
            }

            // even length
            left = i, right = i + 1;
            while(left >= 0 && right < s.size() && s[left] == s[right])
            {
                nSubstrings++;
                left--;
                right++;
            }
        }
        return nSubstrings;
    }
};


int main()
{
    string s = "abc";
    cout << "Input: " << s << endl;
    cout << "Output: " << Solution().countSubstrings(s) << endl;
    return 0;
}