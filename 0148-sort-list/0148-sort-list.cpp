/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* merge2Lists(ListNode* A, ListNode* B){
        if(!A) return B;
        if(!B) return A;
        ListNode* p ;
        if(A->val<=B->val){
            p = A;
            A->next = merge2Lists(A->next, B);
        }else {
            p = B;
            B->next = merge2Lists(A, B->next);
        }
        return p;
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *fast = head, *slow  = head; 
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* list2 = slow->next;
        slow->next = NULL;
        head = sortList(head);
        list2 = sortList(list2);
        head = merge2Lists(head, list2);
        
        return head;
        
    }
};