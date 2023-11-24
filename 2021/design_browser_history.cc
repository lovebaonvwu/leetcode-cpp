class BrowserHistory {
  int cur = 0;
  vector<string> his;

 public:
  BrowserHistory(string homepage) {
    his.clear();
    his.push_back(homepage);
  }

  void visit(string url) {
    his.resize(cur + 1);
    his.push_back(url);

    cur = his.size() - 1;
  }

  string back(int steps) {
    if (steps > cur) {
      steps = cur;
    }

    cur -= steps;
    return his[cur];
  }

  string forward(int steps) {
    if (steps + cur > his.size() - 1) {
      steps = his.size() - 1 - cur;
    }

    cur += steps;

    return his[cur];
  }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
// Runtime: 288 ms, faster than 76.49%
// Memory Usage: 54.8 MB, less than 100.00%

class BrowserHistory {
  stack<string> back_stack;
  stack<string> forward_stack;
  string cur;

 public:
  BrowserHistory(string homepage) { cur = homepage; }

  void visit(string url) {
    forward_stack = stack<string>();
    back_stack.push(cur);

    cur = url;
  }

  string back(int steps) {
    while (steps-- > 0 && !back_stack.empty()) {
      forward_stack.push(cur);

      cur = back_stack.top();
      back_stack.pop();
    }

    return cur;
  }

  string forward(int steps) {
    while (steps-- > 0 && !forward_stack.empty()) {
      back_stack.push(cur);

      cur = forward_stack.top();
      forward_stack.pop();
    }

    return cur;
  }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
// Runtime: 660 ms, faster than 8.71%
// Memory Usage: 119.8 MB, less than 100.00%