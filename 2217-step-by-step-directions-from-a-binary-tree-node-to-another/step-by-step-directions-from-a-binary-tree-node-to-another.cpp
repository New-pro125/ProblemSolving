class Solution {
public:
    TreeNode* findLCA(TreeNode* root, int p, int q) {
        // Base case: If root is null or root is either p or q
        if (root == nullptr || root->val == p || root->val == q) return root;
        
        TreeNode* left = findLCA(root->left, p, q);
        TreeNode* right = findLCA(root->right, p, q);
        
        if (left != nullptr && right != nullptr) return root;
        
        return left != nullptr ? left : right;
    }

    bool buildPath(TreeNode* root, int val, string& path) {
        if (!root) return false;
        if (root->val == val) return true;
        
        path.push_back('L');
        if (buildPath(root->left, val, path)) return true;
        path.pop_back();
        
        path.push_back('R');
        if (buildPath(root->right, val, path)) return true;
        path.pop_back();
        
        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* LCA = findLCA(root, startValue, destValue);
        string startPath, endPath;
        buildPath(LCA, startValue, startPath);
        buildPath(LCA, destValue, endPath);
        
        for (char& c : startPath) {
            c = 'U';
        }
        
        return startPath + endPath;
    }
};