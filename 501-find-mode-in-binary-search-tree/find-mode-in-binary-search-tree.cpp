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
    void dfs(TreeNode* root,int &prev,int &currfreq,int &maxfreq,vector<int>&ans){
        if(root->left)
            dfs(root->left,prev,currfreq,maxfreq,ans);
        int val = root->val;
        if(prev==val){
            currfreq++;
        }
        else{
            prev = val;
            currfreq = 1;
        }
        if(maxfreq==currfreq){
            ans.push_back(val);
        }
        else if(maxfreq<currfreq){
            ans = {val};
            maxfreq = currfreq;
        }
        if(root->right){
            dfs(root->right,prev,currfreq,maxfreq,ans);
        }
    }
    vector<int> findMode(TreeNode* root) {
        vector<int>ans;
        int prev=1e9, currfreq=0, maxfreq=0;
        if(root==NULL){
            return ans;
        }
        dfs(root,prev,currfreq,maxfreq,ans);
        return ans;

    }
};