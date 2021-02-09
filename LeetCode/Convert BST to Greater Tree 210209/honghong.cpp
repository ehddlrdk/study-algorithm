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
    TreeNode* convertBST(TreeNode* root) {
        
        if(root != nullptr)
            DFS(0, root); 
        
        return root;
    }
    
	//num = 왼쪽 노드로 넘겨줄 값 저장
    int DFS(int num, TreeNode* cur) {
        
        int ini_value = cur->val;
        int right_sum = 0;
        int left_sum = 0;
             
        //오른쪽 탐색
        if(cur->right != nullptr)
            right_sum = DFS(num, cur->right);   
          
        //왼쪽 탐색
        if(cur->left != nullptr)
            left_sum = DFS(right_sum + num + ini_value, cur->left);
        
        cur->val = num + ini_value + right_sum;
        
        return ini_value + right_sum + left_sum;
    }
};