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
    int gcd(int a, int b){
        if(b==0) return a;
        return gcd(b, a%b);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* cur = head;
        while(cur->next!=NULL){
            int g = gcd(cur->val, cur->next->val);
            ListNode* temp = new ListNode(g);
            temp->next = cur->next;
            cur->next = temp;
            cur = cur->next->next;
        }
        return head;
    }
};