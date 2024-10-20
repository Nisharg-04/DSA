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
    void delnode(TreeNode* &node,vector<TreeNode*>&ans,unordered_set<int>&mpp){
        if(node == NULL)return;
        if(node->left)delnode(node->left,ans,mpp);
        if(node->right)delnode(node->right,ans,mpp);
        if(mpp.find(node->val)!=mpp.end()){
            if(node->left)ans.push_back(node->left);
            if(node->right)ans.push_back(node->right);
            node=NULL;
        }

    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*>ans;
        unordered_set<int>mpp;
        for(int i=0;i<to_delete.size();i++){
            mpp.insert(to_delete[i]);
        }
        delnode(root,ans,mpp);
        if(root)ans.push_back(root);
        return ans;
    }
};