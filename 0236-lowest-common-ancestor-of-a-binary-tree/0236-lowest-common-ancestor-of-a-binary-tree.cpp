class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        // If root is NULL, or root is one of p/q
        if (root == NULL || root == p || root == q) {
            return root;
        }

        // Search in left subtree
        TreeNode* left = lowestCommonAncestor(root->left, p, q);

        // Search in right subtree
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // If p and q are found on different sides
        if (left != NULL && right != NULL) {
            return root;
        }

        // Return whichever side contains p or q
        if (left != NULL) {
            return left;
        }

        return right;
    }
};