class Solution {
 public:
  vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
    vector<pair<int, int>> tmp;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      tmp.push_back({nums[i], i});
    }

    sort(begin(tmp), end(tmp));

    vector<int> ans(n);
    for (int i = 0; i < n;) {
      vector<int> val;
      vector<int> idx;
      val.push_back(tmp[i].first);
      idx.push_back(tmp[i].second);

      int j = i + 1;
      for (; j < n; ++j) {
        if (abs(tmp[j].first - tmp[j - 1].first) > limit)
          break;

        val.push_back(tmp[j].first);
        idx.push_back(tmp[j].second);
      }

      i = j;

      sort(begin(idx), end(idx));
      for (int k = 0; k < idx.size(); ++k) {
        ans[idx[k]] = val[k];
      }
    }

    return ans;
  }
};
// 297 ms
// 165.56 MB