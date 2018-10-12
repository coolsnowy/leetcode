/*
 * Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
 */

#include <cstdio>
#include <vector>

using std::vector;


//	Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) { }
};

/*
 * see prompts!
 * The basic idea is here:
Say we have 2 arrays, PRE and IN.
Preorder traversing implies that PRE[0] is the root node.
Then we can find this PRE[0] in IN, say it's IN[5].
Now we know that IN[5] is root, so we know that IN[0] - IN[4] is on the left side, IN[6] to the end is on the right side.
Recursively doing this on subarrays, we can build a tree out of it :)


 */
class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if(inorder.empty()) {
			return nullptr;
		}
		return build(0, 0, inorder.size() - 1, preorder, inorder);
	}
	TreeNode* build(int preStart, int inStart, long int inEnd, vector<int>& preorder, vector<int>& inorder) {
		if(preStart > preorder.size() - 1 || inStart > inEnd) {
			return nullptr;
		}
		TreeNode *root = new TreeNode(preorder[preStart]);
		int inIndex = 0;
		for(int i = inStart;i <= inEnd; i++) {
			if(inorder[i] == preorder[preStart]) {
				inIndex = i;
				break;
			}
		}
		root->left = build(preStart + 1, inStart, inIndex - 1, preorder, inorder);
		root->right = build(preStart + inIndex - inStart + 1, inIndex + 1, inEnd, preorder, inorder);
		return root;
	}
};

int main() {
	vector<int> preorder{3,9,20,15,7};
	vector<int> inorder{9,3,15,20,7};
}