class Solution {
    struct TreeNode* pre = NULL;
public:
    bool isValidBST(TreeNode* root) {
		if (root)
		{
			if (!isValidBST(root->left))
			{
				return false;
			}
			
			if (pre && pre->val >= root->val)
			{
				return false;
			}
			
			pre = root;
			
			if (!isValidBST(root->right))
			{
				return false;
			}
			
			return true;
		}
		else
		{
			return true;
		} 
    }
};