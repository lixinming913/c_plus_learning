/*  二叉树中特殊节点个数计算
 *  叶子节点个数：N0
 *  有两个儿子的节点：N2
 *  仅有右子节点NR, 仅有左子节点NL
 */
 
 struct BinaryTreeNode{
 int  data;
 struct BinaryTreeNode *left, *right;
 }
 
 int N0 = 0, NR = 0, NL = 0, N2 = 0;
 class Solution
 {
    publc:
        void count(BinaryTreeNode *root)
        {
            if(root->left != NULL) {
                if(root->right != NULL)
                    N2++;
                else
                    NL++
            }
            else if(root->right != NULL) {
                NR++;
            }
            else
                N0++;
                
            if(root->left != NULL)
                count(root->left);
            
            if(root->right != NULL)
                count(root->right);
        }
 };