#include <vector>
#include <iostream>

using namespace std;


class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        k_ = k;
        nums_ = nums;
    }
    
    int add(int val) {
        
    }
private:
    int k_;
    vector<int> nums_;
};


int main(){
    vector<int> nums = {4, 5, 8, 2};
    KthLargest* obj = new KthLargest(3, nums);
    cout << obj->add(3) << endl;
    cout << obj->add(5) << endl;
    cout << obj->add(10) << endl;
    cout << obj->add(9) << endl;
    cout << obj->add(4) << endl;
    return 0;
}