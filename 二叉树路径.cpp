class Solution {
public:
    void que(TreeNode* root,vector<int> &temp,vector<string> &result)
    {
        temp.push_back(root->val);
        if(root->left == nullptr && root->right == nullptr)
        {
            string cur;
            for(int i = 0; i < temp.size()-1;i++)
            {
                cur+= to_string(temp[i]);
                cur+="->";
            }
            cur+= to_string(temp[temp.size()-1]); //最后不需要箭头
            result.push_back(cur);
            return;
        }
        if(root->left)
        {
            que(root->left,temp,result);
            temp.pop_back();   //删掉数组最后一位,实现回溯
        }
        if(root->right)
        {
            que(root->right,temp,result);
            temp.pop_back();   //删掉数组最后一位,实现回溯
        }

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        vector<int> temp;
        string path;
        if(root == nullptr)
            return result;
        que(root, temp,result);
        return result;
    }
};
