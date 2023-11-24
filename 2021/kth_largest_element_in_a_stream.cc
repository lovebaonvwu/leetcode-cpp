class KthLargest {
  priority_queue<int, vector<int>, greater<>> pq;
  int size;

 public:
  KthLargest(int k, vector<int>& nums) {
    pq;
    size = k;

    for (auto& n : nums) {
      if (pq.size() < size) {
        pq.push(n);
      } else {
        if (n > pq.top()) {
          pq.pop();
          pq.push(n);
        }
      }
    }
  }

  int add(int val) {
    if (pq.size() < size) {
      pq.push(val);
    } else if (val > pq.top()) {
      pq.pop();
      pq.push(val);
    }

    return pq.top();
  }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// 48ms

class KthLargest {
  priority_queue<int, vector<int>, greater<>> pq;
  int size;

 public:
  KthLargest(int k, vector<int>& nums) {
    pq;
    size = k;

    for (auto& n : nums) {
      if (pq.size() < size) {
        pq.push(n);
      } else {
        if (n > pq.top()) {
          pq.pop();
          pq.push(n);
        }
      }
    }
  }

  int add(int val) {
    if (pq.size() < size) {
      pq.push(val);

      return pq.top();
    } else {
      if (val <= pq.top()) {
        return pq.top();
      } else {
        pq.pop();
        pq.push(val);
        return pq.top();
      }
    }
  }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// 56ms

class KthLargest {
  priority_queue<int> pq;
  int p;

 public:
  KthLargest(int k, vector<int>& nums) {
    pq = priority_queue<int>(nums.begin(), nums.end());
    p = k;
  }

  int add(int val) {
    stack<int> stk;

    pq.push(val);

    for (int i = 1; i < p; ++i) {
      stk.push(pq.top());
      pq.pop();
    }

    int res = pq.top();

    while (!stk.empty()) {
      pq.push(stk.top());
      stk.pop();
    }

    return res;
  }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// TLE