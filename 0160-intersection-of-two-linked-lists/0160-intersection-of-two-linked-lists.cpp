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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int s1 =0, s2=0;
        ListNode* temp1 = headA, * temp2 = headB;
        while(temp1!=NULL){
            temp1 = temp1->next;
            s1++;
        }
        while(temp2!=NULL){
            temp2 = temp2->next;
            s2++;
        }
        if(s1>s2){
            while(s1!=s2){
                s1--;
                headA = headA->next;
            }
        }else  if(s1<s2){
            while(s1!=s2){
                s2--;
                headB = headB->next;
            }
        }
        
        while(headA!=NULL){
            if(headA == headB) return headA;
            headA=headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};