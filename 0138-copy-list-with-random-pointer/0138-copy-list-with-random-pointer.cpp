/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        Node* temp = head;
       
        
        while(temp!=NULL){
            Node* cur = new Node(temp->val);
            cur->next = temp->next;
            temp->next = cur;
            temp=temp->next->next;
        }
        temp = head;
        while(temp!=NULL){
            temp->next->random = temp->random!=NULL ? temp->random->next : NULL;
            temp=temp->next->next;
        }
         Node* newHead= head->next;
        Node* ntemp = newHead;
        temp = head;
        while(temp!=NULL){
            temp->next = temp->next->next;
            ntemp->next= ntemp->next ? ntemp->next->next : NULL;
            temp=temp->next;
            ntemp=ntemp->next;
                
        }
        return newHead;
    }
};