#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;


class Solution {
public:
    int climbStairs(int n) {
        int one = 1, two = 1;
        for(int i = 0; i < n - 1; i++){
            int temp = one;
            one = one + two;
            two = temp;
        }
        return one;
    }
};


int main(){
    int n = 3;
    cout << Solution().climbStairs(n) << endl;
    return 0;
}