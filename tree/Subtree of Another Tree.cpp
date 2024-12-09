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

string ser(TreeNode* root, string &res){
      if(!root)
{    
      res+="#";
      return res;
  
}
      res+=to_string(root->val);
      ser(root->left, res);
      ser(root->right, res);
      return res;
}


int main(){
 TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(-1);
    root1->left->left = new TreeNode(3);
    root1->left->right = new TreeNode(4);
    
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(-1);
    root2->left->left = new TreeNode(3);
    root2->left->right = new TreeNode(4);

  // prints 1 for true and 0 for false;
  
  string str1, str2;
  ser(root1, str1);
  ser(root2, str2);
  if(str1.find(str2)!=string::npos){ /////////////imppp
      cout<< true;
  }
  else{
    cout<<false;
  }
  
}
