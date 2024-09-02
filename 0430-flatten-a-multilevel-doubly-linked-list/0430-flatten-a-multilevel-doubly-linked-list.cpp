/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* k = head;
        
        while(k!=NULL){
            if(k->child){
                Node* temp = k->next;
                k->next = k->child;
                k->child->prev = k;
                Node* r = k->child;
                k->child = NULL;
                if(temp!=NULL){
                while(r->next!=NULL) r=r->next;
                r->next = temp;
                temp->prev = r;
                }
            }
            k=k->next;
        }
        return head;
    }
};