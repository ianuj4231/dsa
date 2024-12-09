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


void inor(int &ans, int &count, TreeNode* root,int  k ){
  if(!root)return ;
  inor(ans, count, root->left, k);
  if(k==count){
    ans=root->val;
  }
  count++;
  inor(ans, count, root->right, k);
}

int main(){
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(0);
    root1->right = new TreeNode(4);
    cout<<endl;
    int ans=-1;
    int count=1;
    int k=1 ;
    inor(ans, count, root1, k);
    cout<<"ans is "<<ans;
}
