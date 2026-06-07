/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    pair<int,int> fun(TreeNode* root) {

        if (root == NULL) {
            return {0, 0};
        }

        auto left = fun(root->left);
        auto right = fun(root->right);

        // Rob current node
        int rob = root->val + left.second + right.second;

        // Skip current node
        int skip = max(left.first, left.second)
                 + max(right.first, right.second);

        return {rob, skip};
    }

    int rob(TreeNode* root) {

        auto ans = fun(root);

        return max(ans.first, ans.second);
    }
};
