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

void lvl(TreeNode* root){
    vector<vector<int>> all;
    queue<TreeNode* > q;
    q.push(root);
    while(! q.empty()){
        int size=q.size();
        vector<int> res;
        while(size--){
          TreeNode* curr=  q.front();
          q.pop();
          if(curr->left){
             q.push(curr->left);
          }
          if(curr->right){
               q.push(curr->right);
          }
          res.push_back(curr->val);
        }
        all.push_back(res);
    }
    for(int i=0;i< all.size();i++){
      for(int j: all[i]){
          cout<< j<<" ";
      }
      cout<<endl;
    }
}

// time is o-N 
int main(){
  TreeNode* root= new TreeNode(1);
  root->left=new TreeNode(0);
  root->right=new TreeNode(3);
  lvl(root);
}
