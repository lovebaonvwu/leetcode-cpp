class Solution {
 public:
  int largestValsFromLabels(vector<int>& values,
                            vector<int>& labels,
                            int num_wanted,
                            int use_limit) {
    vector<pair<int, int>> vl;

    for (int i = 0; i < values.size(); ++i) {
      vl.push_back({values[i], labels[i]});
    }

    sort(vl.begin(), vl.end(),
         [](auto& a, auto& b) { return a.first > b.first; });

    unordered_map<int, int> label_cnt;

    int ans = 0;

    for (int i = 0, cnt = 0; i < vl.size() && cnt < num_wanted; ++i) {
      auto [v, l] = vl[i];

      if (label_cnt[l] < use_limit) {
        ans += v;
        ++label_cnt[l];
        ++cnt;
      }
    }

    return ans;
  }
};
// Runtime: 56 ms, faster than 94.78%
// Memory Usage: 20.5 MB, less than 8.09%