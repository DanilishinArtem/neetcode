#include <vector>
#include <iostream>

using namespace std;



class Solution {
public:
    bool isPalindrome(string s, int l, int r){
        while(l < r){
            if(s[l] != s[r]){
                return false;
            }
            l += 1;
            r -= 1;
        }
        return true;
    }

    void dfs(string s, int i){
        if(i >= s.size()){
            result.push_back(part);
            return;
        }
        for(int j = i; j < s.size(); j++){
            if(isPalindrome(s, i, j)){
                part.push_back(s.substr(i, j - i + 1));
                dfs(s, j + 1);
                part.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        dfs(s, 0);
        return result;
    }
private:
    vector<vector<string>> result;
    vector<string> part;
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

template <typename T>
ostream& operator<<(ostream& out, const vector<vector<T>>& str){
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
    string s = "aab";
    cout << "Input: " << s << endl;
    cout << "Solution: " << Solution().partition(s) << endl;
    return 0;
}