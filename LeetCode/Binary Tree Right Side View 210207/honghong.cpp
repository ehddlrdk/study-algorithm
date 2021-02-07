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
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> output;
        queue<pair<int, int>> level;
        queue<TreeNode*> BFS;
        
        BFS.push(root);
        level.push(make_pair(1,1));
        
        if(root == nullptr) {
            return output;
        }
        
        int rightside = 1;
        int rightside_val = root->val;
        int saved_level = 1;
        
        while(!BFS.empty()) {
            TreeNode* cur_node = BFS.front();
            pair<int, int> cur_level = level.front();
            
            BFS.pop();
            level.pop();
            
            //Level 깊어질 때, 저장된 가장 오른쪽에 있는 값을 Output에 저장
            if(saved_level != cur_level.first) {
                output.push_back(rightside_val);
                rightside = 0;
            }   
            
            //같은 Level에서 가장 오른쪽에 있는 값을 저장
            if(cur_level.second >= rightside) {
                rightside = cur_level.second;
                rightside_val = cur_node->val;
            }
            
            //왼쪽 노드 Push
            if(cur_node->left != nullptr) {
                BFS.push(cur_node->left);
                level.push(make_pair(cur_level.first+1, cur_level.second*2-1));
            }
        
            //오른쪽 노드 Push
            if(cur_node->right != nullptr) {
                BFS.push(cur_node->right);
                level.push(make_pair(cur_level.first+1, cur_level.second*2));
            }
            
            saved_level = cur_level.first;
        }

        //마지막 Level에서 가장 오른쪽에 있는 값을 저장
        output.push_back(rightside_val);

        return output;
    }
};