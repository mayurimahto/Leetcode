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
    vector<int> inorderTraversal(TreeNode* root) {
        //Morris Traversal
        vector<int>inorder;
        TreeNode* curr = root;
        
        while(curr!=NULL){
            //Case-1
            if(curr->left ==NULL){
                inorder.push_back(curr->val);
                curr = curr->right;
            }
            //Case-2,3
            else{
                TreeNode* prev = curr->left;
                
                while(prev->right && prev->right!=curr){
                    prev = prev->right;
                }
                
                if(prev->right==NULL){
                    prev->right = curr;
                    curr = curr->left;
                }
                else{
                    //cutting the thread
                    prev->right = NULL;
                    inorder.push_back(curr->val);
                    curr = curr->right; 
                }
            }
        }
        return inorder;
    }
};