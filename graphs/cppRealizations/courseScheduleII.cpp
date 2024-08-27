#include <vector>
#include <iostream>
#include <set>
#include <map>

using namespace std;


class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
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
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1,0}};
    cout << "numCourses = " << numCourses << endl;
    cout << "prerequisites = " << prerequisites << endl;
    cout << "Solution: " << Solution().findOrder(numCourses, prerequisites) << endl;
    return 0;
}