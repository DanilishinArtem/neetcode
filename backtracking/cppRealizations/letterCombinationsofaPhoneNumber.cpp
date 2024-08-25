#include <vector>
#include <iostream>
#include <map>
using namespace std;



class Solution {
public:
    void backtrack(int i, string curStr, string digits){
        if(curStr.size() == digits.size()){
            result.push_back(curStr);
            return;
        }
        for(auto c : key[digits[i] - '2'].second){
            backtrack(i + 1, curStr + c, digits);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() != 0){
            backtrack(0, "", digits);
        }
        return result;
    }
private:
    pair<string, string> key[8] = {{"2", "abc"}, {"3", "def"}, {"4", "ghi"}, {"5", "jkl"}, {"6", "mno"}, {"7", "pqrs"}, {"8", "tuv"}, {"9", "wxyz"}};
    vector<string> result;
};


template <typename T>
ostream& operator<<(ostream& out, const vector<T>& str){
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
    string s = "23";
    cout << "Input: " << s << endl;
    cout << "Solution: " << Solution().letterCombinations(s) << endl;
    return 0;
}