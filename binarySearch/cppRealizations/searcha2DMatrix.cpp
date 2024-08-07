#include <iostream>
#include <vector>
#include <stack>

using namespace std;


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ROWS = matrix.size();
        int COLS = matrix[0].size();
        int top = 0;
        int bot = ROWS - 1;
        while(top <= bot){
            int row = (top + bot) / 2;
            if(target > matrix[row][COLS - 1]){
                top = row + 1;
            }else if(target < matrix[row][0]){
                bot = row - 1;
            }else{
                break;
            }
        }

        if(!(top <= bot)){
            return false;
        }
        int row = (top + bot) / 2;
        int l = 0;
        int r = COLS - 1;
        while(l <= r){
            int mid = (l + r) / 2;
            if(target > matrix[row][mid]){
                l = mid + 1;
            }else if(target < matrix[row][mid]){
                r = mid - 1;
            }else{
                return true;
            }
        }
        return false;
    }
};



int main(){
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 3;
    cout << Solution().searchMatrix(matrix, target) << endl;
    return 0;
}