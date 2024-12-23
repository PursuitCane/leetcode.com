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
    int minimumOperations(TreeNode* root) {
        int count = 0;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            vector<int> vec1, vec2;
            while (size--) {
                auto* node = que.front(); que.pop();
                vec1.push_back(node->val);
                vec2.push_back(node->val);
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            sort(vec2.begin(), vec2.end());
            unordered_map<int, int> mp;
            for (int i = 0; i < vec2.size(); i++) {
                mp[vec2[i]] = i;
            }

            for (int i = 0; i < vec1.size(); i++) {
                while (mp[vec1[i]] != i) {
                    count++;
                    swap(vec1[i], vec1[mp[vec1[i]]]);
                }
            }
        }
        return count;
        
    }
};
