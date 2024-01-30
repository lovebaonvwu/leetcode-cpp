class Solution {
 public:
  int maximumLength(vector<int>& nums) {
    unordered_map<long long, int> cnt;
    for (auto n : nums)
      ++cnt[n];

    int ans = 1;
    for (auto& [n, c] : cnt) {
      if (n == 1) {
        ans = max(ans, c % 2 == 0 ? c - 1 : c);
      } else if (c > 1) {
        int cur = 0;
        for (auto it = cnt.find(n * n); it != cnt.end();
             it = cnt.find(it->first * it->first)) {
          cur += 2;
          if (it->second == 1)
            break;
        }

        ans = max(ans, cur + 1);
      }
    }

    return ans;
  }
};
// 203 ms
// 122.18 MB