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

void right(TreeNode* root)
{
  queue<TreeNode* > q;
  q.push(root);
  vector<int> res;
  while(! q.empty() ){
       int sz=q.size();
       for(int i=0;i<sz;i++){
         TreeNode* curr= q.front();
      q.pop();
      if(i==sz-1)res.push_back(curr->val);
      if(curr->left)q.push(curr->left);
      if(curr->right)q.push(curr->right);  
       }
       
  }
  for(int x: res)cout<<x<<" "; 
}

int main(){
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(0);
    root1->right = new TreeNode(4);
    right(root1);
    cout<<endl;
}
