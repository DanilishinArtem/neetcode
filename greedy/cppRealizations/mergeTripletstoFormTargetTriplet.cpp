#include <vector>
#include <iostream>
#include <set>
using namespace std;



class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        set<int> good;
        for(auto t : triplets){
            if(t[0] > target[0] || t[1] > target[1] || t[2] > target[2]){
                continue;
            }
            for(int i = 0; i < 3; i++){
                if(t[i] == target[i]){
                    good.insert(i);
                }
            }
        }
        return good.size() == 3;
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
    vector<vector<int>> triplets = {{2,5,3},{1,8,4},{1,7,5}};
    vector<int> target = {2,7,5};
    cout << "Input:" << endl;
    cout << "triplets = " << triplets << endl;
    cout << "target = " << target << endl;
    cout << "Solution: " << Solution().mergeTriplets(triplets, target) << endl;
    return 0;
}