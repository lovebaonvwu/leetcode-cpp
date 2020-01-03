class Solution {
 public:
  int minSubArrayLen(int s, vector<int>& nums) {
    deque<int> dq;

    int ans = 0;
    int sum = 0;

    for (int i = 0; i < nums.size(); ++i) {
      dq.push_back(nums[i]);
      sum += nums[i];

      while (!dq.empty() && (sum - dq.front() >= s)) {
        sum -= dq.front();
        dq.pop_front();
      }

      if (sum >= s) {
        ans = !ans ? dq.size() : min(ans, (int)dq.size());
      }
    }

    return ans;
  }
};
// Runtime: 4 ms, faster than 99.85%
// Memory Usage: 10.2 MB, less than 17.65%

class Solution {
 public:
  int minSubArrayLen(int s, vector<int>& nums) {
    int ans = 0;
    int sum = 0;
    int from = 0;

    for (int i = 0; i < nums.size(); ++i) {
      sum += nums[i];

      while (sum >= s) {
        ans = !ans ? i - from + 1 : min(ans, i - from + 1);

        sum -= nums[from++];
      }
    }

    return ans;
  }
};
// Runtime: 8 ms, faster than 96.51%
// Memory Usage: 9.9 MB, less than 94.12%