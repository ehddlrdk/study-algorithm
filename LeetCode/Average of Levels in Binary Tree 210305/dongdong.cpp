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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> answer;
        queue<TreeNode*> q;
        
        // 연결되어있지 않은 node들 까지 고려한 것.
        if (!root)
            return answer;
        
        q.push(root);
        
        while(!q.empty()) {
            int size = q.size();
            double sum = 0;
            for(int i = 0; i < size; i++) {
                TreeNode* cur = q.front();
                q.pop();
                sum += cur->val;
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
            answer.push_back(sum / size);
        }
        
        // 연결되어있지 않은 node 고려안한 것.
        // queue<pair<TreeNode*, int>> q;
        // vector<pair<int,int>> avg;
        // double sum = 0;
        // int cnt = 0;
        // int level = 0;
        // if (root == NULL)
        //     return answer;
        // q.push(make_pair(root, level));
        // while(!q.empty()) {
        //     TreeNode* cur = q.front().first;
        //     int level = q.front().second;
        //     q.pop();
        //     avg.push_back(make_pair(cur->val, level));
        //     if (cur->left)
        //         q.push(make_pair(cur->left, level+1));
        //     if (cur->right)
        //         q.push(make_pair(cur->right, level+1));
        // }
        // for(int i = 0; i < avg.size(); i++) {
        //     if (avg[i].second == level) {
        //         cnt++;
        //         sum += avg[i].first; 
        //     } 
        //     if (avg[i].second == level+1 || i == avg.size() - 1) {
        //         answer.push_back(sum / cnt);
        //         level = level + 1;
        //         cnt = 0;
        //         sum = 0;
        //         cnt ++;
        //         sum += avg[i].first;
        //     }
        // }
        return answer;
    }
};