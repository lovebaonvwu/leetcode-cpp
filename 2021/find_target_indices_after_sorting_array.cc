class Solution {
 public:
  vector<int> targetIndices(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());

    vector<int> ans;

    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] == target) {
        ans.push_back(i);
      }
    }

    return ans;
  }
};
// Runtime: 8 ms, faster than 55.56%
// Memory Usage: 11.8 MB, less than 22.22%
// 2021.11.28 at 茗筑美嘉

class Solution {
 public:
  vector<int> targetIndices(vector<int>& nums, int target) {
    int cnt = 0, smaller = 0;

    for (auto n : nums) {
      if (n < target) {
        ++smaller;
      } else if (n == target) {
        ++cnt;
      }
    }

    vector<int> ans;

    while (cnt-- > 0) {
      ans.push_back(smaller++);
    }

    return ans;
  }
};
// Runtime: 4 ms
// Memory Usage : 11.7 MB
// 2021.11.28 at 茗筑美嘉

class Solution {
 public:
  vector<int> targetIndices(vector<int>& nums, int target) {
    int cnt = 0, smaller = 0;

    for (auto n : nums) {
      if (n < target) {
        ++smaller;
      } else if (n == target) {
        ++cnt;
      }
    }

    vector<int> ans;

    for (int i = smaller; i < smaller + cnt; ++i) {
      ans.push_back(i);
    }

    return ans;
  }
};
// Runtime: 8 ms, faster than 55.56%
// Memory Usage: 11.7 MB, less than 55.56%
// 2021.11.28 at 茗筑美嘉