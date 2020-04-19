class Solution {
 public:
  int minStartValue(vector<int>& nums) {
    int ans = 1;

    for (; ans <= 10001; ++ans) {
      bool find = true;
      for (int j = 0, sum = ans; j < nums.size(); ++j) {
        if ((sum += nums[j]) < 1) {
          find = false;
          break;
        }
      }

      if (find) {
        break;
      }
    }

    return ans;
  }
};
// Runtime: 4 ms, faster than 14.29%
// Memory Usage: 7.5 MB, less than 100.00%

class Solution {
 public:
  int minStartValue(vector<int>& nums) {
    vector<int> presum(nums.size() + 1, 0);

    for (int i = 0; i < nums.size(); ++i) {
      presum[i + 1] = presum[i] + nums[i];
    }

    int mi = *min_element(presum.begin(), presum.end());

    return 1 - mi;
  }
};
// Runtime: 4 ms, faster than 14.29%
// Memory Usage: 7.9 MB, less than 100.00%