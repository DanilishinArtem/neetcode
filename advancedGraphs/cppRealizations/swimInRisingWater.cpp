#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <queue>

using namespace std;


class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int N = grid.size();
        set<tuple<int, int>> visited;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minH;
        minH.push({grid[0][0], 0, 0});
        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while(!minH.empty()){
            vector<int> curr = minH.top();
            minH.pop();
            int time = curr[0];
            int row = curr[1];
            int col = curr[2];
            if(row == N - 1 && col == N - 1){
                return time;
            }
            for(auto dir : directions){
                int neiRow = row + dir[0];
                int neiCol = col + dir[1];
                if(neiRow < 0 || neiRow == N || neiCol < 0 || neiCol == N || visited.find({neiRow, neiCol}) != visited.end()){
                    continue;
                }
                visited.insert({neiRow, neiCol});
                minH.push({max(time, grid[neiRow][neiCol]), neiRow, neiCol});
            }
        }
        return -1;
    }
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
    vector<vector<int>> grid = {{0, 2}, {1, 3}};
    cout << "Input: " << grid << endl;
    cout << "Solution: " << Solution().swimInWater(grid) << endl;
    return 0;
}