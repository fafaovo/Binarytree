class Solution {
public:
    int pre(TreeNode* root)
    {
        if(root == NULL)
            return 0;  //为空的时候是不计算的
        int left = pre(root->left);
        int right = pre(root->right);
        return max(left,right) + 1;
    }
    int maxDepth(TreeNode* root) {
        return pre(root);
    }
};
