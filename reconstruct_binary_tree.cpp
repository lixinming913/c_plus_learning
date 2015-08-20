/*重建二叉树*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
     struct TreeNode* reConstructTree
    (vector<int> pre, vector<int> in, int start_pre, int end_pre, int start_in, int end_in)
    {
        int rootVal = pre[0];
        struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        root->val = rootVal;
   		root->left = root->right = NULL;
        
        if(start_pre == end_pre) {
            if(start_in == end_in && pre[start_pre] == in[start_in]) 
                return root;
            else
                return NULL;
        }
        
        /*找到中序中根节点的位置*/
        int root_in = start_in;
        while(root_in <= end_in && in[root_in] != rootVal) {
            ++root_in;
        }
        if(root_in == end_in && in[root_in] != rootVal)
            return NULL;
        
        int leftlength = root_in - start_in;
        if(leftlength > 0)
            root->left = reConstructTree(pre, in, start_pre+1, start_pre+leftlength, start_in, root_in-1);
        if(leftlength < end_pre - start_pre)
            root->right = reConstructTree(pre, in, start_pre+leftlength+1, end_pre, root_in+1, end_in);
    	
        return root;
    }
    struct TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> in) {
        if(pre.empty() || in.empty() || pre.size() != in.size())
            return NULL;
        
        int len = pre.size();
		return reConstructTree(pre, in, 0, len -1, 0, len-1);
    }
    
   
};


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  
    struct TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> in) {
    	if(pre.size() != in.size() || pre.empty())
            return NULL;
        
        
        
        struct TreeNode* root = new TreeNode(pre[0]);
        
        vector<int>::iterator partition = find(in.begin(), in.end(), pre[0]);
       
        vector<int> left_in(in.begin(), partition);
        vector<int> left_pre(pre.begin()+1, pre.begin()+1+left_in.size());
        vector<int> right_in(++partition, in.end());
        vector<int> right_pre(pre.begin()+1+left_in.size(), pre.end());
        
        root->left = reConstructBinaryTree(left_pre,left_in);
        root->right = reConstructBinaryTree(right_pre,right_in);
        
        return root;
    }
    
   
};