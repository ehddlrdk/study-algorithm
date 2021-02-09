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
		//오른쪽 쭉 탐색 후 왼쪽 넣어서 탐색. dfs느낌 
		int sum = 0;
		map<int, int> check_node; //방문했는지 체크
		stack<TreeNode*> s;

		if (root != nullptr) {
			s.push(root);
		}

		while (!s.empty()) {
			TreeNode* cur = s.top();
			// 오른쪽부터 탐색
			if (cur->right != nullptr && check_node[cur->val] != 1) {
				s.push(cur->right);
				check_node[cur->val] = 1;
			}
			else {
				sum += cur->val;
				cur->val = sum;
				cout << cur->val << endl;
				s.pop();
				// pop했을 때 왼쪽 탐색해야할 것이 있으면 push
				if (cur->left != nullptr) {
					s.push(cur->left);
				}
			}
		}
		// 갱신한 TreeNode* root를 반환.
		return root;
	}
};