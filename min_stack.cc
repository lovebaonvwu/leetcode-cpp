class MinStack {
 private:
  stack<int> reg_stack, min_stack;

 public:
  /** initialize your data structure here. */
  MinStack() {}

  void push(int x) {
    if (min_stack.empty() || x <= min_stack.top()) {
      min_stack.push(x);
    }

    reg_stack.push(x);
  }

  void pop() {
    if (reg_stack.top() == min_stack.top()) {
      min_stack.pop();
    }
    reg_stack.pop();
  }

  int top() { return reg_stack.top(); }

  int getMin() { return min_stack.top(); }
};  // 24ms

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

class MinStack {
 private:
  vector<int> stack;

 public:
  /** initialize your data structure here. */
  MinStack() {}

  void push(int x) {
    if (stack.size() == 0) {
      stack.push_back(x);
    } else {
      int min = x < stack[stack.size() - 2] ? x : stack[stack.size() - 2];
      stack.push_back(min);
    }

    stack.push_back(x);
  }

  void pop() {
    stack.pop_back();
    stack.pop_back();
  }

  int top() { return stack[stack.size() - 1]; }

  int getMin() { return stack[stack.size() - 2]; }
};  // 36ms

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */