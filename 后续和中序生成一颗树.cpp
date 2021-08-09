//106. 从中序与后序遍历序列构造二叉树
//https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(postorder.size() == 0) return NULL;
        //后续的节点都是当前的中间节点
        int rootValse = postorder[postorder.size()-1];
        //创建节点
        TreeNode* root = new TreeNode(rootValse);
        if(postorder.size() == 1)
            return root;
        //在中序中找到当前的中间节点,用于切割
        int i;
        for(i = 0; i <inorder.size(); i++)
        {
            if(inorder[i] == rootValse)
                break;
        }
        //舍弃掉最后一个节点
        //切割中序数组
        vector<int> inoleft(inorder.begin(),inorder.begin()+i);
        vector<int> inoright(inorder.begin()+i+1,inorder.end());
        //切割后序数组
        postorder.resize(postorder.size()-1);
        vector<int> postleft(postorder.begin(),postorder.begin() + i);
        vector<int> postright(postorder.begin()+i,postorder.end());

        root->left = buildTree(inoleft,postleft);
        root->right = buildTree(inoright,postright);

        //解题思路 取后续遍历最后一个元素在中序遍历的位置来确定分割操作数，从头分割到分割树为left.从分割树+1切割到末尾为right，然后递归，
        return root;






    }
};
