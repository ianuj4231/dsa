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

void fn2(int maxx, TreeNode* root, int &count){
    if(! root) return ;
    if(root-> val > maxx){
        count++;
        maxx=max(maxx, root->val);
    }
    fn2(maxx, root->left, count);
    fn2(maxx, root-> right, count);
}

int fn(TreeNode* root){  // be careful with teh return type, it is int.
    int maxx=INT_MIN;
    int count=0;
    fn2(maxx, root, count);
    return count;
}

int main(){
  TreeNode* root= new TreeNode(1);
  root->left=new TreeNode(2);
  root->right=new TreeNode(-1);
    root->left->left=new TreeNode(3);
  root->left->right=new TreeNode(4);

  cout<< fn(root);
  
}
