#include <vector>
#include <iostream>
#include <set>
#include <tuple>

using namespace std;
#define MAX(a, b) ((a) > (b) ? (a) : (b))



class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(grid[r][c] == 1){
                    int current = dfs(grid, r, c, rows, cols);
                    area = MAX(area, current);
                }
            }
        }
        return area;
    }
private:
    int dfs(vector<vector<int>>& grid, int r, int c, int rows, int cols){
        if(r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == 0){
            return 0;
        }
        grid[r][c] = 0;
        return (1 + dfs(grid, r + 1, c, rows, cols) + dfs(grid, r - 1, c, rows, cols) + dfs(grid, r, c + 1, rows, cols) + dfs(grid, r, c - 1, rows, cols));
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
    vector<vector<int>> grid = {{0,0,1,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,1,1,0,1,0,0,0,0,0,0,0,0},{0,1,0,0,1,1,0,0,1,0,1,0,0},{0,1,0,0,1,1,0,0,1,1,1,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,0,0,0,0,0,0,1,1,0,0,0,0}};
    cout << "Input: " << grid << endl;
    int answer = Solution().maxAreaOfIsland(grid);
    cout << "Solution: " << answer << endl;
    return 0;
}