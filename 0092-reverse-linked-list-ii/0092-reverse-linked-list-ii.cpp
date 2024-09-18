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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || !head->next || left == right) return head;
        
        ListNode* dum = new ListNode(-1);
        ListNode* cur = head, *prev = dum;
        
        dum->next = head;
        while(left>1){
            left--;
            prev = cur;
            cur=cur->next;
            right--;
        }
        ListNode* tail = cur, *j = cur, *t = NULL;
        while(right>0 && cur!=NULL){
            right--;
            tail = tail->next;
            cur->next = t;
            t= cur;
            cur=tail;
        }
        prev->next = t;
        j->next = cur;
        return dum->next;
        
    }
};