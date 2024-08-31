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

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;
        int n = 0;
        ListNode* temp = head;
        while(temp!=NULL && n<k){
            temp=temp->next;
            n++;
        }
        if(n<k) return head;
        
         ListNode* cur = head, *prev = NULL, * h = head;
        int t = 0;
        while(t<k){
            t++;
            h= h->next;
            cur -> next = prev;
            prev  = cur;
            cur = h;
        }
        
        if(h!=NULL){
            ListNode* newHead = reverseKGroup(h, k);
            head->next = newHead;
        }
        return prev;
        
    }
};