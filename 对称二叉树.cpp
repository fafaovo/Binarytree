//题目源自： 101.对称二叉树 https://leetcode-cn.com/problems/symmetric-tree/

//递归方式
class Solution {
public:
    bool symm(TreeNode* left,TreeNode* right)
    {
        if(left == nullptr && right != nullptr) return false;
        else if(left != nullptr && right == nullptr) return false;
        else if(left == nullptr && right == nullptr ) return true;
        else if(left->val != right->val) return false;

        //上面用于判断节点是否对称 一个为空一个不为空 或者 数组不对就不对称了

        bool Outside = symm(left->left,right->right); //这边是将左边的左边和右边的右边进行递归 也就是外层的节点
        bool Inside = symm(left->right,right->left); //然后才是内层的节点
        bool result = Outside && Inside;
        return result;
    }
    bool isSymmetric(TreeNode* root) {
        return symm(root->left,root->right);
    }
};

//非递归方式 栈和队列都可以 换一下名字就好了
//队列就先判断外层然后判断内层
//栈就先判断内层然后判断外层
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> que;
        if(root == nullptr)
            return true;
        que.push(root->left);
        que.push(root->right);

        while(!que.empty())
        {
            TreeNode* left = que.front();
            que.pop();;
            TreeNode* right = que.front();
            que.pop();
            if(!left && !right) //假设两个都是空就跳出本次循环了 此时堆已经没有元素了
                continue;
            // 左右⼀个节点不为空，或者都不为空但数值不相同，返回false
            if(!left ||  !right || (left->val != right->val))
                return false;
            que.push(left->left);
            que.push(right->right);
            que.push(left->right);
            que.push(right->left);
        }
        return true;
    }
};
