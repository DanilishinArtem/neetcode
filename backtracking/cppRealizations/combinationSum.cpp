#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    void dfs(int index, vector<int>& cur, int total, vector<int>& candidates, int target){
        if(total == target){
            result.push_back(cur);
            return;
        }
        if(index >= candidates.size() || total > target){
            return;
        }
        cur.push_back(candidates[index]);
        dfs(index, cur, total + candidates[index], candidates, target);
        cur.pop_back();
        dfs(index + 1, cur, total, candidates, target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> cur{};
        dfs(0, cur, 0, candidates, target);
        return result;
    }
private:
    vector<vector<int>> result;
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
    vector<int> candidates = {2,3,6,7};
    int target = 7;
    cout << "Input: " << "candidates = " << candidates << ", target = " << target << endl;
    cout << "Solution: " << Solution().combinationSum(candidates, target) << endl;
    return 0;
}