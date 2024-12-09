#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
      int val;
      TreeNode* left;
      TreeNode* right;
      TreeNode(int x){
        val=x;
        left=nullptr;
        right=nullptr;
      }
};


TreeNode* invert(TreeNode* root){
   if(!root)return nullptr;
   invert(root->left);
   invert(root->right);
   TreeNode*temp=root->left;
   root->left=root->right;
   root->right=temp;
   return root;
}

void lvl(TreeNode* root){
     queue<TreeNode* > q;
     q.push(root);
     vector<int> res;
     while(! q.empty()){
        TreeNode* curr= q.front();
        q.pop();
        if(curr->left){
            q.push(curr->left);
        }
        if(curr->right){
            q.push(curr->right);  
        }
        res.push_back(curr->val);
     }
     for(int i: res){
       cout<< i <<" ";
     }
}

int main(){
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(-1);
    root1->left->left = new TreeNode(3);
    root1->left->right = new TreeNode(4);
    lvl(root1);
    invert(root1);
    cout<<endl;
    lvl(root1);
}
