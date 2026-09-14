class BrowserHistory {
private:
    std::list<string> browser;
    std::list<string>::iterator cur;
public:
    BrowserHistory(string homepage) {
        browser.assign(1, homepage);
        cur = browser.begin();
    }
    
    void visit(string url) {
        browser.erase(next(cur), browser.end());
        browser.push_back(url);
        cur = prev(browser.end());
    }
    
    string back(int steps) {
        while (steps-- > 0 && cur != browser.begin()) {
            cur--;
        }

        return *cur;
    }
    
    string forward(int steps) {
        while (steps-- > 0 && cur != prev(browser.end())) {
            cur++;
        }

        return *cur;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */