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
        unordered_map<Node* , Node*> mp;
        Node* ptr = head;
        while(ptr!=NULL){
            mp[ptr] = new Node(ptr->val);
            ptr = ptr->next;
        }
        Node* nHead = mp[head];
        ptr=head;
        while(ptr!=NULL){
            mp[ptr]->next = mp[ptr->next];
            mp[ptr]->random = mp[ptr->random];
            ptr=ptr->next;
        }
        return nHead;
    }
};