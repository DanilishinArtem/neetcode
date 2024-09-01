#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;


class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int N = points.size();
        vector<vector<pair<int, int>>> adj(N, vector<pair<int, int>>());
        for(int i = 0; i < N; i++){
            int x1 = points[i][0];
            int y1 = points[i][1];
            for(int j = 0; j < N; j++){
                int x2 = points[j][0];
                int y2 = points[j][1];
                int dist = abs(x1 - x2) + abs(y1 - y2);
                adj[i].push_back({dist, j});
                adj[j].push_back({dist, i});
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        int res = 0;
        minHeap.push({0, 0});
        set<int> visited;
        while(visited.size() < N){
            int dist = minHeap.top().first;
            int node = minHeap.top().second;
            minHeap.pop();
            if(visited.find(node) != visited.end()){
                continue;
            }
            res += dist;
            visited.insert(node);
            for(auto& edge : adj[node]){
                if(visited.find(edge.second) == visited.end()){
                    minHeap.push({edge.first, edge.second});
                }
            }
        }
        return res;
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

    vector<vector<int>> points = {{0,0},{2,2},{3,10},{5,2},{7,0}};
    cout << "Input: " << points << endl;
    Solution s;
    cout << "Solution: " << s.minCostConnectPoints(points) << endl;
    return 0;
}