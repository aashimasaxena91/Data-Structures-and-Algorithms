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
    
    ListNode* merge2Lists(ListNode* list1, ListNode* list2){
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
        ListNode* newHead = list1;
        if(list2->val < list1->val){
            newHead = list2;
            list2 = list2->next;
        }else{
            list1=list1->next;
        }
        ListNode* temp = newHead;
        while(list1!=NULL && list2!=NULL){
            if(list1->val<=list2->val){
                temp->next = list1;
                list1=list1->next;
            }else{
                temp->next = list2;
                list2=list2->next;
            }
            temp = temp->next;
        }
        if(list1!=NULL){
            temp->next = list1;
        }
        else if(list2!=NULL){
            temp->next = list2;
        }
        return newHead;
        
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int siz = lists.size();
        if(siz == 0 ) return NULL;
        if(siz == 1) return lists[0];
        
        ListNode* mergedList = merge2Lists(lists[0], lists[1]);
        for(int i = 2;i<siz;i++){
            mergedList =  merge2Lists(lists[i], mergedList);
        }
        
        return mergedList;
        
    }
};