class CustomStack {
  int max_size;
  int top;
  vector<int> stk;

 public:
  CustomStack(int maxSize) : max_size(maxSize), top(-1), stk(max_size) {}

  void push(int x) {
    if (top < max_size - 1) {
      stk[++top] = x;
    }
  }

  int pop() { return top < 0 ? -1 : stk[top--]; }

  void increment(int k, int val) {
    for (int i = 0; i < k && i <= top; ++i) {
      stk[i] += val;
    }
  }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
// Runtime: 36 ms, faster than 96.42%
// Memory Usage: 19.7 MB, less than 100.00%

class CustomStack {
  int max_size;
  vector<int> stk;
  vector<int> record;

 public:
  CustomStack(int maxSize) : max_size(maxSize) {}

  void push(int x) {
    if (stk.size() < max_size) {
      stk.push_back(x);
      record.push_back(0);
    }
  }

  int pop() {
    if (stk.empty()) {
      return -1;
    }

    if (record.size() > 1) {
      record[record.size() - 2] += record[record.size() - 1];
    }

    int res = stk.back() + record[stk.size() - 1];

    record.pop_back();
    stk.pop_back();

    return res;
  }

  void increment(int k, int val) {
    int i = min(k, static_cast<int>(stk.size())) - 1;

    if (i >= 0) {
      record[i] += val;
    }
  }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
// Runtime: 40 ms, faster than 85.59%
// Memory Usage: 19.7 MB, less than 100.00%