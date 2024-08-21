#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


class Solution {
public:
    void dfs(int index, int total, vector<int>& candidates, int target){
        if(total == target){
            result.push_back(cur);
            return;
        }
        if(index == candidates.size() || total > target){
            return;
        }
        // include candidates[index]
        cur.push_back(candidates[index]);
        dfs(index + 1, total + candidates[index], candidates, target);
        cur.pop_back();

        // exclude candidates[index]
        while(index + 1 < candidates.size() && candidates[index] == candidates[index + 1]){
            index++;
        }
        dfs(index + 1, total, candidates, target);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(0, 0, candidates, target);
        return result;        
    }
private:
    vector<vector<int>> result;
    vector<int> cur;
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
    vector<int> nums = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    cout << "Input: candidates = " << nums << ", target = " << target << endl;
    Solution s;
    vector<vector<int>> res = s.combinationSum2(nums, target);
    cout << "Output: " << res << endl;
}