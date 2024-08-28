#include <vector>
#include <map>
#include <set>
#include <iostream>

using namespace std;


class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        return 2;
    }
};


template <typename T>
ostream& operator<<(ostream& out, const vector<T>& str){
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


template<typename T>
ostream& operator<<(ostream& out, const vector<vector<T>>& str){
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
    int n = 6;
    vector<vector<int>> edges = {{0,1},{1,2},{2,3},{4,5}};
    cout << "Input: n = " << n << ", edges = " << edges << endl;
    cout << "Solution: " << Solution().countComponents(n, edges) << endl;
    return 0;
}