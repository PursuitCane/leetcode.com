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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr) return ans;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            int num = que.front()->val;
            while (size--) {
                auto* node = que.front();
                num = max(num, node->val); que.pop();
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            ans.push_back(num);
        }
        return ans;
        
    }
};
