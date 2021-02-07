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
		// BFS
		// node level에 존재하는 node중 가장 오른쪽에 있는 node의 숫자를 answer에 push
		queue<TreeNode*> rightView;
		vector<int> answer;
		int right_num = 0;
		int size = 0;

		if (root != NULL) {
			rightView.push(root);
		}

		while (!rightView.empty()) {
			size = rightView.size();
			for (int i = 0; i < size; i++) {
				TreeNode* node = rightView.front();

				if (i == size - 1) {
					answer.push_back(node->val);
				}

				if (node->left) {
					rightView.push(node->left);
				}

				if (node->right) {
					rightView.push(node->right);
				}
				rightView.pop();
			}

		}
		return answer;
	}
};