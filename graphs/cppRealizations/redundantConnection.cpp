#include <vector>
#include <iostream>


using namespace std;


class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> par;
        vector<int> rank;
        for(int i = 0; i <= edges.size(); i++){
            par.push_back(i);
            rank.push_back(1);
        }
        for(int i = 0; i < edges.size(); i++){
            int n1 = edges[i][0];
            int n2 = edges[i][1];
            if(!union_(par, rank, n1, n2)){
                return {n1, n2};
            }
        }
        return {};
    }
private:
    int find_(vector<int>& par, int n){
        int p = par[n];
        while(p != par[p]){
            par[p] = par[par[p]];
            p = par[p];
        }
        return p;
    }
    bool union_(vector<int>& par, vector<int>& rank, int n1, int n2){
        int p1 = find_(par, n1);
        int p2 = find_(par, n2);
        if(p1 == p2){
            return false;
        }
        if(rank[p1] > rank[p2]){
            par[p2] = p1;
            rank[p1] += rank[p2];
        }else{
            par[p1] = p2;
            rank[p2] += rank[p1];
        }
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
    vector<vector<int>> edges = {{1,2},{1,3},{2,3}};
    cout << "Input: " << edges << endl;
    cout << "Solution: " << Solution().findRedundantConnection(edges) << endl;
    return 0;
}