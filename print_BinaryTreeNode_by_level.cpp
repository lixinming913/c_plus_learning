/*
 * 二叉树打印按层依次打印
 */
 
 
#include<iostream>
#include<stdlib.h>
#include<queue>

using namespace std;


struct BinaryTreeNode {
    int             m_key;
    BinaryTreeNode *pLeft;
    BinaryTreeNode *pRight;
};


BinaryTreeNode *
create(int m)
{
    BinaryTreeNode *pnode = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    
    pnode->m_key = m;
    pnode->pLeft = NULL;
    pnode->pRight = NULL;
    
    return pnode;
}


void
connect(BinaryTreeNode *Parent, BinaryTreeNode*Left, BinaryTreeNode*Right)
{
    if(Parent == NULL)
        return;
    
    Parent->pLeft = Left;
    Parent->pRight = Right;
}


void
print(BinaryTreeNode *pHead)
{
    if(pHead == NULL)
        return ;
    
    queue<BinaryTreeNode *> Q;
    Q.push(pHead);
    int nextlevel = 0;        /*储存下一层的结点数*/
    int current_print = 1;  /*储存当前层还没有打印的结点数*/
    while(!Q.empty()) {
        BinaryTreeNode *pnode = Q.front();
        cout<<pnode->m_key<<" ";
        
        if(pnode->pLeft != NULL) {
            Q.push(pnode->pLeft);
            ++nextlevel;
        }
        
        if(pnode->pRight != NULL) {
            Q.push(pnode->pRight);
            ++nextlevel;
        }
        
        Q.pop();
        --current_print;
        if(current_print == 0) {
            cout<<endl;
            current_print = nextlevel;
            nextlevel = 0;
        }
    }
}


void 
test()
{
    BinaryTreeNode *pNode1 = create(1);
    BinaryTreeNode *pNode2 = create(2);
    BinaryTreeNode *pNode3 = create(3);
    BinaryTreeNode *pNode4 = create(4);
    BinaryTreeNode *pNode5 = create(5);
    BinaryTreeNode *pNode6 = create(6);
    BinaryTreeNode *pNode7 = create(7);
    
    connect(pNode1, pNode2, pNode3);
    connect(pNode2, pNode4, pNode5);
    connect(pNode3, pNode6, pNode7);
    
    print(pNode1);
}


void 
main()
{
    test();
}