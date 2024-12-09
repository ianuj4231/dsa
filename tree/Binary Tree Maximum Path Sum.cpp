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

int maxpathfn(TreeNode* root, int &maxx){
     if(!root){
       return 0;
     }
     int left=max(0, maxpathfn(root->left , maxx));
     int right=max(0, maxpathfn(root->right, maxx));
     int straightpath= root->val + max(left, right );
     int curvedpath=root->val+ left+ right;
     maxx=max(maxx, max(straightpath, curvedpath));
     return straightpath;
}

int maxpath(TreeNode* root){
      int maxx=INT_MIN;
      maxpathfn(root, maxx);
      return maxx;
}
int main(){
   TreeNode* root=new TreeNode(1);
   root->left=new TreeNode(2);
   root->right=new TreeNode(3);
   cout<< maxpath(root);
}
