struct Node {
    string page;
    Node* next;
    Node* prev;
    Node(){
        next = NULL;
        prev=NULL;
    }
    Node(string url){
        page = url;
        next = NULL;
        prev=NULL;
    }
};

class BrowserHistory {
public:
    Node* head;
    Node* current;
    BrowserHistory(string homepage) {
        head= new Node(homepage);
        current = head;
    }
    
    void visit(string url) {
        Node* temp= new Node(url);
        Node* q = current->next;
        while(q!=NULL){
            Node* w = q;
            q=q->next;
            delete w;
        }
        current->next = temp;
        temp->prev = current;
        current = current->next;
    }
    
    string back(int steps) {
        while(steps>0 && current->prev!=NULL){
            steps--;
            current = current->prev;
        }
        return current->page;
    }
    
    string forward(int steps) {
        while(steps>0 && current->next!=NULL){
            steps--;
            current = current->next;
        }
        return current->page;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */