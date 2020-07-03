class Solution {
 public:
  int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
    unordered_map<int, int> mp;

    for (auto n : arr) {
      ++mp[n];
    }

    vector<int> cnt;
    int ans = 0;

    for (auto& m : mp) {
      ++ans;
      cnt.push_back(m.second);
    }

    sort(cnt.begin(), cnt.end());

    for (int i = 0; i < cnt.size() && k > 0; ++i) {
      if (k >= cnt[i]) {
        --ans;
      }
      k -= cnt[i];
    }

    return ans;
  }
};
// Runtime: 352 ms, faster than 94.68%
// Memory Usage: 62.5 MB, less than 40.00%