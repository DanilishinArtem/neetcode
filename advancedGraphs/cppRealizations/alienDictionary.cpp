#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;


class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        map<char, vector<char>> adj;
        for(auto word : words){
            for(auto c : word){
                adj[c] = vector<char>();
            }
        }

        for(int i = 0; i < words.size() - 1; i++){
            string word1 = words[i];
            string word2 = words[i + 1];
            int len = min(word1.size(), word2.size());
            if(word1.size() > word2.size() && word1.substr(0, len) == word2){
                return "";
            }
            for(int j = 0; j < len; j++){
                if(word1[j] != word2[j]){
                    adj[word1[j]].push_back(word2[j]);
                    break;
                }
            }
        }
        map<char, bool> visit;
        vector<char> result;

        for(auto c : adj){
            if(dfs(c.first, adj, visit, result)){
                return "";
            }
        }
        reverse(result.begin(), result.end());
        string res = "";
        for(auto c : result){
            res += c;
        }
        return res;
    }
private:
    bool dfs(char c, map<char, vector<char>>& adj, map<char, bool>& visit, vector<char>& result){
        if(visit.find(c) != visit.end()){
            return visit[c];
        }

        visit[c] = true;
        for(char nei : adj[c]){
            if(dfs(nei, adj, visit, result)){
                return true;
            }
        }
        visit[c] = false;
        result.push_back(c);
        return false;
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
    vector<string> input = {"hrn","hrf","er","enn","rfnn"};
    cout << "Input: " << input << endl;
    cout << "Solution: " << Solution().foreignDictionary(input) << endl;
    return 0;
}