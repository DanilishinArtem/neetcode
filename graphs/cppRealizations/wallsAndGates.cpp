#include <vector>
#include <iostream>
#include <set>
#include <tuple>
#include <queue>

using namespace std;


class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& rooms) {
        for(int r = 0; r < rooms.size(); r++){
            for(int c = 0; c < rooms[0].size(); c++){
                if(rooms[r][c] == 0){
                    q.push({r, c});
                    visit.insert({r, c});
                }
            }
        }
        int dist = 0;
        while(!q.empty()){
            for(int i = 0; i < q.size(); i++){
                int r = get<0>(q.front());
                int c = get<1>(q.front());
                q.pop();
                rooms[r][c] = dist;
                addRoom(rooms, r + 1, c);
                addRoom(rooms, r - 1, c);
                addRoom(rooms, r, c + 1);
                addRoom(rooms, r, c - 1);
            }
            dist += 1;
        }
    }
private:
    set<tuple<int, int>> visit;
    queue<tuple<int, int>> q;

    void addRoom(vector<vector<int>>& rooms, int r, int c){
        if(r < 0 || c < 0 || r == rooms.size() || c == rooms[0].size() || rooms[r][c] == -1 || visit.find({r, c}) != visit.end()){
            return;
        }
        visit.insert({r, c});
        q.push({r, c});
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
    vector<vector<int>> grid = {{2147483647,-1,0,2147483647},{2147483647,2147483647,2147483647,-1},{2147483647,-1,2147483647,-1},{0,-1,2147483647,2147483647}};
    cout << "Input: " << grid << endl;
    Solution().islandsAndTreasure(grid);
    cout << "Output: " << grid << endl;
    return 0;
}