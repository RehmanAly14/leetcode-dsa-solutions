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
         queue<TreeNode*>q;
        vector<vector<int>>res;
        if(root==NULL) return {};
        q.push(root);
        bool lefttoright=true;
        while(!q.empty()){
            int lvlsize=q.size();
            int first=0;
            int last=lvlsize-1;
            vector<int>tmp(lvlsize);
            while(lvlsize--){
                TreeNode* t=q.front();
                q.pop();
                if(lefttoright){
                    tmp[first++]=t->val;
                }
                else{
                    tmp[last--]=t->val;
                }
                if(t->left){
                    q.push(t->left);
                }
                 if(t->right){
                    q.push(t->right);
                }
            }
            res.push_back(tmp);
            lefttoright=!lefttoright;
        }
        return res;
        
    }
};
