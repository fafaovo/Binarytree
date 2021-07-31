//层序遍历即每一层每一层的遍历
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> que;
        if(root != nullptr)
        {
            que.push(root);
        }
        vector<vector<int>> result;
        while(!que.empty()) //栈为空时结束循环
        {
            vector<int> temp;
            int size = que.size(); //后续会进行入队操作，为了得到上一层的n个元素，所以这个size是记录n元素的个数已确保出队次数符合
            for(int i = 0;i < size;i++)
            {
                TreeNode *cur = que.front();
                que.pop();
                temp.push_back(cur->val);
                if(cur->left) que.push(cur->left); //把left和right都丢进去
                if(cur->right) que.push(cur->right);
            }
            result.push_back(temp); //最后把一层的数组丢到二维数组中
        }
        return result;
    }
};
