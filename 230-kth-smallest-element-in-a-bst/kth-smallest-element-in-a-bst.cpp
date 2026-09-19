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
    void f(TreeNode* root,int& ct,int k,int& ans){
        if(root == NULL) return;
        
        
        if(root->left) {
            //ct++;
            f(root->left,ct,k,ans);
        }
        ct++;
        if(ct == k){
            ans = root->val;
            return;
        }
        if(root->right) {
            //ct++;
            f(root->right,ct,k,ans);
        }
        //root->val = left + right + 1;
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        int ct = 0;
        int ans;
        f(root,ct,k,ans);
        return ans;
    }
};