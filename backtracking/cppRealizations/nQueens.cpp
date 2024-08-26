#include <vector>
#include <iostream>
#include <set>

using namespace std;


class Solution {
public:
    void backtrack(int r, int n){
        if(r == n){
            result.push_back(board);
            return;
        }
        for(int c = 0; c < n; c++){
            if(col.find(c) != col.end() || posDiag.find(r + c) != posDiag.end() || negDiag.find(r - c) != negDiag.end()){
                continue;
            }
            col.insert(c);
            posDiag.insert(r + c);
            negDiag.insert(r - c);
            board[r][c] = 'Q';

            backtrack(r + 1, n);
            
            col.erase(c);
            posDiag.erase(r + c);
            negDiag.erase(r - c);
            board[r][c] = '.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        board = vector<string>(n, string(n, '.'));
        backtrack(0, n);
        return result;
    }
private:
    set<int> col;
    set<int> posDiag;
    set<int> negDiag;
    vector<vector<string>> result;
    vector<string> board;
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
    int n = 4;
    cout << "Input: " << n << endl;
    cout << "Solution: " << Solution().solveNQueens(n) << endl;
    return 0;
}