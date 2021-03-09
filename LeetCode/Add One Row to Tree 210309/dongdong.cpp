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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        // root 존재여부 확인
        // d-1의 자식노드로 v값을 가지는 노드를 왼 오 추가.
        // 기존에 d-1에 붙어있던 자식 노드는 왼쪽노드는 추가된 왼쪽노드에 왼쪽 자식노드로 오른쪽도 마찬가지로.
        queue<pair<TreeNode*, int>> q;
        int depth = 1;
        if (root == nullptr)
            return nullptr;
        if (d == 1) {
            TreeNode* addNode = new TreeNode(v, root, nullptr);
            return addNode;
        }
        
        q.push(make_pair(root, depth));
        while (!q.empty()) {
            TreeNode* cur = q.front().first;
            int cur_depth = q.front().second;
            q.pop();
            if (cur->left != nullptr)
                q.push(make_pair(cur->left, cur_depth + 1));
            if (cur->right != nullptr)
                q.push(make_pair(cur->right, cur_depth + 1));
            if (cur_depth == d)
                break;
            if (cur_depth == d-1) {
                TreeNode* addNodeLeft = new TreeNode(v, cur->left, nullptr);
                TreeNode* addNodeRight = new TreeNode(v, nullptr, cur->right);
                cur->left = addNodeLeft;
                cur->right = addNodeRight;
            }
        }
        return root;
    }
};