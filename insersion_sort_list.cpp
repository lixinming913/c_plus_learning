/*
 *  Insertion Sort List
 *  Sort a linked list using insertion sort.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void swap(ListNode *p1, ListNode *p2) {
        int temp = p1->val;
        p1->val = p2->val;
        p2->val = temp;
    }


    ListNode* insertionSortList(ListNode* head) {
        if(!head || head->next == NULL)
            return head;
            
        ListNode* current = head;
        ListNode* temp = head;
        
        while(current != NULL) {
            temp = head;
            while(temp != current) {
                if(current->val < temp->val)
                    swap(temp, current);
                    
                temp = temp->next;
            }
            
            current = current->next;
        }
        
        return head;
    }
};