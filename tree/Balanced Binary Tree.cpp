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

int fn (TreeNode* root ){
  if(!root)return 0;
    int lh = fn(root->left);
    if(lh==-1) return -1;
    int rh = fn(root->right);
    if(rh==-1)return -1;
    if(abs(lh-rh ) > 1   ){
         return -1;
    }
    return 1+ max(lh, rh );
}

int main(){
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(0);
    root1->right = new TreeNode(4);
    root1->left->left = new TreeNode(0);
    root1->left->left->left = new TreeNode(0);

    if(fn(root1)!=-1)cout<<"true";
    else cout<<"false";
    cout<<endl;
}
