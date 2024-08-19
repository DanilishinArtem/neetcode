#include <vector>
#include <iostream>
#include <numeric>
#include <map>
#include <queue>
using namespace std;




class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0){
            return false;
        }
        map<int, int> count;
        for(int n : hand){
            count[n]++;
        }
        priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> minH(count.begin(), count.end());
        while(minH.size() > 0){
            int first = minH.top().first;
            for(int i = first; i < first + groupSize; i++){
                if(count.find(i) == count.end()){
                    return false;
                }
                count[i]--;
                if(count[i] == 0){
                    if(i != minH.top().first){
                        return false;
                    }
                    minH.pop();
                }
            }

        }
        return true;
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
    vector<int> hand = {1,2,3,6,2,3,4,7,8};
    cout << "Input: " << hand << endl;
    cout << "Solution: " << Solution().isNStraightHand(hand, 3) << endl;
    return 0;
}