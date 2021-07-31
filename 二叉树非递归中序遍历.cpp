class Solution {
public:
    //中序遍历 左根右
    void center(TreeNode* root,vector<int> &arr_int)
    {
        stack<TreeNode*> TreeStact;
        if(root == nullptr) return;
        TreeNode *cur = root;
        while(cur != NULL || !TreeStact.empty())
        {
            if(cur != NULL)
            {
                TreeStact.push(cur);  //注意这个用于一直往左边找当左边为空的时候才会进行出栈操作
                cur = cur->left;
            }
            else
            {
                TreeNode *node = TreeStact.top();
                TreeStact.pop();
                arr_int.push_back(node->val);
                cur = node->right;  //出栈后把节点置为right 因为找left的时候已经把中间丢到栈里面了
            }
        }

    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> arr_int;
        center(root,arr_int);
        return arr_int;
    }
};
