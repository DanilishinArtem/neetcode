#include <vector>
#include <iostream>
#include <set>
#include <map>

using namespace std;


class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i = 0; i < prerequisites.size(); i++){
            preMap[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for(int crs = 0; crs < numCourses; crs++){
            if(!dfs(crs)){
                return false;
            }
        }        
        return true;
    }
private:
    set<int> visited;
    map<int, vector<int>> preMap;
    bool dfs(int crs){
        if(visited.find(crs) != visited.end()){
            return false;
        }
        if(preMap[crs] == vector<int>{}){
            return true;
        }
        visited.insert(crs);
        for(auto n : preMap[crs]){
            if(!dfs(n)){
                return false;
            }
        }
        visited.erase(crs);
        preMap[crs] = vector<int>{};
        return true;
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
    vector<vector<int>> prerequisites = {{1,0},{2,0},{3,1},{3,2}};
    int numCourses = 4;
    cout << "numCourses = " << numCourses << endl;
    cout << "prerequisites = " << prerequisites << endl;
    cout << "Solution: " << Solution().canFinish(numCourses, prerequisites) << endl;
    return 0;
}