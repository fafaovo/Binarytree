//平衡二叉树 ：110 https://leetcode-cn.com/problems/balanced-binary-tree/submissions/
class Solution {
public:
    int getDepth(TreeNode* root)
    {
        if(root == nullptr)
            return 0;
        int left = getDepth(root->left);
        if(left == -1) //当有一次是-1的时候后续就一直跳
            return -1;
        int right = getDepth(root->right);
        if(right == -1)
            return -1;
        int result;
        if(abs(left-right) > 1)
        //这里用于处理节点，当节点左右都有的时候结果是0
        //当一个有一个没是1 当一个有一个没有并且持续多次的时候就会出现2
            result = -1;
        else
        //此处两边都会+1
            result = 1 + max(left,right);
        return result;
    }
    bool isBalanced(TreeNode* root) {
        return getDepth(root) == -1 ? false:true;
    }
};
