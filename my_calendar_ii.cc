class MyCalendarTwo {
  map<int, int> mp;

 public:
  MyCalendarTwo() {}

  bool book(int start, int end) {
    ++mp[start];
    --mp[end];

    int event = 0;
    for (auto& [k, v] : mp) {
      event += v;

      if (event == 3) {
        --mp[start];
        ++mp[end];

        return false;
      }

      if (k > end) {
        break;
      }
    }

    return true;
  }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
// Runtime: 344 ms, faster than 7.88%
// Memory Usage: 39.1 MB, less than 23.10%

class MyCalendarTwo {
  vector<pair<int, int>> booked;
  vector<pair<int, int>> overlap;

 public:
  MyCalendarTwo() {}

  bool book(int start, int end) {
    for (auto& [s, e] : overlap) {
      if (max(start, s) < min(end, e)) {
        return false;
      }
    }

    for (auto& [s, e] : booked) {
      int ss = max(start, s);
      int ee = min(end, e);

      if (ss < ee) {
        overlap.push_back({ss, ee});
      }
    }

    booked.push_back({start, end});

    return true;
  }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
// Runtime: 120 ms, faster than 66.39%
// Memory Usage: 33.9 MB, less than 83.82%