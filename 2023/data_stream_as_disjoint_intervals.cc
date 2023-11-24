class SummaryRanges {
  map<int, int> intervals;

 public:
  SummaryRanges() {}

  void addNum(int val) {
    int left = val, right = val;
    auto cur = intervals.upper_bound(val);

    if (cur != intervals.begin()) {
      auto prev = ::prev(cur);
      if (prev->second >= val) {
        return;
      }

      if (prev->second == val - 1) {
        left = prev->first;
      }
    }

    if (cur != intervals.end() && cur->first == val + 1) {
      right = cur->second;
      intervals.erase(cur);
    }

    intervals[left] = right;
  }

  vector<vector<int>> getIntervals() {
    vector<vector<int>> ans;
    for (auto& [left, right] : intervals) {
      ans.push_back({left, right});
    }

    return ans;
  }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
// Runtime 72 ms
// Memory 33.3 MB
// 2023.1.28 at 奥盛大厦