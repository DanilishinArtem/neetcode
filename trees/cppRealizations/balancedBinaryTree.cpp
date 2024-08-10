#include "btf.h"


class Solution {
public:
    bool isBalanced(TreeNode* root) {
        
    }
};


int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    cout << "Input:" << endl;
    btf(root);
    cout << "Solution:" << endl;
    cout << Solution().isBalanced(root) << endl;
    return 0;
}