#include <vector>
#include <iostream>

using namespace std;



class Solution {
public:
    void dfs(int index, vector<int>& nums){
        if(index == nums.size()){
            result.push_back(subset);
            return;
        }
        subset.push_back(nums[index]);
        dfs(index + 1, nums);
        subset.pop_back();
        dfs(index + 1, nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0, nums);
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
    vector<int> nums = {1,2,3};
    cout << "Input: " << nums << endl;
    cout << "Solution: " << Solution().subsets(nums) << endl;
    return 0;
}