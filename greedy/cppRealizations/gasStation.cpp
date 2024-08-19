#include <vector>
#include <iostream>
#include <numeric>

using namespace std;


class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(), 0)){
            return -1;
        }
        int total = 0;
        int res = 0;
        for(int i = 0; i < gas.size(); i++){
            total += gas[i] - cost[i];
            if(total < 0){
                total = 0;
                res = i + 1;
            }
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
    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};
    cout << "Gas: " << gas << endl;
    cout << "Cost: " << cost << endl;
    cout << "Solution: " << Solution().canCompleteCircuit(gas, cost) << endl;
    return 0;
}