/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    
    Node* inorderSuccessor(Node* node) {
        Node* k = node;
        if(node->right){
            k=node->right;
            while(k->left)
                k=k->left;
            return k;
        }else{
            k = node->parent;
            while(k){
                if(k->val>node->val)
                    return k;
                k=k->parent;
            }
        }
         return NULL;  
    }
};