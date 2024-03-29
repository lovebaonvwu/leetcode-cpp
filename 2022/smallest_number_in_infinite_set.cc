class SmallestInfiniteSet {
  set<int> st;

 public:
  SmallestInfiniteSet() {
    for (int i = 1; i <= 1000; ++i) {
      st.insert(i);
    }
  }

  int popSmallest() {
    auto it = st.begin();
    int res = *it;

    st.erase(*it);

    return res;
  }

  void addBack(int num) {
    if (st.find(num) != st.end()) {
      return;
    }

    st.insert(num);
  }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
// Runtime: 141 ms, faster than 100.00%
// Memory Usage: 46.4 MB, less than 100.00%
// 2022.7.11 at 奥盛大厦

class SmallestInfiniteSet {
  int smallest;
  set<int> smaller;

 public:
  SmallestInfiniteSet() { smallest = 1; }

  int popSmallest() {
    if (smaller.empty()) {
      return smallest++;
    }

    int res = *smaller.begin();
    smaller.erase(res);

    return res;
  }

  void addBack(int num) {
    if (num < smallest) {
      smaller.insert(num);
    }
  }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
// Runtime: 83 ms, faster than 100.00%
// Memory Usage: 35.5 MB, less than 100.00%
// 2022.7.11 at 奥盛大厦