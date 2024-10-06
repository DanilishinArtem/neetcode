#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;


class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int target = 0;
        for(int i = 0; i < nums.size(); i++){
            target += nums[i];
        }
        if(target % 2 != 0){
            return false;
        }
        target /= 2;
        unordered_set<int> dp;
        dp.insert(0);
        for(int i = 0; i < nums.size(); i++){
            unordered_set<int> temp;
            for(int t : dp){
                if(t + nums[i] == target){
                    return true;
                }
                temp.insert(t + nums[i]);
                temp.insert(t);
            }
            dp = temp;
        }
        return false;
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
    vector<int> nums = {1,5,11,5};
    bool result = Solution().canPartition(nums);
    cout << "Input: " << nums << endl;
    cout << "Output: " << result << endl;
    return 0;
}