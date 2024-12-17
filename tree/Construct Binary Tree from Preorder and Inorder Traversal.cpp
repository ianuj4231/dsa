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
    private: 
    int preindex=0;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        map<int, int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
    
        function<TreeNode*( int,int)>build=[&](  int instart,int inend)->TreeNode*{
                   if(inend < instart ){
                    return nullptr;
                   }
                   int rootval=preorder[preindex++];
                   int inindex=mp[rootval];
                   TreeNode* root=new TreeNode(rootval);
                   root->left=build( instart, inindex-1);
                   root->right=build( inindex+1, inend);
                   return root;
        };

        return build( 0, inorder.size()-1);
    }


};
