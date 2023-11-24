class FrontMiddleBackQueue {
  deque<int> left;
  deque<int> right;

 public:
  FrontMiddleBackQueue() {}

  void pushFront(int val) {
    left.push_front(val);
    if (left.size() > right.size()) {
      right.push_front(left.back());
      left.pop_back();
    }
  }

  void pushMiddle(int val) {
    left.push_back(val);
    if (left.size() > right.size()) {
      right.push_front(left.back());
      left.pop_back();
    }
  }

  void pushBack(int val) {
    right.push_back(val);
    if (right.size() - left.size() > 1) {
      left.push_back(right.front());
      right.pop_front();
    }
  }

  int popFront() {
    int val = -1;
    if (!left.empty()) {
      val = left.front();
      left.pop_front();
    } else if (!right.empty()) {
      val = right.front();
      right.pop_front();
    }

    if (right.size() - left.size() > 1) {
      left.push_back(right.front());
      right.pop_front();
    }

    return val;
  }

  int popMiddle() {
    int val = -1;

    if (right.size() > left.size()) {
      val = right.front();
      right.pop_front();
    } else if (!left.empty()) {
      val = left.back();
      left.pop_back();
    } else {
      val = -1;
    }

    return val;
  }

  int popBack() {
    int val = -1;
    if (!right.empty()) {
      val = right.back();
      right.pop_back();
    } else if (!left.empty()) {
      val = left.back();
      left.pop_back();
    }

    if (left.size() > right.size()) {
      right.push_front(left.back());
      left.pop_back();
    }

    return val;
  }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */
// Runtime: 75 ms, faster than 41.40%
// Memory Usage: 20.4 MB, less than 42.20%
// 2022.9.27 at 奥盛大厦