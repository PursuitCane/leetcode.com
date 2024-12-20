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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        int level = 0;
        while (!que.empty()) {
            int n = que.size();
            if (level & 1) {
                vector<TreeNode*> vec;
                for (int i = 0; i < n; i++) {
                    auto* node = que.front(); que.pop();
                    vec.push_back(node);
                    if (node->left) que.push(node->left);
                    if (node->right) que.push(node->right);
                }

                for (int i = 0; i < n/2; i++) {
                    swap(vec[i]->val, vec[n-i-1]->val);
                }
            } else {
                while (n--) {
                    auto* node = que.front(); que.pop();
                    if (node->left) que.push(node->left);
                    if (node->right) que.push(node->right);
                }
            }
            level++;
        }        

        return root;
        
    }
};
