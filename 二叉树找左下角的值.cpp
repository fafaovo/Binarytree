//来源 513. 找树左下角的值  https://leetcode-cn.com/problems/find-bottom-left-tree-value/

//解题思路，层序遍历
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> que;
        if(root != nullptr)
            que.push(root);
        int min = 0;
        while(!que.empty())
        {
            int size =que.size();
            for(int i = 0 ; i < size; i++)
            {
                TreeNode* cur = que.front();
                que.pop();
                if(i == 0) min = cur->val; //记录最后一行第一个,这个很重要
                if(cur->left) que.push(cur->left);
                if(cur->right) que.push(cur->right);
            }
        }
        return min;
    }
};
