#include <vector>
#include <iostream>
#include <set>
#include <map>

using namespace std;


class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        if(dfs(0, -1) == true && n == visited.size()){
            return true;
        }
        return false;
    }
private:
    map<int, vector<int>> adj;
    set<int> visited;
    bool dfs(int i, int prev){
        if(visited.find(i) != visited.end()){
            return false;
        }
        visited.insert(i);
        for(auto j : adj[i]){
            if(j == prev){
                continue;
            }
            if(!dfs(j, i)){
                return false;
            }
        }
        return true;
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
    int n = 4;
    vector<vector<int>> edges = {{0,1},{2,3}};
    // vector<vector<int>> edges = {{0,1},{0,2},{0,3},{1,4}};
    cout << "Input: n = " << n << ", edges = " << edges << endl;
    cout << "Solution: " << Solution().validTree(n, edges) << endl;
    return 0;
}