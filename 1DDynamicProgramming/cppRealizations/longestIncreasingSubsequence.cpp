#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        for(int i = nums.size() - 1; i > -1; i--){
            for(int j = i + 1; j < nums.size(); j++){
                if(nums[i] < nums[j]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
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
    vector<int> nums = {10,9,2,5,3,7,101,18};
    cout << "Input: " << nums << endl;
    cout << "Output: " << Solution().lengthOfLIS(nums) << endl;
    return 0;
}