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
    int kthSmallest(TreeNode* root, int k) {
        int cur_k = 0;
        stack<pair<TreeNode*, bool>> s;
        s.push(make_pair(root, false));
        while(!s.empty()) {
            pair<TreeNode*, bool> elm = s.top(); s.pop();
            if (elm.second){
                cur_k ++;
                if (cur_k == k) return elm.first->val;
            }
            else {
                if (elm.first->right)
                    s.push(make_pair(elm.first->right, false));
                s.push(make_pair(elm.first, true));
                if (elm.first->left)
                    s.push(make_pair(elm.first->left, false));
            }
        }
        return -1;
    }
};
