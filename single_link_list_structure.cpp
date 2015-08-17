/*
 *  单链表添加，删除
 */
 
 struct ListNode {
    int     m_nValue;
    struct ListNode *m_pnext;
 };
 
 void AddtoTail(ListNode **pHead, int value)
 {
        ListNode *pnew = new ListNode();
        pnew->m_nValue = value;
        pnew->m_pnext   = NULL;
        
        if(*pHead == NULL) {
            *pHead = pnew;
        } else {
            ListNode *pnode = *pHead;
            while(pnode->m_pnext != NULL) {
                pnode = pnode->m_pnext;
            }
            
            pnode->m_pnext = pnew;
        }
 }
 
 void delNode(ListNode **pHead, int value) 
 {
        if(pHead == NULL || *pHead == NULL)
            return;
        
        ListNode *ptodel = NULL;
        if(*pHead->m_nValue == value) {
            ptodel = *pHead;
            *pHead = (*pHead)->m_pnext;
        } else {
            ListNode *pnode = *pHead;
            while(pnode->m_pnext != NULL && pnode->m_pnext->m_nValue != value) {
                pnode = pnode->m_pnext;
            }
            
            if(pnode->m_pnext != NULL && pnode->m_pnext->m_nValue == value) {
                ptodel = pnode->m_pnext;
                pnode = pnode->m_pnext;
            }
            
            if(ptodel != NULL) {
                delete ptodel;
                ptodel = NULL;
            }
        }
        
 }
 