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

int maxdepth(TreeNode* root){
  if(!root)return 0;
  int left=maxdepth(root->left);
  int right = maxdepth(root->right);
  return 1 + max(left, right);
}


int main(){
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(-1);
    root1->left->left = new TreeNode(3);
    root1->left->right = new TreeNode(4);
    cout<<maxdepth(root1);
    cout<<endl;

}
