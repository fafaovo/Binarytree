class Solution {
public:
    void pre(TreeNode* root,vector<int> &arr_int)
    {
        stack<TreeNode*> Treestack; //用栈容器来遍历
        if(root == nullptr)
            return;
        Treestack.push(root);
        while(!Treestack.empty())
        {
            TreeNode* node = Treestack.top();
            Treestack.pop();
            arr_int.push_back(node->val);  //出栈并且把元素丢到数组中
            if(node->right)Treestack.push(node->right);  //想象一下栈,所以得右边先入栈
            if(node->left)Treestack.push(node->left);   //然后才是左边入栈
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> arr_int;
        pre(root,arr_int);
        return arr_int;
    }
};
