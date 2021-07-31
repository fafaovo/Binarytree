//后序遍历 左右根

class Solution {
public:
    void footer(TreeNode* root,vector<int> &arr_int)
    {
        stack<TreeNode*> TreeStack;
        if(root == nullptr) return;
        TreeStack.push(root);
        while(!TreeStack.empty())
        {
            TreeNode* cur = TreeStack.top();
            TreeStack.pop();
            arr_int.push_back(cur->val);
            if(cur->left) TreeStack.push(cur->left); //这里是先left入栈然后才是right  中序遍历是反过来
            if(cur->right) TreeStack.push(cur->right);
        }
        reverse(arr_int.begin(),arr_int.end()); //翻转整个数组
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> arr_int;
        footer(root,arr_int);
        return arr_int;
    }
};
