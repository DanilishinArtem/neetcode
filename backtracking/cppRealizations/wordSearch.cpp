#include <vector>
#include <iostream>
#include <set>
#include <tuple>

using namespace std;


class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word, int r, int c, int i){
        if(i == word.size()){
            return true;
        }
        if(r < 0 || c < 0 || r == board.size() || c == board[0].size() || path.find({r, c}) != path.end() || board[r][c] != word[i]){
            return false;
        }
        path.insert({r, c});
        bool res = dfs(board, word, r + 1, c, i + 1) || dfs(board, word, r - 1, c, i + 1) || dfs(board, word, r, c + 1, i + 1) || dfs(board, word, r, c - 1, i + 1);
        path.erase({r, c});
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int ROWS = board.size();
        int COLS = board[0].size();
        for(int r = 0; r < ROWS; r++){
            for(int c = 0; c < COLS; c++){
                if(dfs(board, word, r, c, 0)){
                    return true;
                }
            }
        }
        return false;
    }
private:
    set<tuple<int, int>> path;
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
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "ABCCED";
    cout << "Input: board = " << board << ", word = " << word << endl;
    Solution s;
    bool res = s.exist(board, word);
    cout << "Output: " << res << endl;
    return 0;
}