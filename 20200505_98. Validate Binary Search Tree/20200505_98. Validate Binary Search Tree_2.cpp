class Solution {
public:
    bool valid(TreeNode* root,long int lower, long int higher){
        if (!root) return true;//空节点必然是BST
        if (root->val >= higher || root->val <= lower)    
            return false;//二叉搜索树必然保持左右子树不超过当前的最大值和最小值
        return (valid(root->left, lower, root->val)&&
                valid(root->right, root->val, higher));
    }
    bool isValidBST(TreeNode* root) {
        return valid(root, LONG_MIN, LONG_MAX);
    }
};