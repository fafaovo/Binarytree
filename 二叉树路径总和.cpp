//来源 113. 路径总和 II   https://leetcode-cn.com/problems/path-sum-ii/


//解题思路 前序遍历 进行回溯算法 定义个数组 当遇到叶子节点的时候进行回溯 然后将数组中的全部元素相加最终和targetSum比较 如果是相等,那么就把这个路径丢到二维向量中
class Solution {
public:
    //根节点 数组元素总和需相等的值 用于回溯的数组 用于记录的二维数组
    void traversal(TreeNode* root,int targetSum,vector<int> &temp,vector<vector<int>> &result)
    {
        temp.push_back(root->val);  //把元素丢到向量中
        if(!root->left && !root->right)
        {
            int count = 0;
            for(int i = 0; i < temp.size(); i ++)
                count+=temp[i];
            if(count == targetSum)
            {
                result.push_back(temp);
            }
            return;
        }
        if(root->left)
        {
            traversal(root->left,targetSum,temp,result);
            temp.pop_back();
        }
        if(root->right)
        {
            traversal(root->right,targetSum,temp,result);
            temp.pop_back();
        }


    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result; // 存放结果
        if(root == nullptr)
            return result;
        vector<int> temp; //用于回溯
        traversal(root,targetSum,temp,result);
        return result;
    }
};
