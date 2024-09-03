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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next == NULL && n==1) return NULL;
        ListNode* fast = head;
        int k =0;
        while(k<n   && fast){
            fast=fast->next;
            k++;
        }
        if(fast==NULL) return head->next;
        ListNode* slow = head;
        while(fast->next){
            slow=slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};