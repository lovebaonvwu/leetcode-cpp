class Solution {
 public:
  vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
    vector<array<double, 3>> cnt;
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        cnt.push_back({arr[i] * 1.0 / arr[j], 1.0 * i, 1.0 * j});
      }
    }

    sort(begin(cnt), end(cnt));
    return {arr[cnt[k - 1][1]], arr[cnt[k - 1][2]]};
  }
};
// 480 ms
// 174.32 MB