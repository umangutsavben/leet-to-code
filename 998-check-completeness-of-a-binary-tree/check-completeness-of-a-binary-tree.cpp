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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*>q;
        if(root==NULL)return true;
        q.push(root);
        int lvl = 0;
        int flag1 = 0;
        int flag2 = 0;
        while(!q.empty()){
            long long int num = (1<<lvl);
            if(q.size()!=num){
                flag1=1;
            }
            int n = q.size();
            for(int i=0;i<n;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left && flag2==1) return false;
                if(node->right && flag2==1) return false;
                if(node->left==NULL)flag2=1;
                else{
                    q.push(node->left);
                }
                if(node->right==NULL)flag2=1;
                else if(node->right&&flag2==1){
                    return false;
                }
                else if(node->right && flag2==0){
                    q.push(node->right);
                }
            }
        }
        return true;
    }
};