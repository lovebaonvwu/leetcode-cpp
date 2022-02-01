class Solution {
 public:
  vector<int> maxScoreIndices(vector<int>& nums) {
    int ones = 0;

    for (auto n : nums) {
      ones += n;
    }

    vector<int> ans;

    for (int i = 0, zeros = 0, curMax = 0; i <= nums.size(); ++i) {
      if (i == 0) {
        curMax = ones;
        ans.push_back(i);
        continue;
      }

      if (nums[i - 1] == 1) {
        --ones;
      } else {
        ++zeros;
      }

      if (ones + zeros > curMax) {
        curMax = ones + zeros;
        ans.clear();
        ans.push_back(i);
      } else if (ones + zeros == curMax) {
        ans.push_back(i);
      }
    }

    return ans;
  }
};
// Runtime: 576 ms, faster than 84.62%
// Memory Usage: 286.6 MB, less than 74.82%
// 2022.2.1 at 茗筑美嘉

class Solution {
 public:
  vector<int> maxScoreIndices(vector<int>& nums) {
    int ones = 0;

    for (auto n : nums) {
      ones += n;
    }

    int curMax = ones;

    vector<int> ans;

    for (int i = 0, zeros = 0; i <= nums.size(); ++i) {
      if (ones + zeros > curMax) {
        curMax = ones + zeros;
        ans.clear();
      }

      if (ones + zeros == curMax) {
        ans.push_back(i);
      }

      if (i < nums.size()) {
        zeros += nums[i] == 0;
        ones -= nums[i];
      }
    }

    return ans;
  }
};
// Runtime: 336 ms, faster than 94.88%
// Memory Usage: 286.7 MB, less than 74.82%
// 2022.2.1 at 茗筑美嘉