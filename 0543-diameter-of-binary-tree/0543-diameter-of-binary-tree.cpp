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
     int maxi = -1;
public:
    int findheight(TreeNode* root){
        if(root==NULL) return 0;
        int left = findheight(root->left);
        int right = findheight(root->right);
        return 1 + max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
    
        int lh = findheight(root->left);
        int rh = findheight(root->right);
        
        maxi = max(maxi, lh+rh);
        
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        
        return maxi;
    }
};