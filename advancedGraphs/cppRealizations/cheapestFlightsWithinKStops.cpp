#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <limits>

using namespace std;


class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> prices(n, numeric_limits<int>::max());
        prices[src] = 0;

        for(int i = 0; i < k + 1; i++){
            vector<int> temp(prices);
            temp = prices;
            for(const vector<int>& flight : flights){
                if(prices[flight[0]] == numeric_limits<int>::max()){
                    continue;
                }
                if(prices[flight[0]] + flight[2] < temp[flight[1]]){
                    temp[flight[1]] = prices[flight[0]] + flight[2];
                }
            }
            prices = temp;
        }
        return prices[dst] == numeric_limits<int>::max() ? -1 : prices[dst];
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

ostream& operator << (ostream& out, const vector<vector<int>>& str){
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
    vector<vector<int>> flights = {{0,1,1},{0,2,5},{1,2,1},{2,3,1}};
    int src = 0, dst = 3, k = 1, n = 4;
    cout << "flights = " << flights << endl;
    cout << "src = " << src << endl;
    cout << "dst = " << dst << endl;
    cout << "k = " << k << endl;
    cout << "n = " << n << endl;
    cout << "Solution: " << Solution().findCheapestPrice(4, flights, src, dst, k) << endl;
    return 0;
}