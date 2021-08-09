class Solution {
public:
//用于比较两棵树是否一致
    bool compare(TreeNode* q,TreeNode* p)
    {
        if(!q && !p) return true;
        if(!q || !p) return false;
        if(q->val != p->val) return false;
        return compare(q->left,p->left) && compare(q->right,p->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        queue<TreeNode*> que;
        if(root != nullptr)
            que.push(root);
        if(subRoot == nullptr)
            return true;
        bool flag = false;
        while(!que.empty())
        {
            int size = que.size();
            for(int i = 0; i < size;i++)
            {
                //利用层序遍历取主树中的每一个节点和子树进行比较
                TreeNode* cur = que.front();
                que.pop();
                flag =  compare(cur,subRoot);
                if(flag == true)
                    return true;
                if(cur->left) que.push(cur->left);
                if(cur->right) que.push(cur->right);
            }
        }
        return false;
    }
};
