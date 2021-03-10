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
        TreeNode* hong = NULL;
        
        //depth가 1로 주어질 대
        if(d == 1) {
            TreeNode* new_root = new TreeNode(v, root, NULL);
            return new_root;
        }
        
        queue<pair<TreeNode*, int>> BFS;
        BFS.push(make_pair(root, 1));
        
        //우선 d-1까지의 노드들을 Queue에 저장해둔다
        while(!BFS.empty()) {
            pair<TreeNode*, int> cur = BFS.front();
            
            if(cur.second == d-1) {
                break;
            }
            BFS.pop();
            
            if(cur.first->left != NULL)
                BFS.push(make_pair(cur.first->left, cur.second + 1));
            if(cur.first->right != NULL)
                BFS.push(make_pair(cur.first->right, cur.second + 1));
        }
        
        //d-1 노드들을 탐색하면서 d 깊이에 TreeNode 생성
        while(!BFS.empty()) {
            pair<TreeNode*, int> cur = BFS.front();
            BFS.pop();
            
            TreeNode* new_left = new TreeNode(v);
                
            new_left->left = cur.first->left;
            cur.first->left = new_left;
            
            TreeNode* new_right = new TreeNode(v);
                
            new_right->right = cur.first->right;
            cur.first->right = new_right;
        }
        
        return root;
    }
};