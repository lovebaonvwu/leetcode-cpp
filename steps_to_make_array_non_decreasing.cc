class Solution {
 public:
  int totalSteps(vector<int>& nums) {
    int ans = 0;

    while (true) {
      vector<int> tmp;
      tmp.push_back(nums[0]);
      for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] >= nums[i - 1]) {
          tmp.push_back(nums[i]);
        }
      }

      if (tmp.size() == nums.size()) {
        break;
      }

      swap(tmp, nums);
      ++ans;
    }

    return ans;
  }
};
// Time Limit Exceeded
// 2022.6.15 at 奥盛大厦

class Solution {
 public:
  int totalSteps(vector<int>& nums) {
    stack<pair<int, int>> stk;

    int ans = 0;

    for (int i = nums.size() - 1; i >= 0; --i) {
      if (stk.empty() || nums[i] <= stk.top().first) {
        stk.push({nums[i], 0});
      } else {
        int cnt = 0;

        while (!stk.empty() && nums[i] > stk.top().first) {
          cnt = max(cnt + 1, stk.top().second);
          stk.pop();
        }

        stk.push({nums[i], cnt});

        ans = max(ans, cnt);
      }
    }

    return ans;
  }
};
// Runtime: 177 ms, faster than 94.87%
// Memory Usage: 76.5 MB, less than 52.11%
// 2022.6.25 at 茗筑美嘉