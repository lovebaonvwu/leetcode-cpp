/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than
 * a nested list. bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a
 * single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a
 * nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
  vector<int> container;
  int cur = 0;

 public:
  NestedIterator(vector<NestedInteger>& nestedList) {
    for (auto& item : nestedList) {
      if (item.isInteger()) {
        container.push_back(item.getInteger());
      } else {
        NestedIterator nestIterator(item.getList());

        while (nestIterator.hasNext()) {
          container.push_back(nestIterator.next());
        }
      }
    }
  }

  int next() { return container[cur++]; }

  bool hasNext() { return cur < container.size(); }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
// Runtime: 16 ms, faster than 55.16%
// Memory Usage: 13.5 MB, less than 54.72%

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than
 * a nested list. bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a
 * single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a
 * nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
  stack<NestedInteger*> stk;

 public:
  NestedIterator(vector<NestedInteger>& nestedList) {
    for (int i = nestedList.size() - 1; i >= 0; --i) {
      stk.push(&nestedList[i]);
    }
  }

  int next() {
    auto item = stk.top();

    stk.pop();

    return item->getInteger();
  }

  bool hasNext() {
    while (!stk.empty()) {
      auto item = stk.top();

      if (item->isInteger()) {
        return true;
      } else {
        stk.pop();

        auto& nestedList = item->getList();
        for (int i = nestedList.size() - 1; i >= 0; --i) {
          stk.push(&nestedList[i]);
        }
      }
    }

    return false;
  }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
// Runtime: 16 ms, faster than 55.16%
// Memory Usage: 12.9 MB, less than 77.90%