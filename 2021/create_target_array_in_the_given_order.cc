class Solution {
 public:
  vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
    vector<int> ans;

    for (int i = 0; i < nums.size(); ++i) {
      if (index[i] < ans.size()) {
        ans.insert(ans.begin() + index[i], nums[i]);
      } else {
        ans.push_back(nums[i]);
      }
    }

    return ans;
  }
};
// Runtime: 4 ms, faster than 68.96%
// Memory Usage: 8.4 MB, less than 100.00%

class Solution {
 public:
  vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
    list<int> lt;

    for (int i = 0; i < nums.size(); ++i) {
      auto it = lt.begin();

      advance(it, index[i]);

      lt.insert(it, nums[i]);
    }

    return vector<int>(lt.begin(), lt.end());
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 8.7 MB, less than 100.00%