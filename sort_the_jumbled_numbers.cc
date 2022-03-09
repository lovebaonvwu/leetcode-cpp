class Solution {
  int helper(vector<int>& mapping, int n) {
    vector<int> d;

    do {
      d.push_back(n % 10);
      n /= 10;
    } while (n > 0);

    int ret = 0;
    for (int i = d.size() - 1; i >= 0; --i) {
      ret = ret * 10 + mapping[d[i]];
    }

    return ret;
  }

 public:
  vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
    vector<pair<int, int>> v;

    for (int i = 0; i < nums.size(); ++i) {
      v.push_back({helper(mapping, nums[i]), i});
    }

    sort(v.begin(), v.end());

    vector<int> ans;

    for (int i = 0; i < v.size(); ++i) {
      ans.push_back(nums[v[i].second]);
    }

    return ans;
  }
};
// Runtime: 580 ms, faster than 60.10%
// Memory Usage: 199 MB, less than 10.35%
// 2022.3.9 at 奥盛大厦