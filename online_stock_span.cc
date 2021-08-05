class StockSpanner {
  vector<int> p;
  stack<int> s;

 public:
  StockSpanner() {}

  int next(int price) {
    p.push_back(price);

    while (!s.empty() && p[s.top()] <= price) {
      s.pop();
    }

    int ret = s.empty() ? p.size() : p.size() - 1 - s.top();

    s.push(p.size() - 1);

    return ret;
  }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// Runtime: 212 ms, faster than 30.39%
// Memory Usage: 86.4 MB, less than 14.90%
// 2021.8.5 at 奥盛大厦

class StockSpanner {
  stack<pair<int, int>> stk;

 public:
  StockSpanner() {}

  int next(int price) {
    int cnt = 1;

    while (!stk.empty() && stk.top().first <= price) {
      cnt += stk.top().second;
      stk.pop();
    }

    stk.push({price, cnt});

    return cnt;
  }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// Runtime: 208 ms, faster than 36.11%
// Memory Usage: 84.2 MB, less than 62.89%