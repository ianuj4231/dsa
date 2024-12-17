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

string serialize(TreeNode* root){
      if(!root)return "[]";
      ostringstream out;
      queue<TreeNode* > q;
      q.push(root);
      while(! q.empty()){
          TreeNode* curr=q.front();
          q.pop();
          if(curr){
                out<<curr->val<<" ";
                q.push(curr->left);
                q.push(curr->right);
          }
          else{
            out<<"null ";
          }
      }
      string result=out.str();
      if(! result.empty()){
            result.pop_back();
      }
      return result;
}

TreeNode* deserialize(string data){
      istringstream in(data);
      if(data=="[]")return nullptr;
      queue<TreeNode* > q;
      string val;
      in>>val;
      TreeNode* root= new TreeNode(stoi(val));
      q.push(root);
      while(! q.empty()){
          TreeNode* curr=q.front();
          q.pop();
          in>>val;
          if(val!="null"){
              curr->left=new TreeNode(stoi(val));
              q.push(curr->left);
          }
          in>>val;
          if(val!="null"){
             curr->right=new TreeNode(stoi(val));
             q.push(curr->right);
          }
      }
      return root;
}



int main(){
  TreeNode* root=new TreeNode(1);
  root->left=new TreeNode(2);
  root->right=new TreeNode(3);
  root->left->left=new TreeNode(4);
  string str=serialize(root);
  cout<<"after serialization"<< endl;
  cout<<str;
  cout<<endl;
      TreeNode* rootFinal=      deserialize(str);
      cout<<"after deserialization " <<endl;
      cout<<rootFinal->val;
  return 0;
}

/*
 /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root){
            return "[]";
        }
        ostringstream out;
        queue<TreeNode* > q;
        q.push(root);
        while(! q.empty()){
              TreeNode* curr= q.front();
              q.pop();
              if(curr){
                q.push(curr->left);
                q.push(curr->right);
                out<<curr->val<<" ";
              }
              else{
                    out<<"null ";
              }
        }
        string res=   out.str();
        res.pop_back();
        // cout<<res<<"x";
        return res;
    }

    TreeNode* deserialize(string data) {
            if(data=="[]"){
                return nullptr;
            }
            istringstream in(data);
            string val;
            in>>val;
            queue<TreeNode* > q;
            TreeNode* root=new TreeNode(stoi(val));
            q.push(root);
            while(! q.empty()){
                   TreeNode* curr= q.front();q.pop();
                   in>> val;
                   if(val!="null")
                   {
                    curr->left = new TreeNode(stoi(val));
                    q.push(curr->left);
                   }
                   in>> val;
                if(val!="null")
                  { 
                    curr->right = new TreeNode(stoi(val));
                    q.push(curr->right);
                  }
            }
            return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));   
*/
