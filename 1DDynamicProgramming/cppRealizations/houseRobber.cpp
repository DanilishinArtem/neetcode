#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    int rob(vector<int>& nums) {
        int rob1 = 0, rob2 = 0;
        for(int i = 0; i < nums.size(); i++){
            int temp = max(rob1 + nums[i], rob2);
            rob1 = rob2;
            rob2 = temp;
        }
        return rob2;
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
    vector<int> nums = {1, 2, 3, 1};
    cout << "Input: " << nums << endl;
    cout << "Output: " << Solution().rob(nums) << endl;
    return 0;
}