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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> mp;
        int n=inorder.size();
        for(int i=0;i<n;i++) mp[inorder[i]]=i;
        TreeNode* root=build(postorder,0,n-1,inorder,0,n-1,mp);
        return root;
    }
    TreeNode* build(vector<int>& postorder,int post_start,int post_end,vector<int>& inorder,int in_start,int in_end,map<int,int>& mp){
        if(post_start>post_end || in_start>in_end) return NULL;
        // if(post_start==post_end) return new TreeNode(postorder[post_end]);
        // if(in_start==in_end) return new TreeNode(inorder[in_end]);
        TreeNode* root=new TreeNode(postorder[post_end]);
        int inroot=mp[root->val];
        int size=inroot-in_start;
        root->left=build(postorder,post_start,post_start+size-1,inorder,in_start,inroot-1,mp);
       root->right=build(postorder,post_start+size,post_end-1,inorder,inroot+1,in_end,mp);
        return root;
    }
};