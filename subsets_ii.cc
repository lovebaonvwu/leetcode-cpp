class Solution {
 public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> ans{{}};

    sort(nums.begin(), nums.end());

    int idx = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (i == 0 || nums[i - 1] != nums[i]) {
        idx = 0;
      }

      for (int sz = ans.size(); idx < sz; ++idx) {
        ans.push_back(ans[idx]);
        ans.back().push_back(nums[i]);
      }
    }

    return ans;
  }
};
// Runtime: 8 ms, faster than 83.88%
// Memory Usage: 9.1 MB, less than 100.00%

class Solution {
 public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> ans{{}};
    vector<vector<int>> tmp;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); ++i) {
      if (i == 0 || nums[i - 1] != nums[i]) {
        tmp = ans;
      }

      for (auto& t : tmp) {
        t.push_back(nums[i]);
      }

      ans.insert(ans.end(), tmp.begin(), tmp.end());
    }

    return ans;
  }
};
// Runtime: 8 ms, faster than 83.88%
// Memory Usage: 9.4 MB, less than 68.18%