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
    ListNode* reve(ListNode* head)
    {
        
        ListNode* prev = NULL, * curr = head;
        while(curr!=NULL){
            head= head->next;
            curr->next = prev;
            prev=curr;
            curr = head;
        }
        return prev;
    } 
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL) return true;
        int siz = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            siz++;
            temp = temp->next;
                
        }
        temp = head;
       
        int t=0;
        while(t<siz/2){
            temp=temp->next;
            t++;
        }
         if(siz%2 ==1)temp=temp->next;
        temp = reve(temp);
        int i = 0;
        while(i<siz/2){
            i++;
            if(head->val !=temp->val)
                return false;
            temp=temp->next;
            head=head->next;
        }
        return true;
    }
};