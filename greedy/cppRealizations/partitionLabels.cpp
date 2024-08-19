#include <vector>
#include <iostream>
#include <map>

using namespace std;


class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char, int> lastIndex;
        for(int i = 0; i < s.size(); i++){
            lastIndex[s[i]] = i;
        }
        vector<int> res;
        int size = 0;
        int end = 0;
        for(int i = 0; i < s.size(); i++){
            size++;
            end = max(end, lastIndex[s[i]]);
            if(i == end){
                res.push_back(size);
                size = 0;
            }
        }
        return res;
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
    string s = "ababcbacadefegdehijhklij";
    cout << "Input:" << endl;
    cout << s << endl;
    cout << "Solution:" << endl;
    vector<int> result = Solution().partitionLabels(s);
    cout << result << endl;
    return 0;
}