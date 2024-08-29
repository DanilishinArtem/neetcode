#include <vector>
#include <string>
#include <iostream>

using namespace std;


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
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