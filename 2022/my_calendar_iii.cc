class MyCalendarThree {
  map<int, int> mp;

 public:
  MyCalendarThree() {}

  int book(int start, int end) {
    mp[start] += 1;
    mp[end] -= 1;

    int res = 0;
    int cur = 0;
    for (auto& [t, e] : mp) {
      cur += e;
      res = max(res, cur);
    }

    return res;
  }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
// Runtime: 241 ms, faster than 40.60%
// Memory Usage: 26.4 MB, less than 75.61%
// 2022.10.7 at 茗筑美嘉