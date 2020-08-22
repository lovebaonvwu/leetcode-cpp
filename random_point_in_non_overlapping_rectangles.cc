class Solution {
  vector<int> areas;
  vector<vector<int>> rects_;

  int area(vector<int>& rect) {
    return (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1);
  }

 public:
  Solution(vector<vector<int>>& rects) {
    rects_ = rects;
    for (auto& r : rects) {
      areas.push_back(area(r) + (areas.empty() ? 0 : areas.back()));
    }
  }

  vector<int> pick() {
    int rnd = rand() % areas.back();
    auto it = upper_bound(areas.begin(), areas.end(), rnd);

    int pos = it - areas.begin();

    auto rect = rects_[pos];

    return {rand() % (rect[2] - rect[0] + 1) + rect[0],
            rand() % (rect[3] - rect[1] + 1) + rect[1]};
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
// Runtime: 224 ms, faster than 16.43%
// Memory Usage: 68.8 MB, less than 22.53%