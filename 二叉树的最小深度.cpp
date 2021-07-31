class Solution {
public:
    //解题方法：使用队列，直到找到一个左边和右边都是为空的就返回
    int minDepth(TreeNode* root) {
        queue<TreeNode*> que;
        if(root == nullptr)
            return 0;
        que.push(root);
        int count = 1;
        while(!que.empty())
        {
            int size = que.size();
            for(int i = 0; i < size; i++)
            {
                TreeNode* cur = que.front();
                que.pop();
                if(cur->left) que.push(cur->left);
                if(cur->right) que.push(cur->right);
                if(!cur->left && !cur->right)
                    return count;
            }
            count++;
        }
        return count;
    }
};
