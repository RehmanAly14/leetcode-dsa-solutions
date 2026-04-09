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
    stack<TreeNode*> asc; 
    stack<TreeNode*> des;
    void pushLeft(TreeNode* node) {
        while (node) {
            asc.push(node);
            node = node->left;
        }
    }
    void pushRight(TreeNode* node) {
        while (node) {
            des.push(node);
            node = node->right;
        }
    }
    TreeNode* getNextSmall() {
        TreeNode* node = asc.top();
        asc.pop();
        pushLeft(node->right);
        return node;
    }
    TreeNode* getNextLarge() {
        TreeNode* node = des.top();
        des.pop();
        pushRight(node->left);
        return node;
    }

    bool findTarget(TreeNode* root, int k) {
        if(root ==NULL) return false;
        pushLeft(root);
        pushRight(root);

        TreeNode* i = getNextSmall();
        TreeNode* j = getNextLarge();
        while(i!=j){
            int sum = i->val + j->val;
            if(sum==k){
                return true;
            }
            if(sum>k){
                j=getNextLarge();
            }
            else{
                i=getNextSmall();
            }
        }
        return false;
    }
};
