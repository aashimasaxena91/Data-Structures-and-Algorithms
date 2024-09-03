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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* left = new ListNode();
        ListNode* right  = new ListNode();
        ListNode* l = left, *r = right;
        ListNode* temp = head;
        while(temp!=NULL){
            if(temp->val<x){
                l->next = temp;
                l=l->next;
            }else{
                r->next=temp;
                r=r->next;
            }
              temp=temp->next;  
        }
        r->next = NULL;
        if(left->next){
        l->next = right->next;
        return left->next;
        }
        return right->next;
    }
};