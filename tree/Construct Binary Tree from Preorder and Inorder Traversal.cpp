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
// time is o-N and space is o-H
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
             unordered_map<int, int> mp;
             for(int i=0;i<inorder.size();i++){
                mp[inorder[i]]=i;
             }
             function<TreeNode*(int& , int , int )>build=[&](int& preindex, int instart , int  inend)->TreeNode*{
                        if(instart >  inend )return nullptr;

                        int rootval=preorder[preindex++];
                        TreeNode* root = new TreeNode(rootval);
                        int inindex=mp[rootval];
              
                        root->left=build(preindex, instart, inindex-1);
                        root->right=build(preindex, inindex+1, inend);
              
                        return root;
             };
                int preindex=0;
                return build(preindex, 0, inorder.size()-1);
    }
};
