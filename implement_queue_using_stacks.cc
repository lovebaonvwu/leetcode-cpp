class MyQueue {
  stack<int> s_in, s_out;

 public:
  /** Initialize your data structure here. */
  MyQueue() {}

  /** Push element x to the back of queue. */
  void push(int x) { s_in.push(x); }

  /** Removes the element from in front of queue and returns that element. */
  int pop() {
    while (!s_in.empty()) {
      s_out.push(s_in.top());
      s_in.pop();
    }

    int temp = s_out.top();
    s_out.pop();

    while (!s_out.empty()) {
      s_in.push(s_out.top());
      s_out.pop();
    }

    return temp;
  }

  /** Get the front element. */
  int peek() {
    while (!s_in.empty()) {
      s_out.push(s_in.top());
      s_in.pop();
    }

    int temp = s_out.top();

    while (!s_out.empty()) {
      s_in.push(s_out.top());
      s_out.pop();
    }

    return temp;
  }

  /** Returns whether the queue is empty. */
  bool empty() { return s_in.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */