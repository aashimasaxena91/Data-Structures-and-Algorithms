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
    ListNode* reve(ListNode* head, ListNode* end, ListNode* prev){
        ListNode* cur = head;
        ListNode* d = prev;
        while(cur!=NULL && cur!=d){
            head = head->next;
            cur->next =prev;
            prev = cur;
            cur = head;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right || head->next == NULL ||!head) return head;
        int k=1;
        ListNode* cur=head, * l, *r;
        if(left == 1) l =head;
        while(cur->next!=NULL){
            if(k == left-1){
                l = cur;
            }
            if(k == right){
                r = cur;
                break;
            }
            k++;
            cur=cur->next;
        }
        if(left == 1)
            return reve(head, r, r->next);
        l->next = reve(l->next, r, r->next);
        return head;
    }
};