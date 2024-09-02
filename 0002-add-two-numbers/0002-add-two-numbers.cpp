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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* k = new ListNode (-1);
        ListNode* temp = k;
        int carry = 0;
        while(l1!=NULL || l2!=NULL || carry!=0){
            
            int a = 0, b=0;
            if(l1!=NULL){
                a = l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                b = l2->val;
                l2=l2->next;
            }
            int ans = a+b+carry;
            if(ans>=10)
                carry=1;
            else carry = 0;
            ListNode* q = new ListNode(ans%10);
            temp->next = q;
                temp=temp->next;
        }
        return k->next;
    }
};