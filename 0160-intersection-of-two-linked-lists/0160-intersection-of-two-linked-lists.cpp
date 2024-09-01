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
    ListNode *getIntersectionNode(ListNode *A, ListNode *B) {
        ListNode* headA = A, *headB = B;
        while(headA!=NULL && headB!=NULL && headA!=headB){
            headA= headA->next;
            headB = headB->next;
            if(headA == headB) return headA;
            if(headA == NULL ){
                headA = B;
            }
            if(headB == NULL){
                headB = A;
            }
        }
        return headA;
    }
};