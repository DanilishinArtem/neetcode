#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int total_tickets = tickets.size();
        for(const vector<string>& ticket : tickets){
            adj[ticket[0]].push_back(ticket[1]);
        }
        for(auto& [src, destinations] : adj) {
            std::sort(destinations.begin(), destinations.end());
        }
        result.push_back("JFK");
        dfs("JFK", total_tickets);
        return result;
    }
private:
    map<string, vector<string>> adj;
    vector<string> result;
    bool dfs(string src, int total_tickets){
        if(result.size() == total_tickets + 1){
            return true;
        }
        if(adj.find(src) == adj.end() || adj[src].empty()) {
            return false;
        }
        auto temp = adj[src];
        for(int i = 0; i < temp.size(); i++){
            adj[src].erase(adj[src].begin() + i);
            result.push_back(temp[i]);
            if(dfs(temp[i], total_tickets)){
                return true;
            }
            result.pop_back();
            adj[src].insert(adj[src].begin() + i, temp[i]);
        }
        return false;
    }
};


ostream& operator<<(ostream& out, const vector<string>& str){
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


ostream& operator<<(ostream& out, const vector<vector<string>>& str){
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
    vector<vector<string>> tickets = {{"HOU","JFK"},{"SEA","JFK"},{"JFK","SEA"},{"JFK","HOU"}};
    cout << "Input:" << tickets << endl;
    vector<string> itinerary = Solution().findItinerary(tickets);
    cout << "Output:" << itinerary << endl;    
}