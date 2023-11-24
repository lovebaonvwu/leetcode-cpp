class MedianFinder {
  priority_queue<int, vector<int>, less<int>> left;
  priority_queue<int, vector<int>, greater<int>> right;

 public:
  /** initialize your data structure here. */
  MedianFinder() {}

  void addNum(int num) {
    if (left.empty() || num <= left.top()) {
      left.push(num);
    } else {
      right.push(num);
    }

    if (left.size() < right.size()) {
      left.push(right.top());
      right.pop();
    } else if (left.size() - right.size() >= 2) {
      right.push(left.top());
      left.pop();
    }
  }

  double findMedian() {
    if (left.size() > right.size()) {
      return left.top();
    } else {
      return ((double)left.top() + right.top()) / 2;
    }
  }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// Runtime: 196 ms, faster than 13.95%
// Memory Usage: 46.8 MB, less than 54.96%
// 2021.7.11 at 茗筑美嘉

class MedianFinder {
  multiset<int> m;
  multiset<int>::const_iterator l;
  multiset<int>::const_iterator r;

 public:
  /** initialize your data structure here. */
  MedianFinder() : l(m.end()), r(m.end()) {}

  void addNum(int num) {
    if (m.empty()) {
      l = r = m.insert(num);
      return;
    }

    m.insert(num);

    if (m.size() & 1) {
      if (num >= *r) {
        l = r;
      } else {
        l = --r;
      }
    } else {
      if (num >= *r) {
        ++r;
      } else {
        --l;
      }
    }
  }

  double findMedian() { return ((double)*l + *r) / 2; }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// Runtime: 104 ms, faster than 62.38%
// Memory Usage: 49.3 MB, less than 8.33%
// 2021.7.11 at 茗筑美嘉