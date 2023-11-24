class Solution {
 public:
  vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> ans;

    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      while (nums[i] != nums[nums[i] - 1]) {
        swap(nums[i], nums[nums[i] - 1]);
      }
    }

    for (int i = 0; i < n; ++i) {
      if (nums[i] != i + 1) {
        ans.push_back(i + 1);
      }
    }

    return ans;
  }
};  // 112ms

class Solution {
 public:
  vector<int> findDisappearedNumbers(vector<int>& nums) {
    int n = nums.size();

    vector<int> cnt(n);

    for (auto n : nums) {
      ++cnt[n - 1];
    }

    vector<int> ans;

    for (int i = 0; i < n; ++i) {
      if (cnt[i] == 0) {
        ans.push_back(i + 1);
      }
    }

    return ans;
  }
};
// Runtime: 40 ms, faster than 97.58%
// Memory Usage: 34.9 MB, less than 26.30%
// 2021.11.18 at 奥盛大厦