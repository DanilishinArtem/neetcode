#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;
 

 class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int> orig_queries = queries;
        sort(queries.begin(), queries.end());
        sort(intervals.begin(), intervals.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        unordered_map<int, int> res;
        int i = 0;
        vector<int> result;
        for(const auto& query: queries){
            while(i < intervals.size() && intervals[i][0] <= query){
                minHeap.push({intervals[i][1] - intervals[i][0] + 1, intervals[i][1]});
                i++;
            }
            while(minHeap.size() > 0 && minHeap.top().second < query){
                minHeap.pop();
            }
            if(minHeap.size() > 0){
                res[query] = minHeap.top().first;
            }else{
                res[query] = -1;
            }
        }

        for(auto query: orig_queries){
            result.push_back(res[query]);
        }
        return result;
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
    vector<vector<int>> intervals = {{2,3},{2,5},{1,8},{20,25}};
    vector<int> queries = {2,19,5,22};
    cout << "Input:" << endl;
    cout << "intervals = " << intervals << endl;
    cout << "queries = " << queries << endl;
    cout << "Solution:" << endl;
    vector<int> result = Solution().minInterval(intervals, queries);
    cout << result << endl;
    return 0;
}