/*
 *  Sum Root to Leaf Numbers 
 *  Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
 *  An example is the root-to-leaf path 1->2->3 which represents the number 123.
 *  Find the total sum of all root-to-leaf numbers.
 *  The root-to-leaf path 1->2 represents the number 12.
 *  The root-to-leaf path 1->3 represents the number 13.
 *  Return the sum = 12 + 13 = 25.
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
    void computeSum(TreeNode* root, int &sum, int number)
    {
        if(root == NULL)
            return;
        
        number += root->val;
        
        if(root->left == NULL && root->right == NULL) {
            sum += number;
            number /= 10;
        }
            
        computeSum(root->left, sum, number * 10);
        computeSum(root->right, sum, number * 10);
    }
    
    int sumNumbers(TreeNode* root) {
        if(root == NULL)
            return 0;
            
        int sum = 0;
        int number = 0;
        computeSum(root, sum, number); 
        
        return sum;
    }
};