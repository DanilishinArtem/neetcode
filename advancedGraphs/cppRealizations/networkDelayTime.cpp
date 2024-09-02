#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <queue>

using namespace std;


class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        map<int, vector<pair<int, int>>> adges;
        for(size_t i = 0; i < times.size(); i++){
            adges[times[i][0]].push_back({times[i][1], times[i][2]});
        }

        set<int> visited;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        minHeap.push({0, k});
        int t = 0;
        while(minHeap.size() > 0){
            int w1 = minHeap.top().first;
            int n1 = minHeap.top().second;
            minHeap.pop();
            if(visited.find(n1) != visited.end()){
                continue;
            }
            t = max(t, w1);
            visited.insert(n1);
            for(auto& edge : adges[n1]){
                minHeap.push({w1 + edge.second, edge.first});
            }
        }
        if(visited.size() != n){
            return -1;
        }
        return t;
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
    int n = 4;
    int k = 2;
    vector<vector<int>> times = {{2,1,1},{2,3,1},{3,4,1}};
    cout << "Input: n = " << n << ", k = " << k << ", times = " << times << endl;
    cout << "Solution: " << Solution().networkDelayTime(times, n, k) << endl;
    return 0;
}