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
vector<vector<int>>res;
vector<int>nd;
void fun(TreeNode* root,int sum,int target){
    if(root==NULL) return;
    sum=sum + root->val;
    nd.push_back(root->val);
    if(root->left==NULL && root->right==NULL){
        if(sum==target){
            res.push_back(nd);
        }
         nd.pop_back();
        return;
    }
    fun(root->left,sum,target);
    fun(root->right,sum,target);
     nd.pop_back();
    return;
}
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        fun(root,0,targetSum);
        return res;
        
    }
};
