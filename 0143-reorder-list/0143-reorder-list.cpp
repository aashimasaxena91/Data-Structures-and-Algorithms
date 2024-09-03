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
    void reorderList(ListNode* head) {
        if(head==NULL || head->next ==NULL) return ;
        ListNode* slow = head, * fast = head;
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow=slow->next;
        }
        ListNode* k = slow->next;
        slow->next = NULL;
        ListNode* cur = k, *prev = NULL;
        while(k){
            k=k->next;
            cur->next = prev;
            prev = cur;
            cur=k;
        }
        k = prev;
        fast = head;
        ListNode* r = new ListNode();

        while(fast && k){
            r->next = fast;
            fast =fast->next;
            r=r->next;
            r->next = k;
            k=k->next;
            r= r->next;
        }
        if(fast) r->next = fast;
        if(k) r->next = k;
    }
};