#include <map>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <iostream>
#include <algorithm>


using namespace std;


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(find(wordList.begin(), wordList.end(), endWord) == wordList.end()){
            return 0;
        }
        
        map<string, vector<string>> nei;
        wordList.push_back(beginWord);
        for(auto word : wordList){
            for(int j = 0; j < word.size(); j++){
                string pattern = word.substr(0, j) + "*" + word.substr(j + 1);
                nei[pattern].push_back(word);
            }
        }

        set<string> visited;
        queue<string> q;
        q.push(beginWord);
        visited.insert(beginWord);
        int res = 1;

        while(!q.empty()){
            int levelSize = q.size();
            for(int i = 0; i < levelSize; i++){
                string word = q.front();
                q.pop();
                if(word == endWord){
                    return res;
                }
                for(int j = 0; j < word.size(); j++){
                    string pattern = word.substr(0, j) + "*" + word.substr(j + 1);
                    for(auto neiWord : nei[pattern]){
                        if(visited.find(neiWord) == visited.end()){
                            q.push(neiWord);
                            visited.insert(neiWord);
                        }
                    }
                }
            }
            res += 1;
        }
        return 0;
    }
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
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    string beginWord = "hit";
    string endWord = "cog";
    cout << "Input: beginWord = " << beginWord << ", endWord = " << endWord << ", wordList = " << wordList << endl;
    cout << "Output: " << Solution().ladderLength(beginWord, endWord, wordList) << endl;
    return 0;
}