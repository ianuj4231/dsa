/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
bool  fn(  TreeNode* root, long long minn, long long maxx  )  
{
        if(!root){
            return true;
        }
        if( root->val <= minn  || root->val >= maxx ){
            return false;
        }
        return fn(root->left, minn, root->val) && fn(root->right, root->val, maxx);

}
    bool isValidBST(TreeNode* root) {
            return fn(  root, LONG_MIN, LONG_MAX  );    
    }
};
