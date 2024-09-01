class BrowserHistory {
public:
    list<string> browser;
    list<string> :: iterator it;
    BrowserHistory(string homepage) {
        browser.push_back(homepage);
        it = browser.begin();
    }
    
    void visit(string url) {
        auto delPtr = it;
        delPtr++;
        browser.erase(delPtr, browser.end());
        browser.push_back(url);
        it++;
    }
    
    string back(int steps) {
        while(steps-- && it!=browser.begin()){
            it--;
        }
        
     
        return *it;
    }
    
    string forward(int steps) {
        while(steps-- && it!=--browser.end()) it++;
        return *it;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */