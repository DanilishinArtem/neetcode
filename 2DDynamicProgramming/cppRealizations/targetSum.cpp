#include <vector>
#include <iostream>
#include <map>
#include <tuple>

using namespace std;


class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        map<pair<int, int>, int> dp;
        return backtrack(0, 0, nums, target, dp);
    }
private:
    int backtrack(int index, int total, vector<int>& nums, int target, map<pair<int, int>, int>& dp){
        if(index == nums.size()){
            if(total == target){
                return 1;
            }else{
                return 0;
            }
        }
        if(dp.find({index, total}) != dp.end()){
            return dp[{index, total}];
        }
        dp[{index, total}] = backtrack(index + 1, total + nums[index], nums, target, dp) + backtrack(index + 1, total - nums[index], nums, target, dp);
        return dp[{index, total}];
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


int main(){
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;
    cout << "Input: nums = " << nums << ", target = " << target << endl;
    cout << "Output: " << Solution().findTargetSumWays(nums, target) << endl;
    return 0;
}