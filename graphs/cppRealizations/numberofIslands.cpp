#include <vector>
#include <iostream>
#include <set>
#include <queue>
#include <tuple>

using namespace std;


class Solution {
public:
    void bfs(vector<vector<char>>& grid, int i, int j){
        q.push({i, j});
        visit.insert({i, j});
        while(!q.empty()){
            int x = get<0>(q.front());
            int y = get<1>(q.front());
            q.pop();
            for(int k = 0; k < 4; k++){
                int nx = x + dir[k][0];
                int ny = y + dir[k][1];
                if(nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && grid[nx][ny] == '1' && visit.find({nx, ny}) == visit.end()){
                    q.push({nx, ny});
                    visit.insert({nx, ny});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        for(int r = 0; r < grid.size(); r++){
            for(int c = 0; c < grid.size(); c++){
                if(grid[r][c] == '1' && visit.find({r, c}) == visit.end()){
                    bfs(grid, r, c);
                    islands += 1;
                }
            }
        }
        return islands;
    }
private:
    set<tuple<int, int>> visit;
    queue<tuple<int, int>> q;
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
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
    vector<vector<char>> grid = {{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}};
    cout << "Input: " << grid << endl;
    cout << "Solution: " << Solution().numIslands(grid) << endl;
    return 0;
}