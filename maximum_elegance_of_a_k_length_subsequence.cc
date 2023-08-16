class Solution {
 public:
  long long findMaximumElegance(vector<vector<int>>& items, int k) {
    sort(items.begin(), items.end(),
         [](auto& a, auto& b) { return a[0] > b[0]; });

    long long ans = 0;
    vector<int> dup;
    unordered_set<int> seen;
    long long profit = 0;
    for (int i = 0; i < items.size(); ++i) {
      if (i < k) {
        if (seen.find(items[i][1]) != seen.end()) {
          dup.push_back(items[i][0]);
        }
        profit += items[i][0];
      } else if (seen.find(items[i][1]) == seen.end()) {
        if (dup.empty()) {
          break;
        }

        profit += items[i][0] - dup.back();
        dup.pop_back();
      }

      seen.insert(items[i][1]);
      ans = fmax(ans, profit + 1LL * seen.size() * seen.size());
    }

    return ans;
  }
};
// 464ms
// 179.79mb