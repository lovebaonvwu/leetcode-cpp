class Solution {
 public:
  long long minimumRemoval(vector<int>& beans) {
    sort(beans.begin(), beans.end());

    long long ans = LONG_MAX;
    long long total = accumulate(beans.begin(), beans.end(), 0LL);

    int n = beans.size();

    for (int i = 0; i < n; ++i) {
      long long sum = total - (n - i) * static_cast<long long>(beans[i]);

      ans = min(ans, sum);
    }

    return ans;
  }
};
// Runtime: 266 ms, faster than 70.59%
// Memory Usage: 100.7 MB, less than 70.59%
// 2022.2.14 at 奥盛大厦