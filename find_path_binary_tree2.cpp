/*二叉树中和为某一值的路径*/

void FindPath(
    BinaryTreeNode *Root,
    int                     Num, 
    vector<int>      &path, 
    vector<vector<int>> &res)
{
    if(Root == NULL)
        return;
    if(Root->val > Num)
        return;
    
    path.push_back(Root->val);
    if(Root->val == Num && Root->left == NULL 
       && Root->right == NULL) 
    {
       res.push_back(path);
       path.pop_back();
    }
    else
    {
        FindPath(Root->left, Num - Root->val, path, res);
        FindPath(Root->right, Num - Root->val, path, res);
        path.pop_back();
    }
}

vector<vector<int>> 
FindPath(BinaryTreeNode *root, int expectedSum)
{
    vector<vector<int>> res;
    vector<int> path;
    
    FindPath(root, expectedSum, path, res);
    
    return res;
}