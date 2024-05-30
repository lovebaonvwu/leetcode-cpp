class Solution {
 public:
  long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    unordered_map<int, int> cnt;
    for (auto n : nums1) {
      for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
          ++cnt[i];
          ++cnt[n / i];
        }

        if (i * i == n) {
          --cnt[i];
        }
      }
    }

    long long ans = 0;
    for (auto n : nums2) {
      ans += cnt[n * k];
    }

    return ans;
  }
};
// 1502 ms
// 194.45 MB