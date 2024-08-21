#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;




class Solution {
public:
    void backtrack(int i, vector<int>& nums){
        if(i == nums.size()){
            result.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        backtrack(i + 1, nums);
        subset.pop_back();
        while(i + 1 < nums.size() && nums[i] == nums[i + 1]){
            i++;
        }
        backtrack(i + 1, nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtrack(0, nums);
        return result;
    }
private:
    vector<vector<int>> result;
    vector<int> subset;
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

    vector<int> nums = {1, 2, 2};
    cout << "Input: " << nums << endl;
    Solution s;
    vector<vector<int>> res = s.subsetsWithDup(nums);
    cout << "Output: " << res << endl;
}