/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        if(root==NULL)
            return ans;
        q.push(root);
        while(!q.empty())
        {
            int currentsize = q.size();
            vector<int>level;
            while(currentsize>0)
            {
                TreeNode* currentnode = q.front();
                q.pop();
                level.push_back(currentnode->val);
                currentsize--;
                
                if(currentnode->left!=NULL)
                    q.push(currentnode->left);
                if(currentnode->right!=NULL)
                    q.push(currentnode->right);
            }
            ans.push_back(level);
        }
        return ans;
    }
};