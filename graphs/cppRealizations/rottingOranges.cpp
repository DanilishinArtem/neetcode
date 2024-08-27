#include <vector>
#include <iostream>
#include <set>
#include <tuple>
#include <queue>

using namespace std;


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int time = 0;
        int fresh = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 1){
                    fresh++;
                }
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }

        while(!q.empty() && fresh > 0){
            int size = q.size();
            time++;
            for(int i = 0; i < size; i++){
                int x = get<0>(q.front());
                int y = get<1>(q.front());
                q.pop();
                for(int k = 0; k < 4; k++){
                    int nx = x + directions[k].first;
                    int ny = y + directions[k].second;
                    if(nx >= 0 && nx < rows && ny >= 0 && ny < cols && grid[nx][ny] == 1){
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                        fresh--;
                    }
                }
            }
        }
        return fresh == 0 ? time : -1;
    }
private:
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    queue<tuple<int, int>> q;
};


ostream& operator<<(ostream& out, const vector<int>& str){
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


ostream& operator<<(ostream& out, const vector<vector<int>>& str){
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
    vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
    cout << "Input: " << grid << endl;
    cout << "Output: " << Solution().orangesRotting(grid) << endl;
    return 0;
}