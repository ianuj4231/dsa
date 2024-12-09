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

bool val(TreeNode* root, int minn, int maxx){
        if(!root)return true;
        if(root->val  <=  minn || root->val >= maxx  ){
          return false;
        }
        return val(root->left,  minn, root->val) &&  val(root->right,   root->val, maxx ); 
     
}

int main(){
  TreeNode* root= new TreeNode(1);
  root->left=new TreeNode(4);
  root->right=new TreeNode(3);
  cout<< val(root, INT_MIN, INT_MAX );   // prints 1 for true and 0 for false
  return 0;
}
