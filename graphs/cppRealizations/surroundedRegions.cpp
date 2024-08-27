#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        for(int r = 0; r < rows; r++){
            dfs(board, r, 0);
            dfs(board, r, cols - 1);
        }
        for(int c = 0; c < cols; c++){
            dfs(board, 0, c);
            dfs(board, rows - 1, c);
        }
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(board[r][c] == 'O'){
                    board[r][c] = 'X';
                }
                if(board[r][c] == 'T'){
                    board[r][c] = 'O';
                }
            }
        }
    }
private:
    void dfs(vector<vector<char>>& board, int r, int c){
        if(r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] != 'O'){
            return;
        }
        board[r][c] = 'T';
        dfs(board, r + 1, c);
        dfs(board, r - 1, c);
        dfs(board, r, c + 1);
        dfs(board, r, c - 1);
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

void print_board(vector<vector<char>>& board){
    for(int i = 0; i < board.size(); i++){
        cout << board[i] << endl;
    }
}


int main(){
    vector<vector<char>> board = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
    cout << "Input" << endl;
    print_board(board);
    Solution().solve(board);
    cout << "Output" << endl;
    print_board(board);
    return 0;
}