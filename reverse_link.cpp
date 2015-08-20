/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
		if(!pHead)
            return NULL;
        
        ListNode *pre = NULL;
        ListNode *cur = pHead;
        ListNode *FIR = NULL;
        while(cur) {
            ListNode *nex = cur->next;
            if(nex == NULL) 
               	FIR = cur;
                
            cur->next = pre;
            pre = cur;
            cur = nex;           
        }
        
        return FIR;
    }
};