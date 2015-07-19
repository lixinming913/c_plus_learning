/*
 * Path Sum II 
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
 * For example:Given the below binary tree and sum = 22,
 */



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void findpath(TreeNode* root, int sum, vector<int> &path, vector<vector<int>> &paths)
    {
        if(root != NULL)
            path.push_back(root->val);
        else
            return;
            
        if(sum - root->val == 0 && root->left == NULL && root->right == NULL)
            paths.push_back(path);
        
        findpath(root->left, sum - (root->val), path, paths);
        findpath(root->right, sum - (root->val), path, paths);
        
        path.pop_back();
    }


    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> paths;
        vector<int> path;
        
        findpath(root, sum, path, paths);
        return paths;
    }
};