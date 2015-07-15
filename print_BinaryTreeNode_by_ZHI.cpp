/*
 *  二叉树之字形打印
 *  用两个辅助栈，一个栈存储奇数层，一个栈存储偶数层
 *  奇数层存储顺序从左节点到右结点，偶数层从右结点到左节点
 *  先打印奇数层在打印偶数层
 */
 
 
#include<iostream>
#include<stack>
#include<stdlib.h>

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
Print(BinaryTreeNode *pHead)
{
    if(pHead == NULL)
        return;
    
    stack<BinaryTreeNode *> s[2];
    int current = 0;
    int next = 1;
    
	s[current].push(pHead);
    while(!s[0].empty() || !s[1].empty()) {
        BinaryTreeNode *pnode = s[current].top();
        cout<<pnode->m_key<<" ";
        s[current].pop();
        
        if(current == 0) {
            if(pnode->pLeft != NULL)
                s[next].push(pnode->pLeft);
            if(pnode->pRight != NULL)
                s[next].push(pnode->pRight);
        } else {
            if(pnode->pRight != NULL)
                s[next].push(pnode->pRight);
            if(pnode->pLeft != NULL)
                s[next].push(pnode->pLeft);
        }
        
        if(s[current].empty()) {
            cout<<endl;
            current = 1 - current;
            next = 1 - next;
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
    
    Print(pNode1);
}


void 
main()
{
    test();
}