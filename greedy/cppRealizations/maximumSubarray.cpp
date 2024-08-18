#include <vector>
#include <iostream>

using namespace std;



class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSub = nums[0];
        int curSum = 0;
        for(auto n : nums){
            if(curSum < 0){
                curSum = 0;
            }
            curSum += n;
            maxSub = max(maxSub, curSum);
        }
        return maxSub;
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
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << "Input: " << nums << endl;
    cout << "Output: " << Solution().maxSubArray(nums) << endl;
    return 0;
}