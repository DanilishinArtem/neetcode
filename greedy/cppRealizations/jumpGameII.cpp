#include <vector>
#include <iostream>

using namespace std;



class Solution {
public:
    int jump(vector<int>& nums) {
        int res = 0;
        int l = 0;
        int r = 0;
        while(r < nums.size() - 1){
            int farthest = 0;
            for(int i = l; i <= r; i++){
                farthest = max(farthest, i + nums[i]);
            }
            l = r + 1;
            r = farthest;
            res++;
        }
        return res;
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
    cout << "Solution: " << Solution().jump(nums) << endl;
    return 0;
}