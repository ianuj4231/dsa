class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
         vector<vector<int>>  finalx;
         queue<TreeNode* > q;
         if(!root){
            return {};
         }
        q.push(root);
        while(! q.empty()){
            vector<int> currx;
            int sz=q.size();
            for(int i=0;i<sz;i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left){
                        q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
                currx.push_back(curr->val);
                }
            
            finalx.push_back(currx);
        }
            return finalx;

    }
    
};
