#include <vector>
#include <iostream>

using namespace std;



class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);
        for(int i = cost.size() - 3; i >= 0; i--){
            cost[i] += min(cost[i + 1], cost[i + 2]);
        }
        return min(cost[0], cost[1]);
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
    vector<int> cost = {10,15,20};
    cout << "Cost: " << cost << endl;
    cout << "Solution: " << endl;
    cout << Solution().minCostClimbingStairs(cost) << endl;
    return 0;
}