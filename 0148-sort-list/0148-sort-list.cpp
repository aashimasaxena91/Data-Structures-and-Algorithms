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
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* k = head;
        vector<int> v;
        while(k!=NULL){
            int q = k->val;
            v.push_back(q);
            k= k->next;
        }
        sort(v.begin(), v.end());
        ListNode* temphead = new ListNode();
        ListNode* temp = temphead;
        for(int i =0;i<v.size();i++){
            auto s = v[i];
            ListNode* e = new ListNode(s);
            temp->next = e;
            temp = temp->next;
        }
        return temphead->next;
    }
};