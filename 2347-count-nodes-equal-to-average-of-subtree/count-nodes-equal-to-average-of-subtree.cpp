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
    bool leaf(TreeNode* root){
        return (root->left==NULL && root->right==NULL);
    }
    int ct = 0;
    pair<int,int> f(TreeNode* root){
        if(root==NULL){
            
            return {0,0};
        }
        //a++;
        pair<int,int> left = f(root->left);
        pair<int,int> right = f(root->right);
        int tmp = left.first + right.first + root->val;
        int n = 1 + left.second + right.second;
        if(tmp/n == root->val){
            ct++;
        }
        return {left.first+right.first+root->val,n};
    }
    int averageOfSubtree(TreeNode* root) {
        int a = 0;
        pair<int,int> sum = f(root);
        return ct;
    }
};