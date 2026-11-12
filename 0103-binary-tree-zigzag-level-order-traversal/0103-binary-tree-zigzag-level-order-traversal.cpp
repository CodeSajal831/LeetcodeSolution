/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        int flag=0;
       
       
        while(!q.empty()){
             int s=q.size();
         vector<int> ds;
         for(int i=0;i<s;i++){
        
           TreeNode* front=q.front();
           q.pop();
           if(front->left!=NULL){
            q.push(front->left);
           }
           if(front->right!=NULL){
            q.push(front->right);
           }
          
            ds.push_back(front->val);
            }
              if(flag==0){
                ans.push_back(ds);
            }
            if(flag==1){
              reverse(ds.begin(), ds.end());
              ans.push_back(ds);
         }
          if(flag==0) flag=1;
          else flag=0;
        }
        return ans;
    }
};