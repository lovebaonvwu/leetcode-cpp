class RecentCounter {
  queue<int> q;

 public:
  RecentCounter() {}

  int ping(int t) {
    q.push(t);

    while (q.front() < t - 3000) {
      q.pop();
    }

    return q.size();
  }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
// Runtime: 264 ms, faster than 25.73%
// Memory Usage: 47.7 MB, less than 100.00%

class RecentCounter {
  vector<int> v;
  int lo = 0;
  int hi = 0;

 public:
  RecentCounter() { v.resize(10000); }

  int ping(int t) {
    v[hi++] = t;

    while (v[lo] < t - 3000) {
      ++lo;
    }

    return hi - lo;
  }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
// Runtime: 284 ms, faster than 18.16%
// Memory Usage: 50.3 MB, less than 9.09%

class RecentCounter {
  vector<int> v;

 public:
  RecentCounter() {}

  int ping(int t) {
    v.push_back(t);

    auto it = lower_bound(v.begin(), v.end(), t - 3000);

    return v.end() - it;
  }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
// Runtime: 312 ms, faster than 12.36%
// Memory Usage: 48.2 MB, less than 100.00%