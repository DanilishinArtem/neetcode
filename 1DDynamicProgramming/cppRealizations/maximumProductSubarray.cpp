#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;



class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0; // handle empty vector case

        int res = *max_element(nums.begin(), nums.end());
        int curMin = 1, curMax = 1;

        for (int n : nums) {
            if (n == 0) {
                curMin = 1;
                curMax = 1;
                continue;
            }
            int tmp = curMax * n;
            curMax = max(n * curMax, max(n * curMin, n));
            curMin = min(tmp, min(n * curMin, n));
            res = max(res, curMax);
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


int main()
{
    vector<int> nums = {2,3,-2,4};
    cout << "Input: nums = " << nums << endl;
    cout << "Output: " << endl;
    cout << Solution().maxProduct(nums) << endl;
    return 0;
}