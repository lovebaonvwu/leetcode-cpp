class Solution {
 public:
  vector<string> findRelativeRanks(vector<int>& score) {
    priority_queue<pair<int, int>> pq;

    for (int i = 0; i < score.size(); ++i) {
      pq.push({score[i], i});
    }

    vector<string> ans(score.size());

    int cnt = 1;
    while (!pq.empty()) {
      auto [_, idx] = pq.top();
      pq.pop();

      if (cnt == 1) {
        ans[idx] = "Gold Medal";
      } else if (cnt == 2) {
        ans[idx] = "Silver Medal";
      } else if (cnt == 3) {
        ans[idx] = "Bronze Medal";
      } else {
        ans[idx] = std::to_string(cnt);
      }

      ++cnt;
    }

    return ans;
  }
};
// Runtime: 8 ms, faster than 97.47%
// Memory Usage: 10.3 MB, less than 49.07%
// 2021.12.26 at 奥盛大厦