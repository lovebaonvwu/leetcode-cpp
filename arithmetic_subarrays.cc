class Solution {
 public:
  vector<bool> checkArithmeticSubarrays(vector<int>& nums,
                                        vector<int>& l,
                                        vector<int>& r) {
    vector<bool> ans;

    for (int i = 0; i < l.size(); ++i) {
      if (r[i] - l[i] < 2) {
        ans.push_back(true);
        continue;
      }

      vector<int> tmp(nums.begin() + l[i], nums.begin() + r[i] + 1);

      sort(tmp.begin(), tmp.end());

      int j = 1;
      for (; j < tmp.size(); ++j) {
        if (tmp[j] - tmp[j - 1] != tmp[1] - tmp[0]) {
          break;
        }
      }

      ans.push_back(j == tmp.size());
    }

    return ans;
  }
};
// Runtime: 60 ms, faster than 80.71%
// Memory Usage: 25.7 MB, less than 70.56%