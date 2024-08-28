#include <vector>
#include <iostream>
#include <set>
#include <map>

using namespace std;


class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {

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


template <typename T>
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
    int n = 5;
    vector<vector<int>> edges = {{0,1},{0,2},{0,3},{1,4}};
    cout << "Input: n = " << n << ", edges = " << edges << endl;
    cout << "Solution: " << Solution().validTree(n, edges) << endl;
    return 0;
}