/*
 *  Sort List
 *  Sort a linked list in O(n log n) time using constant space complexity.
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
    ListNode* merge(ListNode* left, ListNode* right) {
        if(left == NULL)
            return right;
        if(right == NULL)
            return left;
            
        ListNode* merge_head = NULL;
        if(left->val < right->val) {
            merge_head = left;
            merge_head->next = merge(left->next, right);
        } else {
            merge_head = right;
            merge_head->next = merge(left, right->next);
        }
        
        return merge_head;
    }
    
    
    ListNode* mergesort(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next;
            fast = fast->next;
        }
        
        ListNode* mid = slow;
        
        ListNode* rhead = mid->next;
        mid->next = NULL;
        
        ListNode* left = mergesort(head);
        ListNode* right = mergesort(rhead);
        return merge(left, right);
    }
    
    
    ListNode* sortList(ListNode* head) {
        return mergesort(head);
    }
};