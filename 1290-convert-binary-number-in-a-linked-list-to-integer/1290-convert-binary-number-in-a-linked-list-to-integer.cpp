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
    ListNode* rev(ListNode* head){
        ListNode* prev = NULL, *cur = head;
        while(head!=NULL){
            head= head->next;
            cur->next = prev;
            prev = cur;
            cur = head;
        }
        return prev;
    }
    int getDecimalValue(ListNode* head) {
        if(head->next == NULL) return head->val;
        head = rev(head);
        int x=0, i=0;
        while(head!=NULL){
            if(head->val == 1)
                x+= pow(2,i);
            i++;
            head= head->next;
        }
        return x;
    }
};