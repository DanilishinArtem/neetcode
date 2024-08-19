#include <vector>
#include <iostream>

using namespace std;



class Solution {
public:
    bool checkValidString(string s) {
        int leftMin = 0;
        int leftMax = 0;
        for(auto c : s){
            if(c == '('){
                leftMin += 1;
                leftMax += 1;                
            }else if(c == ')'){
                leftMin -= 1;
                leftMax -= 1;
            }else if(c == '*'){
                leftMin -= 1;
                leftMax += 1;
            }
            if(leftMax < 0){
                return false;
            }
            if(leftMin < 0){
                leftMin = 0;
            }
        }
        return leftMin == 0;
    }
};



int main(){
    string s="(((((*(()((((*((**(((()()*)()()()*((((**)())*)*)))))))(())(()))())((*()()(((()((()*(())*(()**)()(())";
    cout << "Input:" << endl;
    cout << s << endl;
    cout << "Solution:" << endl;
    bool result = Solution().checkValidString(s);
    cout << result << endl;
    return 0;
}