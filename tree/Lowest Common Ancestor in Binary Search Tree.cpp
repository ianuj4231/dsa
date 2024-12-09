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


TreeNode* lca(TreeNode* root , TreeNode*    node1, TreeNode* node2){
    if(!root || !node1 ||  !node2 ){
      return nullptr;
    }
      while(root){
          if(root->val > node1->val && root->val > node2-> val){
             root=root->left;
          }
          else if(root->val <  node1->val && root->val < node2-> val){
                root=root-> right;
          }
          else return root;
      }
}

int main(){
  TreeNode* root= new TreeNode(1);
  root->left=new TreeNode(0);
  root->right=new TreeNode(3);
  TreeNode* finalx= lca( root ,root->left ,nullptr) ;
  if(finalx){
cout<<         finalx-> val;
  }
  else 
  {
    cout<<"no lca found";
  }
  return 0;
}
