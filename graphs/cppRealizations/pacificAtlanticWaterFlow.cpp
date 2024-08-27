#include <vector>
#include <iostream>
#include <set>
#include <tuple>

using namespace std;


class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        
        for (int c = 0; c < cols; c++) {
            dfs(heights, 0, c, pac, heights[0][c]);
            dfs(heights, rows - 1, c, atl, heights[rows - 1][c]);
        }
        
        for (int r = 0; r < rows; r++) {
            dfs(heights, r, 0, pac, heights[r][0]);
            dfs(heights, r, cols - 1, atl, heights[r][cols - 1]);
        }

        vector<vector<int>> res;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (pac.find({r, c}) != pac.end() && atl.find({r, c}) != atl.end()) {
                    res.push_back({r, c});
                }
            }
        }
        return res;
    }
private:
    set<tuple<int, int>> pac;
    set<tuple<int, int>> atl;
    void dfs(vector<vector<int>>& heights, int r, int c, set<tuple<int, int>> &visit, int prevHeight){
        if(r < 0 || c < 0 || r == heights.size() || c == heights[0].size() || visit.find({r, c}) != visit.end() || heights[r][c] < prevHeight){
            return;
        }
        visit.insert({r, c});
        dfs(heights, r + 1, c, visit, heights[r][c]);
        dfs(heights, r - 1, c, visit, heights[r][c]);
        dfs(heights, r, c + 1, visit, heights[r][c]);
        dfs(heights, r, c - 1, visit, heights[r][c]);
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
    vector<vector<int>> heights = {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
    cout << "Input" << endl;
    cout <<heights << endl;
    cout << "Output" << endl;
    cout << Solution().pacificAtlantic(heights) << endl;
    return 0;
}