#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int goal = nums.size() - 1;
        for(int i = nums.size() - 1; i >= 0; i--){
            if(i + nums[i] >= goal){
                goal = i;
            }
        }
        return goal == 0;
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
    vector<int> nums = {2,3,1,1,4};
    cout << "Input: " << nums << endl;
    cout << "Solution: " << Solution().canJump(nums) << endl;
    return 0;
}