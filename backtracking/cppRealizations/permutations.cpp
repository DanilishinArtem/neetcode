#include <vector>
#include <iostream>

using namespace std;



class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size() == 0){
            return {{}};
        }
        vector<int> temp = vector<int>(nums.begin() + 1, nums.end());
        vector<vector<int>> perms = permute(temp);
        vector<vector<int>> result;
        for(auto p : perms){
            for(int i = 0; i < p.size() + 1; i++){
                vector<int> temp = p;
                temp.insert(temp.begin() + i, nums[0]);
                result.push_back(temp);
            }
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
    vector<int> nums = {1,2,3};
    cout << "Input: " << nums << endl;
    cout << "Solution: " << Solution().permute(nums) << endl;
    return 0;
}